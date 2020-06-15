//**********************************************
//**********************************************
// Ekspres
// AUTOR: Mateusz Olszanka
// WERSJA:  15.06.2020 002
//
// Zdefiniowanie ekspresu do kawy
//**********************************************
//**********************************************
#ifndef EKSPRES_H
#define EKSPRES_H

#include <string>

#include "ZbiornikNaWode.h"
#include "Kawa.h"
#include "Mleko.h"
#include "ZbiornikNaFusy.h"
#include "Ziarna.h"
#include "Urzadzenie.h"

#pragma once


class Ekspres: public Urzadzenie
{

    private:
        ZbiornikNaWode *zbiornikNaWode;                 ///stworzenie podstaw dla obiektu dynamicznego zbiornikNaWode
        ZbiornikNaFusy zbiornikNaFusy;                  ///stworzenie podstaw dla obiektu ziornikNaFusy

    public:

        Kawa kawa;                                      ///stworzenie podstaw dla obiektu Kawa
        Mleko mleko;                                    ///stworzenie podstaw dla obiektu Mleko
        Ziarna *ziarna;                                 ///stworzenie podstaw dla obiektu dynamicznego ziarna


        ///konstruktor domyslny
        Ekspres();


        ///konstruktor z parametrami
        Ekspres(string nazwa, string kolor, double pojemnoscPojNaWode );


        ///konstruktor kopiujacy
        Ekspres(const Ekspres &ekspres);


        /// tworzy ekspres pytajac przed stworzeniem uzytkownika o jego parametry
        void stworz_ekspres();


        /// sprawdza czy mozliwe jest zrobienie kawy
        /// to znaczy czy sa ziarna, jest mleko, woda oraz miejsce na skropliny
        bool czy_da_sie_zrobic_kawe();


        /// sprawdza czy ekspres zostal stworzony
        bool sprawdz_czy_jest_ekspres();


        /// wysyla prosbe do zbiornika na skropliny aby zostal oprozniony(zbiornik na skropliny)
        void popros_zbiornik_na_fusy_o_oproznienie();


        /// sprawdza czy pojemnik na skropliny nie jest zapelniony
        bool czy_pojemnik_na_skropliny_pelny();


        /// sprawdza czy wystarczy wody do zrobienia kawy
        bool sprawdzam_czy_wystarczy_wody();


        /// sprawdza czy wystaczy mleka do zrobienia kawy
        bool sprawdzam_czy_wystarczy_mleka();


        /// sprawdza czy sa ziarenka
        bool czy_jest_kawa();


        /// uzupelnia wode do pelna
        void uzupelnij_wode();


        /// dodaje dana ilosc ziarenek
        int dodaj_ziarna(int ile_dodac);


        /// pozwala wybrac uzytkownikowi kawe i obiekt kawa jest zwrocony przez ta funkcje
        Kawa wybierz_kawe();


        /// jest to przeciazenie funkcji powyzszej stworzone do testow
        Kawa wybierz_kawe(int typ,int moc, int ilosc);


        /// metoda wyswietlajaca w konsoli informacje na temat stworzonego ekspresu
        void pokaz_ekspres();


        /// metoda zwraca nazwe ekspresu
        string daj_nazwe();


        /// metoda zwraca kolor ekspresu
        string daj_kolor();


        /// metoda zwraca pojemnosc ekspresu
        string daj_pojemnosc();

        /// odczytuje dane klasy+ dane klasy po ktorej dziedziczy
        void odczytaj(istream &is);

        /// wypisuje dane na temat ekspresu oraz komponentow ekspresu
        void wypisz(ostream &os);

         ///zapisuje dane wlasnych pol i pol innych klas, ktore wchodza w sklad ekspresu
        ///os - strumien wyjsciowy(plik do ktorego zapisujemy)
        void zapisz_dane(ostream &os);

          ///zapisuje dane wlasnych pol
        ///os - strumien wyjsciowy(plik do ktorego zapisujemy)
        void zapisz_dane_ekspresu(ostream &os);

        /// wypisuje dane na temat ekspresu
        void wypisz_dane_ekspresu(ostream &os);

        /// destruktor klasy
        virtual ~Ekspres();


};

#endif // EKSPRES_H
