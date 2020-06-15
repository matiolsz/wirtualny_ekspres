#include "Kawa.h"
#include <iostream>
#include <string>

using namespace std;

Kawa::Kawa()
{
    this->typ = 1;
    this->moc = 1;
    this->ilosc = 2;
}

Kawa::Kawa(int typ, int moc, int ilosc)
{
    this->typ = typ;
    this->moc = moc;
    this->ilosc = ilosc;

}

Kawa::Kawa(const Kawa &kawa)
{
    typ = kawa.typ;
    moc = kawa.moc;
    ilosc = kawa.ilosc;

}


void Kawa::wyswietl_kawe()
{

    switch(this->typ)
    {
    case 1:
        cout<<"czarna kawe"<<endl;
        break;
    case 2:
        cout<<"espresso"<<endl;
        break;
    case 3:
        cout<<"cappuccino"<<endl;
        break;
    case 4:
        cout<<"latte "<<endl;
        break;
    case 5:
        cout<<"kawa z mlekiem"<<endl;
        break;
    default:
        break;
    }
    switch(this->moc)
    {
    case 1:
        cout<<" o mocy jednego ziarenka"<<endl;
        break;
    case 2:
        cout<<" o mocy dwoch ziarenek"<<endl;
        break;
    case 3:
        cout<<" o mocy trzech ziarenek"<<endl;
        break;
    case 4:
        cout<<" o mocy czterech ziarenek"<<endl;
        break;
    case 5:
        cout<<" o mocy pieciu ziarenek"<<endl;
        break;
    case 6:
        cout<<" o mocy szesciu ziarenek"<<endl;
        break;

    default:
        break;

    }
}

ostream& operator<<(ostream &os, Kawa &kawa)
{
    os << kawa.typ<<endl;
    os << kawa.moc<<endl;
    os << kawa.ilosc<<endl;
    return os;
}

void Kawa::zapisz_dane(ostream &os)
{
    os<< *this;
}

int Kawa::ZamianaNaInt(string s)
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

void Kawa::odczyt(istream &is)
{
    string pobranyString;
    getline(is, pobranyString);
    this->typ = ZamianaNaInt(pobranyString);
    getline(is, pobranyString);
    this->moc = ZamianaNaInt(pobranyString);
    getline(is, pobranyString);
    this->ilosc = ZamianaNaInt(pobranyString);
}



Kawa::~Kawa()
{
    //dtor
}
