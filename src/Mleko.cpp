#include "Mleko.h"
#include <string>
#include <iostream>

using namespace std;

Mleko::Mleko()
{
    czy_jest = false;
}

Mleko::Mleko(bool czy_jest){
    this->czy_jest = czy_jest;
}

void Mleko::dolacz_mleko(){
    this->czy_jest = true;
}



ostream& operator<<(ostream &os, Mleko &m)
{
    os<< m.oddaj_czy_jest()<<endl;
    return os;
}

void Mleko::zapisz_dane(ostream &os)
{
    os<< *this;
}

bool Mleko::ZamianaNaBool(string s){
    bool czy ;
    if (s.compare(0,2,"tak")){
        return true;
        }else{
        return false;
        }

}

void Mleko::odczyt(istream &is)
{
    string pobranyString;
    getline(is, pobranyString);
    this->czy_jest = ZamianaNaBool(pobranyString);
}

Mleko::~Mleko()
{
    //dtor
}
