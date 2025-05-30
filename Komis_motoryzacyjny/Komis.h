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
};
