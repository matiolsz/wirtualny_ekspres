//**********************************************
//**********************************************
// Mleko
// AUTOR: Mateusz Olszanka
// WERSJA:  15.06.2020 002
//
// Zdefiniowanie mleka
//**********************************************
//**********************************************
#ifndef MLEKO_H
#define MLEKO_H
#include <string>

#pragma once
using namespace std;

class Mleko
{


public:

        bool czy_jest;   /// mleko jest albo przylaczone do ekspresu albo nie


        /// konstruktor domyslny
        Mleko();


        ///konstruktor z parametrem
        Mleko(bool czy_jest);


        /// funkcja pozwalajaca przylaczyc mleko do ekspresu
        void dolacz_mleko();

        /// zamienia true or false na tak or nie
        bool ZamianaNaBool(string s);

        string oddaj_czy_jest(){
            string tak = "tak";
            string nie = "nie";
            if(this->czy_jest == true){
                return tak;
            }else{
                return nie;
            }
        }
        ///operator strumieniowy zapisu
        friend ostream& operator <<(ostream &os, Mleko &m);

        /// odczytuje dane dla pol tej klasy ze strumienia wejsciowego pliku is
        void odczyt(istream &is);

        /// metoda zapisuje dane w pliku os
        void zapisz_dane(ostream &os);

        ///destruktor klasy
        virtual ~Mleko();


};

#endif // MLEKO_H
