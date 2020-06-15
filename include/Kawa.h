//**********************************************
//**********************************************
// Kawa
// AUTOR: Mateusz Olszanka
// WERSJA:  15.06.2020 002
//
// Zdefiniowanie Kawy
//**********************************************
//**********************************************
#ifndef KAWA_H
#define KAWA_H
#include <string>
#include <iostream>

#pragma once
using namespace std;


class Kawa
{
    private:

        int typ;        ///typ kawy, czarna, z mlekiem itp
        int moc;        /// moc kawy od 1 ziarenka do 6 ziarenek
        int ilosc;     ///ilosc kawy od 1-3 ( 2 to normalna, 1 mala, 3 duza)


    public:



        /// konstruktor domyslny
        Kawa();



        /// kontruktor z parametrami
        Kawa(int typ, int moc, int ilosc);



        /// konstruktor kopiujacy
        Kawa(const Kawa &kawa);



        /// metoda wyswietlajaca kawe
        void wyswietl_kawe();

        ///metoda zmieniajaca string na int
        int ZamianaNaInt(string s);

        ///operator strumieniowy zapisu
        ///os to strumien wejsciowy
        friend ostream& operator <<(ostream &os, Kawa &kawa);

        /// odczytuje dane dla pol tej klasy ze strumienia wejsciowego pliku is
        void odczyt(istream &is);

       /// metoda zapisuje dane w pliku os
        void zapisz_dane(ostream &os);


        /// destruktor klasy
        virtual ~Kawa();

};

#endif // KAWA_H
