#include "SamochodDostawczy.h"

SamochodDostawczy::SamochodDostawczy(double pojemnosc, int przebieg, int rok, double cena, double ladownosc) : Pojazd(pojemnosc, przebieg, rok, cena), m_ladownosc(ladownosc) 
{
}

double SamochodDostawczy::getLadownosc() const 
{ 
    return m_ladownosc; 
}
void SamochodDostawczy::setLadownosc(double l) 
{ 
    m_ladownosc = l; 
}

void SamochodDostawczy::wypisz() const 
{
    cout << "Sam. dostawczy: " << m_pojemnosc << "L, " << m_przebieg << " km, " << m_rok << " r., " << m_cena << " zl, ladownosc: " << m_ladownosc << " kg" << endl;
}

void SamochodDostawczy::zapisz(ostream& os) const 
{
    os << "dostawczy ";
    Pojazd::zapisz(os);
    os << m_ladownosc << endl;
}