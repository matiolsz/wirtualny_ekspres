#include <iostream>
#include <string>
#include <sstream>


#include "Ekspres.h"
#include "ZbiornikNaWode.h"
#include "Kawa.h"
#include "Ziarna.h"
#include "ZbiornikNaFusy.h"


#pragma once

using namespace std;

Ekspres::Ekspres()
{
    this->nazwa = "";
    this->kolor = "";
    this->zbiornikNaWode=new ZbiornikNaWode(0,0);
    ziarna = new Ziarna();

}

Ekspres::Ekspres(string nazwa, string kolor, double pojemnoscPojNaWode)
{
    this->nazwa = nazwa;
    this->kolor = kolor;
    this->zbiornikNaWode=new ZbiornikNaWode(pojemnoscPojNaWode,0);
    ziarna = new Ziarna();
}

Ekspres::Ekspres(const Ekspres &ekspres)
{
    nazwa = ekspres.nazwa;
    kolor = ekspres.kolor;
    zbiornikNaWode = ekspres.zbiornikNaWode;
    ziarna=NULL;
    ziarna=new Ziarna(*(ekspres.ziarna));
}

void Ekspres::zapisz_dane(ostream &os)
{
    Urzadzenie::zapisz_dane(os);
    zbiornikNaWode->zapisz_dane(os);
    zbiornikNaFusy.zapisz_dane(os);
    kawa.zapisz_dane(os);
    mleko.zapisz_dane(os);
    ziarna->zapisz_dane(os);
}

void Ekspres::wypisz(ostream &os)
{
    os<<"Ekspres: "<<endl;
    zapisz_dane(os);
    cout<<endl;
}

void Ekspres::zapisz_dane_ekspresu(ostream &os)
{
    Urzadzenie::zapisz_dane(os);
}


void Ekspres::wypisz_dane_ekspresu(ostream &os)
{
    os<<"Ekspres: "<<endl;
    zapisz_dane_ekspresu(os);
    cout<<endl;
}

void Ekspres::odczytaj(istream &is)
{
    Urzadzenie::odczyt(is);
    zbiornikNaWode->odczyt(is);
    zbiornikNaFusy.odczyt(is);
    kawa.odczyt(is);
    mleko.odczyt(is);
    ziarna->odczyt(is);
}


