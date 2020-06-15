//**********************************************
//**********************************************
// Ziarna
// AUTOR: Mateusz Olszanka
// WERSJA:  15.06.2020 002
//
// Zdefiniowanie ziaren
//**********************************************
//**********************************************
#ifndef ZIARNA_H
#define ZIARNA_H
#include <iostream>
#include<string>
using namespace std;

class Ziarna
{
    private:
        double ilosc;


    public:
        ///kontruktor domyslny
        Ziarna();

        ///kontruktor z parametrem
        Ziarna(int ilosc);

        /// metoda zwracajaca ilosc ziaren
        int ile();

        /// konstruktor kopiujacy
        ///umozliwia wsypanie Ziaren w ilosci tej samej jaka ma ziarna w parametrze
        ///ziarna jest obiektem z ktorego zostana skopiowane wszystkie pola
        Ziarna(const Ziarna &ziarna);

        ///operator odejmowania
        ///odejmuje ilosc ziaren, "ile" to referencja na obiekt klasy Ziarno, ktory ma byc odjety od obecnego obiektu
        ///zwraca pozostala ilosc ziaren w postaci obiektu Ziarna
        Ziarna operator-(const Ziarna &ile);

        ///operator przypisania
        ///przypisuje ilosc ziaren z parametru jako biezaca ilosc ziaren
        ///zwraca biezaca ilosc mleka w postaci referencji na obiekt Ziarna
        Ziarna& operator=(const Ziarna &rowne);

        ///operator odejmowania z przypisaniem
        ///zmniejsza ilosc ziaren biezacych i przypisuje obecna ilsc do orginalnego obiektu
        ///zwraca biezaca ilosc mleka w postaci referencji na obiekt Ziarna
        Ziarna& operator-=(const Ziarna &zmniejsz);

        ///operator dodawania z przypisaniem
        ///Zwiêksza iloœæ ziaren biezacych oraz przypisuje obecn¹ wartoœæ dla biezacego obiektu
        /// zwieksz jest referencj¹ na obiekt klasy Ziarna, który ma zwiêkszyæ bie¿¹cy licznik
        /// zwraca bie¿¹c¹ iloœæ ziaren w postaci referencji na obiekt Ziarna
        Ziarna& operator+=(const Ziarna &zwieksz);

        ///operator wieksze-rowne
        ///Sprawdza czy bie¿¹ca ilosc ziaren jest wiêksza lub równa badanej iloœci ziaren w obiekcie
        /// czy jest referencj¹ na obiekt klasy Ziarna, który ma byæ porównany
        /// zwraca wartoœæ boolowsk¹ prawda lub fa³sz
        bool operator>=(const Ziarna &czy);

        /// operator rzutowania
        ///rzutuje ilosc ziaren z double na int
        operator int();

        ///metoda zmieniajaca string na double
        double ZamianaNaDouble(string s);

        ///operator strumieniowy zapisu
        ///os to strumien wyjsciowy, ziarna to referencja do klasy z ktorej zapisywane beda dane
        friend ostream& operator <<(ostream &os, Ziarna &ziarna);

        ///odczytuje dane dla wlasnych pol
        ///is - strumien wejsciowy(plik wczytywany)
        void odczyt(istream &is);

        ///zapisuje dane wlasnych pol
        ///os - strumien wyjsciowy(plik do ktorego zapisujemy)
        void zapisz_dane(ostream &os);

        ///destruktor
        virtual ~Ziarna();


};

#endif // ZIARNA_H
