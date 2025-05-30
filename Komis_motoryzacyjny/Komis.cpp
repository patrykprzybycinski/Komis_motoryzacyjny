#include "Komis.h"
#include "SamochodOsobowy.h"
#include "SamochodDostawczy.h"
#include "Motocykl.h"

using namespace std;

Komis::~Komis() 
{
    for (auto p : m_pojazdy) delete p;
}

const std::vector<Pojazd*>& Komis::getPojazdy() const 
{
    return m_pojazdy;
}