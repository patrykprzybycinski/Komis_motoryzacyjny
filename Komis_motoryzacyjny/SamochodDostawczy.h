#pragma once
#include "Pojazd.h"

class SamochodDostawczy : public Pojazd 
{
private:
    double m_ladownosc;
public:
    SamochodDostawczy(double pojemnosc, int przebieg, int rok, double cena, double ladownosc);

    double getLadownosc() const;
    void setLadownosc(double);
    void wypisz() const override;
};

