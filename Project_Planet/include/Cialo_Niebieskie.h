#ifndef CIALO_NIEBIESKIE_H
#define CIALO_NIEBIESKIE_H
#include <iostream>
using namespace std;
class Cialo_Niebieskie
{
    public:
        //virtual void metodab()=0;
        Cialo_Niebieskie();
        Cialo_Niebieskie(string nazwa);
        Cialo_Niebieskie(string nazwa,int masa);
        Cialo_Niebieskie(const Cialo_Niebieskie& niebieskie);
        Cialo_Niebieskie&operator=(const Cialo_Niebieskie&niebieskie);
        virtual ~Cialo_Niebieskie();
        virtual void save(string nazwa);
        virtual void test_operator()const { cout<<"Base"<<endl; };
        virtual string typ(){string typ1="base";return typ1;}
        string zwroc_nazwe(){return nazwa_;}
        int zwroc_mase(){return masa_;}
    protected:
        string nazwa_;
        int masa_;
    public:
    private:
};

class Gwiazda: public Cialo_Niebieskie
{
    public:
        //void metodab(){;}
        Gwiazda(string nazwa);
        Gwiazda(string nazwa,int masa,string typ_widmowy
        ,int emitowana_jasnosc,int wiek,string dominujacy_pierwiastek);
        Gwiazda(const Gwiazda& slonce);
        Gwiazda&operator=(const Gwiazda&slonce);
        ~Gwiazda();
        void save(string nazwa);
        virtual void test_operator()const;
        string zwroc_nazwe(){return nazwa_;}
        int zwroc_mase(){return masa_;}
        string zwroc_typ_widmowy(){return typ_widmowy_;}
        int zwroc_emitowana_jasnosc(){return emitowana_jasnosc_;}
        int zwroc_wiek(){return wiek_;}
        string zwroc_dominujacy_pierwiastek(){return dominujacy_pierwiastek_;}
        string typ(){string typ1="Gwiazda";return typ1;}
    private:
        string typ_widmowy_;
        int emitowana_jasnosc_;
        int wiek_;
        string dominujacy_pierwiastek_;
};
class Planeta: public Cialo_Niebieskie
{
    public:
        //virtual void metodab(){;}
        Planeta(string nazwa);
        Planeta(string nazwa,int masa,int wiek,string dominujacy_pierwiastek);
        ~Planeta();
        Planeta(const Planeta& Jowisz);
        Planeta&operator=(const Planeta&Jowisz);
        virtual void save(string nazwa);
        virtual void test_operator()const;
        virtual string typ(){string typ1="Planeta";return typ1;}
    protected:
        int wiek_;
        string dominujacy_pierwiastek_;
    private:

};
class Planeta_z_atmosfera: public Planeta
{
    public:
        //void metodab(){;}
        Planeta_z_atmosfera(string nazwa);
        Planeta_z_atmosfera(string nazwa,int masa,int wiek
        ,string dominujacy_pierwiastek,string dominujacy_gatunek,int ESA);
        Planeta_z_atmosfera(const Planeta_z_atmosfera& Ziemia);
        Planeta_z_atmosfera&operator=(const Planeta_z_atmosfera&Ziemia);
        ~Planeta_z_atmosfera();
        void save(string nazwa);
        void test_operator()const;
        string typ(){string typ1="Planeta_z_atmosfera";return typ1;}
    private:
        string dominujacy_gatunek_;
        int wspolczynnik_ESA_;
};
inline ostream& operator<<(ostream& stream,const Cialo_Niebieskie& instancja) // inline zdzialal cuda ! :P
{
    instancja.test_operator();
    return stream;
}
#endif // CIALO_NIEBIESKIE_H
