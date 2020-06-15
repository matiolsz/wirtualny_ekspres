#include "Ziarna.h"
#include <string>
#include <iostream>

using namespace std;

Ziarna::Ziarna()
{
    this->ilosc = 0;
}

Ziarna::Ziarna(int ilosc)
{
    this->ilosc = ilosc;
}
int Ziarna::ile(){
    return this->ilosc;
}
Ziarna::Ziarna(const Ziarna &ziarna){
    this->ilosc=ziarna.ilosc;
}
Ziarna Ziarna::operator-(const Ziarna &ile){
      this->ilosc = this->ilosc - ile.ilosc;
    return *this;
}
Ziarna& Ziarna::operator=(const Ziarna &rowne){
    this->ilosc=rowne.ilosc;
    return *this;
}
Ziarna& Ziarna::operator-=(const Ziarna &zmniejsz){
    ilosc-=zmniejsz.ilosc;
    return *this;
}
Ziarna& Ziarna::operator+=(const Ziarna &zwieksz){
    ilosc+=zwieksz.ilosc;
    return *this;
}
bool Ziarna::operator>=(const Ziarna &czy){
     if(this->ilosc >= czy.ilosc)
        return true;
    else
        return false;
}

ostream& operator<<(ostream &os, Ziarna &ziarna)
{
    os << ziarna.ilosc<<endl;
    return os;
}

void Ziarna::zapisz_dane(ostream &os)
{
    os<< *this;
}

double Ziarna::ZamianaNaDouble(string s)
{
    double wartoscDouble=0;
    int i=0;
    while(i<s.size())
    {
        wartoscDouble = 10*wartoscDouble+s[i]-48;
        i++;
    }
    return wartoscDouble;
}

void Ziarna::odczyt(istream &is)
{
    string pobranyString;
    getline(is, pobranyString);
    this->ilosc = ZamianaNaDouble(pobranyString);
}


Ziarna::operator int(){
    return (int)this->ilosc;

}

Ziarna::~Ziarna()
{
    //dtor
}
