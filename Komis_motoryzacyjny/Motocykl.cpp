#include "Motocykl.h"

Motocykl::Motocykl(double pojemnosc, int przebieg, int rok, double cena, bool kufry) : Pojazd(pojemnosc, przebieg, rok, cena), m_kufry(kufry) 
{
}

bool Motocykl::czyMaKufry() const 
{ 
    return m_kufry; 
}
void Motocykl::setKufry(bool k) 
{ 
    m_kufry = k; 
}

bool Motocykl::getKufry() const
{
    return m_kufry;
}

void Motocykl::wypisz() const 
{
    cout << "Motocykl: " << m_pojemnosc << "L, " << m_przebieg << " km, " << m_rok << " r., " << m_cena << " zl, kufry: " << (m_kufry ? "tak" : "nie") << endl;
}



