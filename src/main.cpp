#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Ekspres.h"
#include "Kawa.h"
#include "Mleko.h"
#include "ZbiornikNaWode.h"
#include "ZbiornikNaFusy.h"
#include "Interfejs.h"

using namespace std;
#pragma once

int main()
{
    vector <Kawa> twoje_kawunie;
    vector <Urzadzenie*> urzadzenia;
    Ekspres *ekspres = new Ekspres();

    int input;
    int liczba_urzadzen= 0 ;
    string input_str;
    string dane;

    ifstream ifs;
    ofstream ofs;

    while(true)
    {
        Interfejs::Menu_glowne();
        while(!(cin>>input) || (input>14 || input<0))
        {
            cout << "Wpisz liczbe z zakresu od 0 do 14!"<<endl;
            cin.clear();
            cin.sync();
        }
        switch(input)
        {
        case 1:
        {
            ekspres->stworz_ekspres();
            urzadzenia.push_back(ekspres);
            cout<<endl;
            liczba_urzadzen++;
            break;
        }
        case 2:
        {
            if(ekspres->czy_da_sie_zrobic_kawe()==true)
            {
                Kawa kawa = ekspres-> wybierz_kawe();
                twoje_kawunie.push_back(kawa);
            }
            break;

        }
        case 3:
        {
            if(ekspres->sprawdz_czy_jest_ekspres()==true)
            {
                ekspres->dodaj_ziarna(10);
                cout<<"Pojemnik na ziarenka juz jest pelny"<<endl<<endl;
                break;
            }
            else
            {
                cout<<"Musisz najpierw stworzyc ekspres"<<endl<<endl;
                break;
            }
        }
        case 4:
        {
            if(ekspres->sprawdz_czy_jest_ekspres()==true)
            {
                ekspres->mleko.dolacz_mleko();
                cout<<"Mleko juz jest podlaczone"<<endl<<endl;
                break;
            }
            else
            {
                cout<<"Musisz najpierw stworzyc ekspres"<<endl<<endl;
                break;
            }
        }
        case 5:
        {
            if(ekspres->sprawdz_czy_jest_ekspres()==true)
            {
                ekspres->uzupelnij_wode();
                cout<<"Woda uzupelniona"<<endl<<endl;
                break;
            }
            else
            {
                cout<<"Musisz najpierw stworzyc ekspres"<<endl<<endl;
                break;
            }
        }
        case 6:
        {
            if(ekspres->sprawdz_czy_jest_ekspres()==true)
            {
                ekspres->popros_zbiornik_na_fusy_o_oproznienie();
                cout<<"Ziornik na fusy oprozniony"<<endl<<endl;
                break;
            }
            else
            {
                cout<<"Musisz najpierw stworzyc ekspres"<<endl<<endl;
                break;
            }
        }
        case 7:
        {
            if(ekspres->sprawdz_czy_jest_ekspres()==true)
            {
                ekspres->pokaz_ekspres();
                break;
            }
            else
            {
                cout<<"Musisz najpierw stworzyc ekspres"<<endl<<endl;
                break;
            }

        }
        case 8:
        {
            if(ekspres->sprawdz_czy_jest_ekspres()==true)
            {
                if(twoje_kawunie.empty())
                    cout<<"Lista kaw jest pusta!"<<endl;
                else
                {
                    cout<<" ------- Poczatek listy ------- "<<endl;
                    for(int i = 0 ; i< twoje_kawunie.size() ; i++)
                    {
                        twoje_kawunie[i].wyswietl_kawe();
                    }
                    cout<<"Masz: "<<twoje_kawunie.size()<<" obiektow w liscie"<<endl;
                    cout<<"------- Koniec listy  --------- "<<endl<<endl<<endl;
                }
                break;
            }
            else
            {
                cout<<"Musisz najpierw stworzyc ekspres"<<endl<<endl;
                break;
            }
        }
        case 9:  ///odczytaj dane  z dysku
        {
            cout<< "Podaj nazwe pliku z ktorego chcesz wczytac dane"<<endl;
            cin>>input_str;
            ifs.open(input_str.c_str());
            if( ifs.good())
                cout<<"Plik zostal otworzony "<<endl;
            else
            {
                cout<<"Plik "<<input_str<<" nie zostal otworzony"<<endl;
                break;
            }
            while(!ifs.eof())
            {
                getline(ifs, dane);
                if (dane == "Ekspres: ")
                {
                    ekspres = new Ekspres();
                    ekspres->odczytaj(ifs);
                    urzadzenia.push_back(ekspres);
                    liczba_urzadzen++;
                }
            }
            ifs.close();
            break;
        }
        case 10:   /// zapisz dane na dysku
        {
            cout<<"Wpisz nazwe nowego pliku w ktorym zapiszesz dane."<<endl;
            cin>>input_str;
            ofs.open(input_str.c_str());
            if( ofs.good())
            {
                cout<<"Plik utworzono pomyslnie, nazwa pliku:  "<<input_str<<endl;
            }
            else
            {
                cout<<"Plik "<<input_str<<" nie zostal utworzony"<<endl;
                break;
            }
            for(int i = 0 ; i<urzadzenia.size() ; i++)
                (urzadzenia[i])->wypisz(ofs);

            ofs.close();
            break;
        }
        case 11:   /// kasowanie urzadzenia
        {
            if(ekspres->sprawdz_czy_jest_ekspres()==true)
            {
                cout<<"ktory ekspres chcesz usunac?"<<endl;
                if(urzadzenia.empty())
                    cout<<"Brak urzadzen!"<<endl;
                else
                {
                    cout<<" ------- Urzadzenia ------- "<<endl;
                    for(int i = 0 ; i< urzadzenia.size() ; i++)
                        urzadzenia[i]->wypisz_dane_ekspresu(cout);
                    cout<<"Masz: "<<urzadzenia.size()<<" ekspresow "<<endl;
                    cout<<"------- Urzadzenia --------- "<<endl;
                }
                while(!(cin>>input) || (input>liczba_urzadzen || input<1))
                {
                    cout << "nie ma ekspresu o tym numerze, sprobuj jeszcze raz"<<endl;
                    cin.clear();
                    cin.sync();
                }
                delete *(urzadzenia.begin() + (input-1));
                urzadzenia.erase(urzadzenia.begin() + (input-1));
                cout<<"Ekspres skasowany!"<<endl;
                liczba_urzadzen--;
                break;
            }
            else
            {
                cout<<"Nie ma zadnego ekspresu do usuniecia."<<endl;

            }
            break;
        }

        case 12:   /// wyswietl spis ekspresow
        {

            if(urzadzenia.empty())
            {
                cout<<"Brak urzadzen!"<<endl;
                break;
            }
            else
            {
                cout<<" ------- Urzadzenia ------- "<<endl;
                for(int i = 0 ; i< urzadzenia.size() ; i++)
                    urzadzenia[i]->wypisz(cout);
                cout<<"Masz: "<<urzadzenia.size()<<" ekspresow "<<endl;
                cout<<"------- Urzadzenia --------- "<<endl;
                break;
            }



        }
        case 13:  /// wyczysc wszystkie dane
        {
            for (auto& urzadzenie : urzadzenia)
                delete urzadzenie;
            cout<<"baza danych jest wyczyszczona"<<endl;
            break;

        }
        case 14:   /// zakoncz program
        {
            return 0;

        }

        default:
        {
            break;
        }
        }
    }
}
