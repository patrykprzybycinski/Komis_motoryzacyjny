#pragma once
#include "Pojazd.h"

class SamochodOsobowy : public Pojazd
{
private:
    int m_liczbaDrzwi;
public:
    SamochodOsobowy(double pojemnosc, int przebieg, int rok, double cena, int liczbaDrzwi);

    int getLiczbaDrzwi() const;
    void setLiczbaDrzwi(int drzwi);
    void wypisz() const override;
    void zapisz(std::ostream& os) const override;
    static SamochodOsobowy* wczytaj(std::istream& is);
};
