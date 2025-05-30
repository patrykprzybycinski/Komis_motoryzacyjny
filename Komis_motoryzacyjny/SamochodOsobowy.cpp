#include "SamochodOsobowy.h"

SamochodOsobowy::SamochodOsobowy(double pojemnosc, int przebieg, int rok, double cena, int liczbaDrzwi) : Pojazd(pojemnosc, przebieg, rok, cena), m_liczbaDrzwi(liczbaDrzwi) 
{
}

int SamochodOsobowy::getLiczbaDrzwi() const 
{ 
    return m_liczbaDrzwi; 
}
void SamochodOsobowy::setLiczbaDrzwi(int drzwi) 
{ 
    m_liczbaDrzwi = drzwi; 
}

void SamochodOsobowy::wypisz() const 
{
    cout << "Sam. osobowy: " << m_pojemnosc << "L, " << m_przebieg << " km, " << m_rok << " r., " << m_cena << " zl, drzwi: " << m_liczbaDrzwi << endl;
}

void SamochodOsobowy::zapisz(std::ostream& os) const 
{
    os << "osobowy ";
    Pojazd::zapisz(os);
    os << m_liczbaDrzwi << endl;
}
