#include "../include/Aplikacja.h"
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
using namespace std;

void Aplikacja::wpisz_liczbe(int &a)
{
    cin>>a;
    if(cin.good()==false)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        string w="Powinienes wpisac liczbe - nie zrobiles tego";
        throw w;
    }
}

Aplikacja::Aplikacja():start_(time(0))
{
        menu();
}

Aplikacja::~Aplikacja()
{
        L_.~Lista();
        tempL_.~Lista();
}

void Aplikacja::menu()
{
    int a=1;
    while(a!=8)
    {
        cout<<"Menu"<<endl;
        cout<<"1.Dodaj"<<endl;
        cout<<"2.Usun"<<endl;
        cout<<"3.Wyczysc liste"<<endl;
        cout<<"4.Wyswietl"<<endl;
        cout<<"5.Load"<<endl;
        if(L_.getNumber_of_nods()>0 || tempL_.getNumber_of_nods()>0){cout<<"6.Save"<<endl;}
        if(L_.getNumber_of_nods()>0 || tempL_.getNumber_of_nods()>0){cout<<"7.Skopiuj liste glowna do listy tymczasowej (lub odwrotnie)"<<endl;}
        cout<<"8.Wyjdz"<<endl;
        try  //sprawdzam czy uzyszzkodnik wpisze liczbe
        {
            wpisz_liczbe(a);
        }
        catch(string w)
        {
            cout<<"Blad! "<<w<<endl;;
        }
        switch(a)
        {
            case 1:
                dodaj();
                break;
            case 2:
                usun();
                break;
            case 3:
            {
                wyczysc_liste();
                break;
            }
            case 4:
            {
                wyswietl();
                break;
            }
            case 5:
            {
                load();
                break;
            }
            case 6:
            {

                if(L_.getNumber_of_nods()>0 || tempL_.getNumber_of_nods()>0){save();}
                break;
            }
            case 7:
            {
                if(L_.getNumber_of_nods()>0 || tempL_.getNumber_of_nods()>0){przekopiuj();}
                break;
            }
        }
    }
}

