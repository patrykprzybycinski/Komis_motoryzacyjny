#pragma once
#include "Pojazd.h"

using namespace std;

class Motocykl : public Pojazd
{
private:
    bool m_kufry;
public:
    Motocykl(double pojemnosc, int przebieg, int rok, double cena, bool kufry);

    bool czyMaKufry() const;
    void setKufry(bool);
    bool getKufry() const;
    void wypisz() const override;
    void zapisz(ostream& os) const override;
    static Motocykl* wczytaj(istream& is);
};

