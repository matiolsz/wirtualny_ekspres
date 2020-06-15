//**********************************************
//**********************************************
// Zbiornik Na Wode
// AUTOR: Mateusz Olszanka
// WERSJA:  15.06.2020 002
//
// Zdefiniowanie zbiornika na wode
//**********************************************
//**********************************************
#ifndef ZBIORNIKNAWODE_H
#define ZBIORNIKNAWODE_H
#include<string>
using namespace std;

class ZbiornikNaWode
{
    protected:

        int pojemnosc;                     ///zmiennna przechwujaca pojemnosc zbiornika na wode
        int ilosc_wody;                    ///zmienna przechowujaca ilosc wody, ktora aktualnie sie znajduja w pojemniku


    public:


        ///konstruktor domyslny
        ZbiornikNaWode();


        /// konstruktor z parametrami
        ZbiornikNaWode(int pojemnosc,int ilosc_wody);


        /// metoda zwraca pojemnosc zbiornika na wode
        int daj_pojemnosc();


        /// metoda sprawdza czy zbiornik jest podlaczony
        bool czy_jest();


        /// metoda ktora dolewa wode az do zapelnienia zbiornika
        void uzupelnij_wode();


        /// metoda zwracajaca ilosc wody , ktora znajduje sie w zbiorniku
        int daj_ilosc_wody();

        ///metoda zamieniajaca string na int
        int ZamianaNaInt(string s);

        ///operator strumieniowy zapisu
        friend ostream& operator <<(ostream &os, ZbiornikNaWode &zbiornikNaWode);

        /// odczytuje dane dla pol tej klasy ze strumienia wejsciowego pliku is
        void odczyt(istream &is);

        /// metoda zapisuje dane w pliku os
        void zapisz_dane(ostream &os);


        /// destruktor
        virtual ~ZbiornikNaWode();


};

#endif // ZBIORNIKNAWODE_H