void Aplikacja::dodaj()
{
    cout<<"Do jakiej listy chcesz dodac obiekt? 1.lista glowna 2.lista poboczna"<<endl;
    int x;
    cin>>x;
    switch(x)
    {
        case 1:
        {
            rozszerz_liste(L_);
            break;
        }
        case 2:
        {
            rozszerz_liste(tempL_);
            break;
        }

    }
}

    void Aplikacja::rozszerz_liste(Lista<Cialo_Niebieskie> &l)
    {
        int wybor=0;
        cout<<"Jaki obiekt chcesz stworzyc?"<<endl;
        cout<<"1.Gwiazda"<<endl;
        cout<<"2.Planeta"<<endl;
        cout<<"3.Planeta z atmosferą"<<endl;
        try
        {
            wpisz_liczbe(wybor);
        }
            catch(string w)
            {
                cout<<"Blad! "<<w<<endl;
            }
        switch(wybor)
        {
            case 1:
            {
                dodaj_gwiazde(l);
                break;
            }
            case 2:
            {
                dodaj_planete(l);
                break;
            }
            case 3:
            {
                dodaj_planete_z_atmosfera(l);
                break;
            }
        }
    }

        void Aplikacja::dodaj_gwiazde(Lista<Cialo_Niebieskie> &l)
        {
                    string nazwa;
                    string pierwiastek;
                    string typ_widmowy;
                    int masa;
                    int wiek;
                    int jasnosc;
                    cout<<"Podaj nazwe obiektu"<<endl;
                    getline(cin,nazwa);//nwm co sie dzieje - poswiecenie getlina go odblokowuje
                    getline(cin,nazwa);
                    cout<<"Podaj glowny pierwiastek na obiekcie"<<endl;
                    getline(cin,pierwiastek);
                    cout<<"Podaj typ widmowy na obiekcie"<<endl;
                    getline(cin,typ_widmowy);
                    cout<<"Podaj mase obiektu"<<endl;
                    cin>>masa;
                    cout<<"Podaj wiek obiektu"<<endl;
                    cin>>wiek;
                    cout<<"Podaj jasnosc obiektu"<<endl;
                    cin>>jasnosc;
                    //parametry_gwiazdy(nazwa);//,&pierwiastek,&typ_widmowy,&masa,&wiek,&jasnosc);
                    //cout<<nazwa<<endl;
                    add_star(nazwa,masa,typ_widmowy,jasnosc,wiek,pierwiastek,l);
        }

            void Aplikacja::add_star(string nazwa,int masa,string typ_widmowy,int jasnosc,int wiek
            ,string pierwiastek,Lista<Cialo_Niebieskie> &l)
            {
                        Cialo_Niebieskie*wskaz=new Gwiazda(nazwa,masa,typ_widmowy,jasnosc,wiek,pierwiastek);
                        l.addElement(wskaz);
            }

        void Aplikacja::dodaj_planete(Lista<Cialo_Niebieskie>& l)
        {
                    string nazwa,dominujacy_pierwiastek;
                    int masa,wiek;
                    cout<<"Podaj nazwe obiektu:"<<endl;
                    getline(cin,nazwa);//nwm co sie dzieje - poswiecenie getlina go odblokowuje
                    getline(cin,nazwa);
                    cout<<"Podaj dominujacy pierwiastek:"<<endl;
                    getline(cin,dominujacy_pierwiastek);
                    cout<<"Podaj masa planety:"<<endl;
                    cin>>masa;
                    cout<<"Podaj wiek planety"<<endl;
                    cin>>wiek;
                    add_planet(nazwa,masa,wiek,dominujacy_pierwiastek,l);
        }

            void Aplikacja::add_planet(string nazwa,int masa,int wiek,string dominujacy_pierwiastek,Lista<Cialo_Niebieskie>&l)
            {
                        Cialo_Niebieskie*wskaz=new Planeta(nazwa,masa,wiek,dominujacy_pierwiastek);
                        l.addElement(wskaz);
            }

        void Aplikacja::dodaj_planete_z_atmosfera(Lista<Cialo_Niebieskie>& l)
        {
                    string nazwa,dominujacy_pierwiastek,dominujacy_gatunek;
                    int masa,wiek,ESA;
                    cout<<"Podaj nazwe obiektu:"<<endl;
                    getline(cin,nazwa);//nwm co sie dzieje - poswiecenie getlina go odblokowuje
                    getline(cin,nazwa);
                    cout<<"Podaj dominujacy gatunek:"<<endl;
                    getline(cin,dominujacy_gatunek);
                    cout<<"Podaj dominujacy pierwiastek:"<<endl;
                    getline(cin,dominujacy_pierwiastek);
                    cout<<"Podaj mase planety z atmosfera:"<<endl;
                    cin>>masa;
                    cout<<"Podaj wiek planety:"<<endl;
                    cin>>wiek;
                    cout<<"Podaj wspolczynnik ESA"<<endl;
                    cin>>ESA;
                    add_planet_with_atmosphere(nazwa,masa,wiek,dominujacy_pierwiastek
                    ,dominujacy_gatunek,ESA,l);
        }

            void Aplikacja::add_planet_with_atmosphere(string nazwa,int masa,int wiek
            ,string dominujacy_pierwiastek,string dominujacy_gatunek,int ESA,Lista<Cialo_Niebieskie>& l)
            {
                        Cialo_Niebieskie*wskaz=new Planeta_z_atmosfera(nazwa,masa,wiek
                        ,dominujacy_pierwiastek,dominujacy_gatunek,ESA);
                        l.addElement(wskaz);
            }

void Aplikacja::usun()
{
    if(tempL_.getNumber_of_nods()==0 && L_.getNumber_of_nods()!=0)
    {
        cout<<"Podaj numer elementu z listy glownej, ktory chcesz usunac"<<endl;
        delete_part_of_list(L_);
    }
    else if(tempL_.getNumber_of_nods()!=0 && L_.getNumber_of_nods()==0)
    {
        cout<<"Podaj numer elementu z listy pobocznej ktory chcesz usunac"<<endl;
        delete_part_of_list(tempL_);
    }
    else if(tempL_.getNumber_of_nods()!=0 && L_.getNumber_of_nods()!=0)
    {
        cout<<"Z ktorej listy chcesz usunac element? 1.Glownej 2.tymczasowej"<<endl;
        int x;
        cin>>x;
        switch(x)
        {
            case 1:
            {cout<<"Podaj numer elementu z listy glownej, ktory chcesz usunac"<<endl;
             delete_part_of_list(L_);break;}
            case 2:
            {cout<<"Podaj numer elementu z listy pobocznej, ktory chcesz usunac"<<endl;
             delete_part_of_list(tempL_);break;}
            default:
            {   cout<<"Nie wybrales zadnej listy"<<endl;}
        }
    }
    else
    {
        cout<<"Na zadnej z list nie ma zadnych elementow"<<endl;
    }
}

    void Aplikacja::delete_part_of_list(Lista<Cialo_Niebieskie>& l)
    {
        int a;
        try
        {
            wpisz_liczbe(a);
            if(a>l.getNumber_of_nods() || a<0)
            {
                string w="Nie ma takiego wezla!";
                throw w;
            }
            l.deleteElement(a);
        }
        catch(string w)
        {
            cout<<"Blad! "<<w<<endl;
        }
    }


