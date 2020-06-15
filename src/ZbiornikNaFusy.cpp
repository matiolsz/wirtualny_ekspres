#include "ZbiornikNaFusy.h"
#include <string>
#include <iostream>

using namespace std;

ZbiornikNaFusy::ZbiornikNaFusy()
{
    this->ilosc_fusow = 0;
    this->pojemnosc_pojemnika = 500;
}

ZbiornikNaFusy::ZbiornikNaFusy(int pojemnosc_pojemnika, int ilosc_fusow){
    this->pojemnosc_pojemnika = pojemnosc_pojemnika;
    this->ilosc_fusow = ilosc_fusow;
}

void ZbiornikNaFusy::dodaj_skropliny(){
    this->ilosc_fusow=(this->ilosc_fusow)+50;
}

int ZbiornikNaFusy::ilosc_skroplin(){
    return  (this->ilosc_fusow);
}

void ZbiornikNaFusy::oproznij_skropliny(){
    this->ilosc_fusow = 0;
}

int ZbiornikNaFusy::pojemnosc(){
    return this->pojemnosc_pojemnika;
}

ostream& operator<<(ostream &os, ZbiornikNaFusy &zbiornikNaFusy)
{
    os << zbiornikNaFusy.ilosc_fusow<<endl;
    os << zbiornikNaFusy.pojemnosc_pojemnika<<endl;
    return os;
}

void ZbiornikNaFusy::zapisz_dane(ostream &os)
{
    os<< *this;
}

int ZbiornikNaFusy::ZamianaNaInt(string s)
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

void ZbiornikNaFusy::odczyt(istream &is)
{
    string pobranyString;
    getline(is, pobranyString);
    this->ilosc_fusow = ZamianaNaInt(pobranyString);
    getline(is, pobranyString);
    this->pojemnosc_pojemnika = ZamianaNaInt(pobranyString);
}



ZbiornikNaFusy::~ZbiornikNaFusy()
{
    //dtor
}
