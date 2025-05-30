#include "Pojazd.h"
#include <iostream>

using namespace std;

Pojazd::Pojazd(double pojemnosc, int przebieg, int rok, double cena) : m_pojemnosc(pojemnosc), m_przebieg(przebieg), m_rok(rok), m_cena(cena) 
{
}

Pojazd::~Pojazd() 
{
}

double Pojazd::getPojemnoscSilnika() const 
{ 
	return m_pojemnosc; 
}

int Pojazd::getPrzebieg() const 
{ 
	return m_przebieg; 
}

int Pojazd::getRokProdukcji() const 
{ 
	return m_rok; 
}

double Pojazd::getCena() const 
{ 
	return m_cena; 
}

void Pojazd::setPojemnoscSilnika(double p) 
{ 
	m_pojemnosc = p; 
}

void Pojazd::setPrzebieg(int p) 
{
	m_przebieg = p; 
}

void Pojazd::setRokProdukcji(int r) 
{ 
	m_rok = r; 
}

void Pojazd::setCena(double c) 
{ 
	m_cena = c; 
}

