#pragma once
#include "Pojazd.h"

using namespace std;

class SamochodDostawczy : public Pojazd 
{
private:
    double m_ladownosc;
public:
    SamochodDostawczy(double pojemnosc, int przebieg, int rok, double cena, double ladownosc);

    double getLadownosc() const;
    void setLadownosc(double);
    void wypisz() const override;
    void zapisz(ostream& os) const override;
    static SamochodDostawczy* wczytaj(istream& is);
};