void Aplikacja::wyczysc_liste()
{
            if(tempL_.getNumber_of_nods()!=0)
            {
            cout<<"Czy ma zostac wyczyszczona glowna lista programu,lista tymczasowa,czy moze obie(wyb 1/2/3)"<<endl;
            int z;
            cin>>z;
                if(z==1){czyszczenie_listy(L_);}
                else if(z==2){czyszczenie_listy(tempL_);}
                else if(z==3){czyszczenie_listy(L_);czyszczenie_listy(tempL_);}
                else{cout<<"Nie wybrales zadnej opcji"<<endl;}
            }
            else if(tempL_.getNumber_of_nods()==0 && L_.getNumber_of_nods()!=0)
            {czyszczenie_listy(L_);}
            else
            {cout<<"Listy sa puste"<<endl;}
}


void Aplikacja::wyswietl()
{
    string text1="Lista glowna programu";
    string text2="Lista poboczna programu";
        if(L_.getNumber_of_nods()!=0 && tempL_.getNumber_of_nods()!=0)
        {
            int g;
            cout<<"Chcesz wyswietlic liste glowna programu, liste podgladowa(tymczasowa?),czy moze obie? [ wyb 1/2/3 ]"<<endl;
            cin>>g;
            switch(g)
            {
                case 1:
                {
                    display(L_,text1);
                    break;
                }
                case 2:
                {
                    display(tempL_,text2);
                    break;
                }
                case 3:
                {
                    display(L_,text1);
                    display(tempL_,text2);
                    break;
                }
                default:
                {
                    cout<<"Nie wybrales zadnej opcji"<<endl;
                    break;
                }
            }
        }
        else if(L_.getNumber_of_nods()!=0 && tempL_.getNumber_of_nods()==0)
        {
            display(L_,text1);
        }
        else if(L_.getNumber_of_nods()==0 && tempL_.getNumber_of_nods()!=0)
        {
            display(tempL_,text2);
        }
        else
        {cout<<endl;cout<<"Lista jest pusta!"<<endl;}
}
    void Aplikacja::display(Lista<Cialo_Niebieskie> &l,const string& text)
    {
            cout<<endl;
            cout<<text<<endl;
            int i=0;
            Node<Cialo_Niebieskie> *temp;
            for(i=1;i<=l.getNumber_of_nods();i++)
            {
                cout<<"Numer "<<i<<":"<<endl;
                //temp=l.nextNode(i);
                temp=l[i];
                cout<<*temp->instante();
                cout<<"Czas żywotu wezla:"<<temp->getTime()-start_<<"s"<<endl;
                cout<<endl;
            }
    }

