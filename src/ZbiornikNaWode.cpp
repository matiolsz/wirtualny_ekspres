#include "ZbiornikNaWode.h"
#include <string>
#include <iostream>
ZbiornikNaWode::ZbiornikNaWode()
{
    this->pojemnosc = 0;
    this->ilosc_wody = 0;
}

ZbiornikNaWode::ZbiornikNaWode(int pojemnosc, int ilosc_wody){
    this->pojemnosc = pojemnosc;
    this->ilosc_wody = ilosc_wody;
}

int ZbiornikNaWode::daj_pojemnosc(){
    return this->pojemnosc;
}
bool ZbiornikNaWode::czy_jest(){
    if(this->ilosc_wody>300){
        return true;
    }else{
        return false;
    }
}

void ZbiornikNaWode::uzupelnij_wode(){
   this->ilosc_wody = this->pojemnosc;
}
int ZbiornikNaWode::daj_ilosc_wody(){
    return this->ilosc_wody;
}

ostream& operator<<(ostream &os, ZbiornikNaWode &zbiornikNaWode)
{
    os << zbiornikNaWode.pojemnosc<<endl;
    os << zbiornikNaWode.ilosc_wody<<endl;
    return os;
}

void ZbiornikNaWode::zapisz_dane(ostream &os){
    os<< *this;
}

int ZbiornikNaWode::ZamianaNaInt(string s)
{
    int wartoscInt=0;
    int i=0;
    while(i<s.size())
    {
        wartoscInt = 10*wartoscInt+s[i]-48;
        i++;
    }
    return wartoscInt;
}

void ZbiornikNaWode::odczyt(istream &is)
{
    string pobranyString;
    getline(is, pobranyString);
    this->pojemnosc = ZamianaNaInt(pobranyString);
    getline(is, pobranyString);
    this->ilosc_wody = ZamianaNaInt(pobranyString);
}




ZbiornikNaWode::~ZbiornikNaWode()
{
    //dtor
}
