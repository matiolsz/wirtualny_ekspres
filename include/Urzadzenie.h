//**********************************************
//**********************************************
// Urzadzenie
// AUTOR: Mateusz Olszanka
// WERSJA:  15.06.2020 002
//
// Zdefiniowanie abstrakcyjnej klasy urzadzenie
//**********************************************
//**********************************************
#ifndef URZADZENIE_H
#define URZADZENIE_H

#include <string>

using namespace std;

/// klasa abstrakcyjna
class Urzadzenie
{
protected:
    string nazwa;                                   ///zmienna przechowujaca nazwe
    string kolor;                                   ///zmienna przechowujaca kolor

    public:

        ///kontruktor domyslny
        Urzadzenie();

        /// kontruktor z parametrami
        Urzadzenie(string nazwa, string kolor);

        /// wirtualna metoda polegajaca na odczytaniu danych z pliku wczytanego is do pol wlasnej klasy
        virtual void odczyt(istream &is);

        /// metoda czysto wirtualna, ktor¹ obiekt dziedziczacy musi przyslonic.
        virtual void odczytaj(istream &is)=0;

        /// metoda zapisujaca do pliku os dane swojej klasy
        virtual void zapisz_dane(ostream &os);

        /// czysto wirtualna metoda do zapisu klasy
        virtual void wypisz(ostream &os)=0;

        /// czysto wirtualna metoda do zapisu tylko danych klasy ekspres
        virtual void wypisz_dane_ekspresu(ostream &os)=0;

        /// operator strumieniowy zapisu,
        /// os - strumien wyjsciowy, u - referencja do klasy, z ktorej beda zapisywane pola do pliku
        friend ostream& operator <<(ostream &os, Urzadzenie &u);

        /// destruktor klasy
        virtual ~Urzadzenie();


};

#endif // URZADZENIE_H
