#pragma once
#include <vector>
#include "Pojazd.h"

using namespace std;

class Komis 
{
private:
    vector<Pojazd*> m_pojazdy;
public:
    ~Komis();

    const vector<Pojazd*>& getPojazdy() const;
    void dodajPojazd(Pojazd* pojazd);
    void usunPojazd(int index);
    void zapiszDoPliku(const std::string& nazwaPliku) const;
    void wczytajZPliku(const std::string& nazwaPliku);
};