void Aplikacja::load()
{
    string texty1="laduje do glownej";
    string texty2="laduje do pobocznej";
    string textx1=",standardowa lista ";
    string textx2=",nie standardowa lista ";
    string textz1=",zastapilem poprzednie dane";
    string textz2=",dopisalem do poprzednich danych";

    int x,y,z;
    cout<<"Chcesz odczytane dane z pliku dodac do glownej listy obiektow programu czy zaladowane obiekty umiescic w liscie tymczasowej(wybierz 1/2)"<<endl;
    cin>>y;
    cout<<"Chcesz zaladowac standardowa liste obiektow? Czy moze chcesz zaladowac z pliku wczesniej przez cb zapisanego(bedziesz musial podac nazwe tego pliku)? (wybierz 1/2)"<<endl;
    cin>>x;
    if(L_.getNumber_of_nods()==0 && tempL_.getNumber_of_nods()==0){z=1;}
    else
    {cout<<"Mam zastapic obiekty jakie znajduja sie na liscie w danej chwili, czy wczytane obiekty po prostu dopisac na koniec listy? (wyb 1/2)"<<endl;
    cin>>z;}
    if(y==1 && x==1 && z==1)
    {

        czyszczenie_listy(L_);
        string date="default.txt";
        read_objects_on_the_file(date,L_);
        cout<<texty1<<textx1<<textz1<<endl;
        cout<<endl;
    }
    else if(y==1 && x==2 && z==1)
    {
        czyszczenie_listy(L_);
        cout<<"Wpisz nazwe pliku wraz z rozszerzeniem z ktorego odczytamy obiekty"<<endl;
        string nazwa;
        cin>>nazwa;
        read_objects_on_the_file(nazwa,L_);
        cout<<texty1<<textx2<<textz1<<endl;
        cout<<endl;
    }
    else if(y==2 && x==1 && z==2)
    {
        string date="default.txt";
        read_objects_on_the_file(date,tempL_);
        cout<<texty2<<textx1<<textz1<<endl;
        cout<<endl;
    }
    else if(y==2 && x==2 && z==2)
    {
        cout<<"Wpisz nazwe pliku wraz z rozszerzeniem z którego odczytamy obiekty"<<endl;
        string nazwa;
        cin>>nazwa;
        read_objects_on_the_file(nazwa,tempL_);
        cout<<texty2<<textx2<<textz2<<endl;
        cout<<endl;
    }
    else if(y==2 && x==1 && z==1)
    {
        czyszczenie_listy(tempL_);
        string date="default.txt";
        read_objects_on_the_file(date,tempL_);
        cout<<texty2<<textx1<<textz1<<endl;
    }
    else if(y==2 && x==2 && z==1)
    {
        czyszczenie_listy(tempL_);
        cout<<"Wpisz nazwe pliku wraz z rozszerzeniem z którego odczytamy obiekty"<<endl;
        string nazwa;
        cin>>nazwa;
        read_objects_on_the_file(nazwa,tempL_);
        cout<<texty2<<textx2<<textz1<<endl;
    }

}

void Aplikacja::read_objects_on_the_file(string nazwa,Lista<Cialo_Niebieskie>&l)
{
        ifstream myfile;
        string linia;
        myfile.open(nazwa, std::ios::in);
        cout<<endl;
        if(myfile.good()==false) {cout<<"Nie mozna otworzyc pliku!"<<endl;}
        int nr_linii=1;
        while(getline(myfile,linia))
        {
            if(linia=="Gwiazda")
            {
                load_star(linia,myfile,l);
            }
            else if(linia=="Planeta")
            {
                load_planet(linia,myfile,l);
            }
            else if(linia=="Planeta_z_atmosfera")
            {
                load_planet_with_atmosphere(linia,myfile,l);
            }
        }
        myfile.close();
}

    void Aplikacja::load_star(string linia,ifstream &myfile,Lista<Cialo_Niebieskie>&l)
    {
            int x=1;
            string nazwa,typ_widmowy,dominujacy_pierwiastek;
            int masa,emitowana_jasnosc,wiek;
            while(getline(myfile,linia))
            {
                if(x==1){nazwa=linia;}
                else if(x==2){masa=stoi(linia);}
                else if(x==3){typ_widmowy=linia;}
                else if(x==4){emitowana_jasnosc=stoi(linia);}
                else if(x==5){wiek=stoi(linia);}
                else if(x==6){dominujacy_pierwiastek=linia;}
                x++;
                if(x==7){break;}
            }
            add_star(nazwa,masa,typ_widmowy,emitowana_jasnosc,wiek,dominujacy_pierwiastek,l);
    }

    void Aplikacja::load_planet(string linia,ifstream &myfile,Lista<Cialo_Niebieskie>&l)
    {
            int x=1;
            string nazwa,dominujacy_pierwiastek;
            int masa,wiek;
            while(getline(myfile,linia))
            {
                if(x==1){nazwa=linia;}
                else if(x==2){masa=stoi(linia);}
                else if(x==3){wiek=stoi(linia);}
                else if(x==4){dominujacy_pierwiastek=linia;}
                x++;
                if(x==5){break;}
            }
            add_planet(nazwa,masa,wiek,dominujacy_pierwiastek,l);
    }

    void Aplikacja::load_planet_with_atmosphere(string linia,ifstream &myfile,Lista<Cialo_Niebieskie> &l)
    {
            int x=1;
            string nazwa,dominujacy_pierwiastek,dominujacy_gatunek;
            int masa,wiek,ESA;
            while(getline(myfile,linia))
            {
                if(x==1){nazwa=linia;}
                else if(x==2){masa=stoi(linia);}
                else if(x==3){wiek=stoi(linia);}
                else if(x==4){dominujacy_pierwiastek=linia;}
                else if(x==5){dominujacy_gatunek=linia;}
                else if(x==6){ESA=stoi(linia);}
                x++;
                if(x==7){break;}
            }
            add_planet_with_atmosphere(nazwa,masa,wiek,dominujacy_pierwiastek
            ,dominujacy_gatunek,ESA,l);
    }

