#include "Komis.h"
#include "SamochodOsobowy.h"
#include "SamochodDostawczy.h"
#include "Motocykl.h"
#include <fstream>
#include <iostream>

using namespace std;

Komis::~Komis() 
{
    for (auto p : m_pojazdy) delete p;
}

const std::vector<Pojazd*>& Komis::getPojazdy() const 
{
    return m_pojazdy;
}

void Komis::dodajPojazd(Pojazd* pojazd) 
{
    m_pojazdy.push_back(pojazd);
}

void Komis::usunPojazd(int index) 
{
    if (index >= 0 && index < m_pojazdy.size()) 
    {
        delete m_pojazdy[index];
        m_pojazdy.erase(m_pojazdy.begin() + index);
    }
}

void Komis::zapiszDoPliku(const string& nazwaPliku) const 
{
    ofstream plik(nazwaPliku);
    if (!plik) 
    {
        cerr << "Nie mozna otworzyc pliku do zapisu\n";
        return;
    }

    for (const auto& pojazd : m_pojazdy) 
    {
        pojazd->zapisz(plik);
    }
}

void Komis::wczytajZPliku(const string& nazwaPliku) 
{
    ifstream plik(nazwaPliku);
    if (!plik) 
    {
        cerr << "Nie mozna otworzyc pliku do odczytu\n";
        return;
    }

    for (auto p : m_pojazdy)
    {
        delete p;
    }
    m_pojazdy.clear();

    string typ;
    while (plik >> typ) 
    {
        Pojazd* p = nullptr;
        if (typ == "osobowy") 
        {
            p = SamochodOsobowy::wczytaj(plik);
        }
        else if (typ == "dostawczy") 
        {
            p = SamochodDostawczy::wczytaj(plik);
        }
        else if (typ == "motocykl") 
        {
            p = Motocykl::wczytaj(plik);
        }
        else 
        {
            cerr << "Nieznany typ pojazdu w pliku: " << typ << endl;
            break;
        }

        if (p)
        {
            m_pojazdy.push_back(p);
        }
        else 
        {
            cerr << "Blad przy wczytywaniu pojazdu typu: " << typ << endl;
            break;
        }
    }
}