#include "Urzadzenie.h"
#include <iostream>
using namespace std;

Urzadzenie::Urzadzenie()
{
    nazwa = " urzadzenie ";
    kolor = " czarny ";
}

Urzadzenie::Urzadzenie(string nazwa, string kolor)
{
    this->nazwa = nazwa;
    this->kolor = kolor;
}

void Urzadzenie::zapisz_dane(ostream &os)
{
    os<< *this;
}

ostream& operator<<(ostream &os, Urzadzenie &u)
{
    os << u.nazwa<<endl;
    os << u.kolor<<endl;
    return os;
}

void Urzadzenie::odczyt(istream &is)
{
    string pobierz;
    getline(is, pobierz);
    this->nazwa = pobierz;
    getline(is, pobierz);
    this->kolor = pobierz;
}

Urzadzenie::~Urzadzenie()
{
    //dtor
}