void Aplikacja::save()
{
    string text1="Zapisalem liste glowna";
    string text2="Zapisalem liste poboczna";
    int x;
    if(L_.getNumber_of_nods()>0 && tempL_.getNumber_of_nods()>0)
    {
        cout<<"Ktora liste chcesz zapisac? 1.glowna 2.poboczna"<<endl;
        cin>>x;
        if(x==1)
        {
            cout<<text1<<endl;
            save_to_file(L_);
        }
        if(x==2)
        {
            cout<<text2<<endl;
            save_to_file(tempL_);
        }
    }
    else if(L_.getNumber_of_nods()==0 && tempL_.getNumber_of_nods()>0)
    {
        cout<<text2<<endl;
        save_to_file(tempL_);
    }
    else if(L_.getNumber_of_nods()>0 && tempL_.getNumber_of_nods()==0)
    {
        cout<<text1<<endl;
    }
    else
    {
        cout<<"Zadna z list nie ma nic do zapisania"<<endl;
    }
}

    void Aplikacja::save_to_file(Lista<Cialo_Niebieskie> &l)
    {
        cout<<"Jak sie nazywac bedzie save? Wpisz nazwe"<<endl;
        string nazwa;
        cin>>nazwa;
            czyszczenie_pliku(nazwa);
            int i=0;
            Node<Cialo_Niebieskie> *temp;
            for(i=1;i<=l.getNumber_of_nods();i++)
            {
                ofstream myfile;
                myfile.open(nazwa,std::ios::app);
                if(myfile.good()==false) {cout<<"Nie udalo sie otworzyc pliku"<<endl;}
                //temp=L_.nextNode(i);
                temp=l[i];
                myfile<<temp->instante()->typ()<<endl;
                myfile.close();
                temp->instante()->save(nazwa);
            }
    }

void Aplikacja::przekopiuj()
{
    string nazwa1="Przekopiowano dane listy glownej do listy tymczasowej";;
    string nazwa2="Przekopiowano dane listy tymczasowa do listy glownej";;
    if(tempL_.getNumber_of_nods()==0 && L_.getNumber_of_nods()>0)
    {copy_date_list_to_other_list(L_,tempL_,nazwa1);}
    else if(tempL_.getNumber_of_nods()>0 && L_.getNumber_of_nods()==0)
    {copy_date_list_to_other_list(tempL_,L_,nazwa2);}
    else
    {
        cout<<"Chcesz zastapic dotychczasowe dane na liscie tymczasowa, przez dane listy glownej?(opcja 1)"<<endl;
        cout<<"Chcesz zastapic dotychczasowe dane na liscie glownej, przez dane listy tymczasowej(opcja 2)"<<endl;
        int x;
        cin>>x;
        if(x==1)
        {
            copy_date_list_to_other_list(L_,tempL_,nazwa1);
        }
        else if(x==2)
        {
            copy_date_list_to_other_list(tempL_,L_,nazwa2);
        }
    }
}
    void Aplikacja::copy_date_list_to_other_list(Lista<Cialo_Niebieskie> &l1,Lista<Cialo_Niebieskie> &l2,const string name )
    {
        cout<<name<<endl;
        l2=l1;
    }

void Aplikacja::czyszczenie_pliku(string nazwa)
{
    ofstream myfile;
    myfile.open(nazwa, std::ios::trunc);
    myfile.close();
}

void Aplikacja::czyszczenie_listy(Lista<Cialo_Niebieskie>&l)
{
    l.cleanList();
}





