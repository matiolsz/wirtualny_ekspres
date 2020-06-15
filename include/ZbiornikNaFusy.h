//**********************************************
//**********************************************
// Zbiornik Na fusy
// AUTOR: Mateusz Olszanka
// WERSJA:  15.06.2020 002
//
// Zdefiniowanie zbiornika na fusy
//**********************************************
//**********************************************
#ifndef ZBIORNIKNAFUSY_H
#define ZBIORNIKNAFUSY_H
#include <string>
#include <iostream>
using namespace std;
class ZbiornikNaFusy
{
    protected:

        int pojemnosc_pojemnika;            ///zmiennna przechwujaca pojemnosc zbiornika na skropliny
        int ilosc_fusow;                    ///zmienna przechowujaca ilosc skroplin( fusow), ktore aktualnie sie znajduja w pojemniku

    public:


        /// konstruktor domyslny
        ZbiornikNaFusy();


        /// konstruktor z parametrami
        ZbiornikNaFusy(int pojemnosc_pojemnika,int ilosc_fusow);


        /// metoda ktora dodaje stala ilosc skroplin, wtedy, gdy kawa zostaje wykonywana
        void dodaj_skropliny();


        /// metoda zwraca ilosc skroplin
        int ilosc_skroplin();


        /// metoda zwraca pojemnosc zbiornika
        int pojemnosc();


        /// metoda oprozniajaca zbiornik na skropliny
        void oproznij_skropliny();

        ///zamieniam string na int
        int ZamianaNaInt(string s);

        ///operator strumieniowy zapisu
        friend ostream& operator <<(ostream &os, ZbiornikNaFusy &zbiornikNaFusy);

        /// odczytuje dane dla pol tej klasy ze strumienia wejsciowego pliku is
        void odczyt(istream &is);

        /// metoda zapisuje dane w pliku os
        void zapisz_dane(ostream &os);

        /// destruktor klasy
        virtual ~ZbiornikNaFusy();


};

#endif // ZBIORNIKNAFUSY_H
