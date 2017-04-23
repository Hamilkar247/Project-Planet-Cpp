#ifndef APLIKACJA_H
#define APLIKACJA_H
#include "Cialo_Niebieskie.h"
#include <iostream>
#include <fstream>
#include "Lista.h"
class Aplikacja
{
    public:
        void wpisz_liczbe(int &a);
        Aplikacja();
        virtual ~Aplikacja();
        void menu();
        void dodaj();
            void rozszerz_liste(Lista<Cialo_Niebieskie> &l);
                void dodaj_gwiazde(Lista<Cialo_Niebieskie> &l);
                    void add_star(string nazwa,int masa,string typ_widmowy
                    ,int jasnosc,int wiek,string pierwiastek,Lista<Cialo_Niebieskie> &l);
                void dodaj_planete(Lista<Cialo_Niebieskie> &l);
                    void add_planet(string nazwa,int masa,int wiek
                    ,string dominujacy_pierwiastek,Lista<Cialo_Niebieskie> &l);
                void dodaj_planete_z_atmosfera(Lista<Cialo_Niebieskie> &l);
                    void add_planet_with_atmosphere(string nazwa,int masa,int wiek
                    ,string dominujacy_pierwiastek,string dominujacy_gatunek
                    ,int ESA,Lista<Cialo_Niebieskie> &l);
        void usun();
            void delete_part_of_list(Lista<Cialo_Niebieskie>&l);
        void wyczysc_liste();
        void wyswietl();
            void display(Lista<Cialo_Niebieskie> &l,const string &);
        void load();
            void read_objects_on_the_file(string nazwa,Lista<Cialo_Niebieskie>&l);
                void load_star(string linia,ifstream &myfile,Lista<Cialo_Niebieskie> &l);
                void load_planet(string linia,ifstream &myfile,Lista<Cialo_Niebieskie> &l);
                void load_planet_with_atmosphere(string linia,ifstream &myfile,Lista<Cialo_Niebieskie> &l);
        void save();
            void save_to_file(Lista<Cialo_Niebieskie> &l);
        void przekopiuj();
            void copy_date_list_to_other_list(Lista<Cialo_Niebieskie> &l1,Lista<Cialo_Niebieskie> &l2,const string name);
        void czyszczenie_pliku(string nazwa);
        void czyszczenie_listy(Lista<Cialo_Niebieskie>&l);
    protected:
    private:
        Lista<Cialo_Niebieskie> L_;
        Lista<Cialo_Niebieskie> tempL_;
        time_t start_;
        //int licznik_;
};

#endif // APLIKACJA_H
