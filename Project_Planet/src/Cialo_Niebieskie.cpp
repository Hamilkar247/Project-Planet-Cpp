#include <iostream>
#include <fstream>
#include "../include/Cialo_Niebieskie.h"
using namespace std;
///              Cialo Niebieskie
Cialo_Niebieskie::Cialo_Niebieskie()
{}

Cialo_Niebieskie::Cialo_Niebieskie(string nazwa)
:nazwa_(nazwa),masa_(0)
{}

Cialo_Niebieskie::Cialo_Niebieskie(string nazwa,int masa)
:nazwa_(nazwa),masa_(masa)
{}

Cialo_Niebieskie::~Cialo_Niebieskie()
{;}

Cialo_Niebieskie::Cialo_Niebieskie(const Cialo_Niebieskie& niebieskie)
:nazwa_(niebieskie.nazwa_),masa_(niebieskie.masa_)
{}

Cialo_Niebieskie& Cialo_Niebieskie::operator=(const Cialo_Niebieskie&niebieskie)
{
    nazwa_=niebieskie.nazwa_;
    masa_=niebieskie.masa_;
}

void Cialo_Niebieskie::save(string nazwa)
{
    ofstream myfile;
    myfile.open(nazwa,std::ios_base::app);

    if(myfile.good()==true)
    {
        myfile<<zwroc_nazwe()<<endl;
        myfile<<zwroc_mase()<<endl;
        myfile.close();
    }

    else
    {
        cout<<"Nieudalo sie otworzyc pliku chlip"<<endl;
    }
}

///Gwiazda

Gwiazda::Gwiazda(string nazwa):Cialo_Niebieskie(nazwa),dominujacy_pierwiastek_("nieznany"),
wiek_(0),typ_widmowy_("brak"),emitowana_jasnosc_(0)
{;}

Gwiazda::Gwiazda(string nazwa,int masa,string typ_widmowy,int emitowana_jasnosc,
int wiek,string dominujacy_pierwiastek)
:Cialo_Niebieskie(nazwa,masa),typ_widmowy_(typ_widmowy),emitowana_jasnosc_(emitowana_jasnosc),wiek_(wiek),dominujacy_pierwiastek_(dominujacy_pierwiastek)
{;}

Gwiazda::Gwiazda(const Gwiazda& slonce)
:Cialo_Niebieskie(slonce.nazwa_,slonce.masa_),typ_widmowy_(slonce.typ_widmowy_),emitowana_jasnosc_(slonce.emitowana_jasnosc_)
,wiek_(slonce.wiek_),dominujacy_pierwiastek_(slonce.dominujacy_pierwiastek_)
{;}

Gwiazda &Gwiazda::operator=(const Gwiazda&slonce)
{
    nazwa_=slonce.nazwa_;
    masa_=slonce.masa_;
    typ_widmowy_=slonce.typ_widmowy_;
    emitowana_jasnosc_=slonce.emitowana_jasnosc_;
    wiek_=slonce.wiek_;
    dominujacy_pierwiastek_=slonce.dominujacy_pierwiastek_;
}

Gwiazda::~Gwiazda()
{;}

void Gwiazda::save(string nazwa)
{
    Cialo_Niebieskie* temp=new Cialo_Niebieskie(nazwa_,masa_);
    temp->save(nazwa);
    ofstream myfile2;
    myfile2.open(nazwa,std::ios_base::app);
    if(myfile2.good()==true)
    {
        myfile2<<zwroc_typ_widmowy()<<endl;
        myfile2<<zwroc_emitowana_jasnosc()<<endl;
        myfile2<<zwroc_wiek()<<endl;
        myfile2<<zwroc_dominujacy_pierwiastek()<<endl;
        myfile2.close();
    }
    else
    {
        cout<<"Nie udalo sie otworzyc pliku :'("<<endl;
    }
}

void Gwiazda::test_operator()const
{
            cout<<"Gwiazda               :"<<nazwa_<<endl;
            cout<<"Masa Gwiazdy          :"<<masa_<<" kg"<<endl;
            cout<<"Typ widmowy           :"<<typ_widmowy_<<endl;
            cout<<"Emitowana Jasnosc     :"<<emitowana_jasnosc_<<" W"<<endl;
            cout<<"Wiek Gwiazdy          :"<<wiek_<<" tys lat"<<endl;
            cout<<"Dominujacy pierwiastek:"<<dominujacy_pierwiastek_<<endl;
            cout<<endl;
}

///Planeta
Planeta::Planeta(string nazwa):Cialo_Niebieskie(nazwa),dominujacy_pierwiastek_("nieznany"),wiek_(0)
{;}