bool Ekspres::sprawdzam_czy_wystarczy_wody()
{
    if(zbiornikNaWode->daj_ilosc_wody()>300 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Ekspres::czy_pojemnik_na_skropliny_pelny()
{
    if(zbiornikNaFusy.ilosc_skroplin()>=zbiornikNaFusy.pojemnosc())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Ekspres::czy_da_sie_zrobic_kawe()
{
    if(this->sprawdz_czy_jest_ekspres()==false)
    {
        cout<<"nie ma ekspresu"<<endl<<endl;
        return false;

    }
    else if((this->czy_jest_kawa()==false))
    {
        cout<<"nie ma ziarenek"<<endl<<endl;
        return false;
    }
    else if(this->sprawdzam_czy_wystarczy_mleka()==false)
    {
        cout<<"nie ma mleka"<<endl<<endl;
        return false;
    }
    else if(this->czy_pojemnik_na_skropliny_pelny()==true)
    {
        cout<<"oproznij pojemnik na skropliny"<<endl<<endl;
        return false;
    }
    else if(this->sprawdzam_czy_wystarczy_wody()==false)
    {
        cout<<"brak wody"<<endl<<endl;
        return false;
    }
    else
    {
        Ziarna ile_potrzeba = Ziarna(2);
        (*ziarna) = (*ziarna) - ile_potrzeba;
        zbiornikNaFusy.dodaj_skropliny();
        return true;
    }
}


bool Ekspres::czy_jest_kawa()
{
    Ziarna ile_potrzeba = Ziarna(2);
    if((*ziarna)>=ile_potrzeba)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Ekspres::dodaj_ziarna(int ile_dodac)
{
    if(ziarna==NULL)
    {
        cout<<"Brak obiektu ziarna"<<endl;
        return -1;
    }
    else
        return (*ziarna)+=ile_dodac;
}

Kawa Ekspres::wybierz_kawe()
{
    int typ;
    int moc;
    int ilosc;

    cout<< "Wybierz napoj: " <<endl;
    cout<< "czarna kawa -> wcisnij 1" <<endl;
    cout<< "espresso -> wcisnij 2" <<endl;
    cout<< "cappuccino -> wcisnij 3" <<endl;
    cout<< "latte -> wcisnij 4" <<endl;
    cout<< "kawa z mlekiem -> wcisnij 5" <<endl;

    cout<< " "<<endl;
    cin>>typ;

    switch(typ)
    {
    case 1:
        cout<<"Wybrales czarna kawe"<<endl;
        break;
    case 2:
        cout<<"Wybrales espresso"<<endl;
        break;
    case 3:
        cout<<"Wybrales cappuccino"<<endl;
        break;
    case 4:
        cout<<"Wybrales latte "<<endl;
        break;
    case 5:
        cout<<"Wybrales kawe z mlekiem"<<endl;
        break;
    default:
        break;
    }

    cout<< " "<<endl;
    cout<< " "<<endl;
    cout<< "Okresl moc kawy"<<endl;
    cout<< "jedno ziarenko -> wcisnij 1" <<endl;
    cout<< "dwa ziarenka -> wcisnij 2" <<endl;
    cout<< "trzy ziarenka -> wcisnij 3" <<endl;
    cout<< "cztery ziarenka -> wcisnij 4" <<endl;
    cout<< "piec ziarenek -> wcisnij 5" <<endl;
    cout<< "szesc ziarenek -> wcisnij 6" <<endl;

    cout<< " "<<endl;

    cin>>moc;

    switch(moc)
    {
    case 1:
        cout<<"Wybrales kawe z jednego ziarenka"<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 2:
        cout<<"Wybrales kawe z dwoch ziarenek"<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 3:
        cout<<"Wybrales kawe z trzech ziarenek"<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 4:
        cout<<"Wybrales kawe z czterech ziarenek"<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 5:
        cout<<"Wybrales kawe z pieciu ziarenek"<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 6:
        cout<<"Wybrales kawe z szesciu ziarenek"<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;

    default:
        break;
    }
    cout<< " "<<endl;
    cout<< " "<<endl;
    cout<< "Okresl ilosc kawy"<<endl;
    cout<< "- 50ml -> wcisnij 1" <<endl;
    cout<< "normalna -> wcisnij 2" <<endl;
    cout<< "+50ml -> wcisnij 3" <<endl<<endl<<endl;

    cin>>ilosc;
    switch(ilosc)
    {
    case 1:
        cout<<"Wybrales kawe mala"<<endl<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 2:
        cout<<"Wybrales kawe normalna"<<endl<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 3:
        cout<<"Wybrales kawe wielka"<<endl<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
        if((int)(*ziarna)!= 0)
        default:
        break;
    }

    return Kawa(typ, moc, ilosc);
}

Kawa Ekspres::wybierz_kawe(int typ,int moc, int ilosc)
{

    switch(typ)
    {
    case 1:
        cout<<"Wybrales czarna kawe"<<endl;
        break;
    case 2:
        cout<<"Wybrales espresso"<<endl;
        break;
    case 3:
        cout<<"Wybrales cappuccino"<<endl;
        break;
    case 4:
        cout<<"Wybrales latte "<<endl;
        break;
    case 5:
        cout<<"Wybrales kawe z mlekiem"<<endl;
        break;
    default:
        break;
    }

    switch(moc)
    {
    case 1:
        cout<<"Wybrales kawe z jednego ziarenka"<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 2:
        cout<<"Wybrales kawe z dwoch ziarenek"<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 3:
        cout<<"Wybrales kawe z trzech ziarenek"<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 4:
        cout<<"Wybrales kawe z czterech ziarenek"<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 5:
        cout<<"Wybrales kawe z pieciu ziarenek"<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 6:
        cout<<"Wybrales kawe z szesciu ziarenek"<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;

    default:
        break;
    }

    switch(ilosc)
    {
    case 1:
        cout<<"Wybrales kawe mala"<<endl<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 2:
        cout<<"Wybrales kawe normalna"<<endl<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
    case 3:
        cout<<"Wybrales kawe wielka"<<endl<<endl;
        cout<< " "<<endl;
        cout<< " "<<endl;
        break;
        if((int)(*ziarna)!= 0)
        default:
        break;
    }

    return Kawa(typ, moc, ilosc);
}

bool Ekspres::sprawdz_czy_jest_ekspres()
{
    if(this->nazwa=="")
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Ekspres::uzupelnij_wode()
{
    this->zbiornikNaWode->uzupelnij_wode();
}

void Ekspres::popros_zbiornik_na_fusy_o_oproznienie()
{
    this->zbiornikNaFusy.oproznij_skropliny();
}

bool Ekspres::sprawdzam_czy_wystarczy_mleka()
{
    if(this->mleko.czy_jest==true)
    {
        return true;
    }
    else return false;
}

void Ekspres::stworz_ekspres()
{

    cout<<"Podaj nazwe swojego ekspresu "<<endl;
    cin>>nazwa;
    this->nazwa = nazwa;
    cin.clear();
    cin.sync();

    cout<<"Podaj kolor: "<<endl;
    cin>>kolor;
    this->kolor = kolor;
    cin.clear();
    cin.sync();

    int poj=0;
    while((poj<500))
    {
        cout<<"Podaj pojemnosc (min 500)"<<endl<<endl;
        cin>>poj;
        this->zbiornikNaWode=new ZbiornikNaWode(poj,0);
        cin.clear();
        cin.sync();
    }
    cout<<"Swietnie, ekspres juz gotowy."<<endl<<endl;
}

void Ekspres::pokaz_ekspres()
{
    if(nazwa!="")
    {
        cout<<"Twoj ekspres : "+ this->nazwa + " \nKolor: "+ this->kolor <<endl;
        stringstream ss;
        ss<<(this->zbiornikNaWode->daj_pojemnosc());
        string pojemnosc = ss.str();
        cout<<"Pojemnosc wynosi: " + pojemnosc<<endl<<endl<<endl;
    }
    else
    {
        cout<<endl;
        cout<<" niestety nie stworzyles jeszcze swojego ekspresu "<<endl<<endl<<endl;

    }
}

string Ekspres::daj_nazwe(){
    return this->nazwa;
}
string Ekspres::daj_kolor(){
    return this->kolor;
}
string Ekspres::daj_pojemnosc(){
     stringstream ss;
    ss<<(this->zbiornikNaWode->daj_pojemnosc());
    string pojemnosc = ss.str();
    return pojemnosc;
}
Ekspres::~Ekspres()
{
    //dtor
}
