#pragma once
#include <iostream>

using namespace std;

class Pojazd 
{
protected:
    double m_pojemnosc;
    int m_przebieg;
    int m_rok;
    double m_cena;
public:
    Pojazd(double pojemnosc, int przebieg, int rok, double cena);
    virtual ~Pojazd();

    double getPojemnoscSilnika() const;
    int getPrzebieg() const;
    int getRokProdukcji() const;
    double getCena() const;

    void setPojemnoscSilnika(double);
    void setPrzebieg(int);
    void setRokProdukcji(int);
    void setCena(double);

    virtual void wypisz() const = 0;

    virtual void zapisz(ostream& os) const;
};