Planeta::Planeta(string nazwa,int masa,int wiek,string dominujacy_pierwiastek)
:Cialo_Niebieskie(nazwa,masa),wiek_(wiek),dominujacy_pierwiastek_(dominujacy_pierwiastek)
{;}

Planeta::~Planeta()
{;}

Planeta::Planeta(const Planeta& Jowisz)
:Cialo_Niebieskie(Jowisz.nazwa_,Jowisz.masa_),wiek_(Jowisz.wiek_),dominujacy_pierwiastek_(Jowisz.dominujacy_pierwiastek_)
{;}

Planeta &Planeta::operator=(const Planeta& Jowisz)
{
    nazwa_=Jowisz.nazwa_;
    masa_=Jowisz.masa_;
    wiek_=Jowisz.wiek_;
    dominujacy_pierwiastek_=Jowisz.dominujacy_pierwiastek_;
}

void Planeta::save(string nazwa)
{
    Cialo_Niebieskie* temp=new Cialo_Niebieskie(nazwa_,masa_);
    temp->save(nazwa);
    ofstream myfile;
    if(myfile.good()==true)
    {
        myfile.open(nazwa,std::ios_base::app);
        myfile<<wiek_<<endl;
        myfile<<dominujacy_pierwiastek_<<endl;
        myfile.close();
    }
    else
    {
        cout<<"Nie udalo sie otworzyc pliku chlip"<<endl;
    }
}

void Planeta::test_operator()const
{
            cout<<"Planeta               :"<<nazwa_<<endl;
            cout<<"Masa Planety          :"<<masa_<<" kg"<<endl;
            cout<<"Wiek Planety          :"<<wiek_<<" tys lat"<<endl;
            cout<<"Dominujacy pierwiastek:"<<dominujacy_pierwiastek_<<endl;
            cout<<endl;
}

///Planeta z atmosfera

Planeta_z_atmosfera::Planeta_z_atmosfera(string nazwa):Planeta(nazwa),dominujacy_gatunek_("brak"),wspolczynnik_ESA_(0)
{;}

Planeta_z_atmosfera::Planeta_z_atmosfera(string nazwa,int masa,int wiek,string dominujacy_pierwiastek,string dominujacy_gatunek,int ESA)
:Planeta(nazwa,masa,wiek,dominujacy_pierwiastek),dominujacy_gatunek_(dominujacy_gatunek),wspolczynnik_ESA_(ESA)
{;}

Planeta_z_atmosfera::~Planeta_z_atmosfera()
{;}

Planeta_z_atmosfera::Planeta_z_atmosfera(const Planeta_z_atmosfera& Ziemia)
:Planeta(Ziemia.nazwa_,Ziemia.masa_,Ziemia.wiek_,Ziemia.dominujacy_pierwiastek_)
,dominujacy_gatunek_(Ziemia.dominujacy_gatunek_),wspolczynnik_ESA_(Ziemia.wspolczynnik_ESA_)
{;}

Planeta_z_atmosfera &Planeta_z_atmosfera::operator=(const Planeta_z_atmosfera& Ziemia)
{
  nazwa_=Ziemia.nazwa_;
  masa_=Ziemia.masa_;
  wiek_=Ziemia.wiek_;
  dominujacy_pierwiastek_=Ziemia.dominujacy_pierwiastek_;
  dominujacy_gatunek_=Ziemia.dominujacy_gatunek_;
  wspolczynnik_ESA_=Ziemia.wspolczynnik_ESA_;
}

void Planeta_z_atmosfera::test_operator()const
{
            cout<<"Planeta               :"<<nazwa_<<endl;
            cout<<"Masa Planety          :"<<masa_<<" kg"<<endl;
            cout<<"Wiek Planety          :"<<wiek_<<" tys lat"<<endl;
            cout<<"Dominujacy pierwiastek:"<<dominujacy_pierwiastek_<<endl;
            cout<<"Dominujacy gatunek    :"<<dominujacy_gatunek_<<endl;
            cout<<"Wspolczynnnik ESA     :"<<wspolczynnik_ESA_<<" %"<<endl;
            cout<<endl;
}

void Planeta_z_atmosfera::save(string nazwa)
{
    Planeta* temp=new Planeta(nazwa_,masa_,wiek_,dominujacy_pierwiastek_);
    temp->save(nazwa);
    ofstream myfile;
    if(myfile.good()==true)
    {
        myfile.open(nazwa,std::ios_base::app);
        myfile<<dominujacy_gatunek_<<endl;
        myfile<<wspolczynnik_ESA_<<endl;
        myfile.close();
    }
    else
    {
        cout<<"Nie udalo sie chlip"<<endl;
    }
}



