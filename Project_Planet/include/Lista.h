#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Cialo_Niebieskie.h"
using namespace std;
template<typename T>
class Node
{
public:
    Node(T* g)
    {
            instant_=g;
            //g;
            next_pointer_=nullptr;
            time_create_node_=time(0);
    }
    ~Node()
    {
        //delete instant_;
    }
    T* instante()
    {
        return instant_;
    }
    Node(const Node& nod)
    {
        cout<<"NIEZDEFiniowany konstruktor kopiowania ! ALERT"<<endl;//nieprzewiduje by mialby byc uzyty
    }
    Node&operator=(const Node& nod)
    {
        cout<<"Niezdefiniowany operator przypisania! ALert!"<<endl;//nie przewiduje by mialbyć uzyty
    }
    time_t getTime()
    {
        return time_create_node_;
    }
////    void display()// do usuniecia - funkcja wystepuje by w szybki sposob sprawdzic
////    //czy operator przypisania i konstruktor kopiujacy  listy dziala zgodnie z przewidywaniami
////    //do wyswietlania aplikacja ma wlasnie zdefiniowana metode
////    {
////        instant_->test_operator();
////    }

    Node *next_pointer_;
private:
    T*instant_;
    time_t time_create_node_;
};

template<typename T>
class Lista
{
public:

    Lista()
    {
        first_pointer_=nullptr;
        number_of_nods_=0;
    }

    Lista(Lista& l)
    {
        number_of_nods_=l.getNumber_of_nods();
        first_pointer_=l.getFirst_pointer();

        int i=0;
        Node<T> *temp;
        temp=first_pointer_;
        for(i=1;i<=number_of_nods_;i++)
        {
            temp=l.nextNode(i);
            temp->next_pointer_=l.nextNode(i)->next_pointer_;
        }
    }

    Lista&operator=(Lista&l)
    {
        number_of_nods_=l.getNumber_of_nods();
        first_pointer_=l.getFirst_pointer();
        int i=0;
        Node<T> *temp;
        temp=first_pointer_;
        for(i=1;i<=number_of_nods_;i++)
        {
            //temp=l.nextNode(i);
            temp=l[i];
            //temp->next_pointer_=l.nextNode(i)->next_pointer_;
            temp->next_pointer_=l[i]->next_pointer_;
        }
    }

    ~Lista()
    {
        cleanList();
    }

    void addElement(T* g)
    {
       Node<T>* temp=new Node<T>(g);
       if(number_of_nods_==0)
       {
        first_pointer_=temp;
        number_of_nods_++;
       }
       else
       {
            int i=0;
            Node<T> *test;
            test=first_pointer_;
            i++;
            while(test->next_pointer_)
            {
                test=test->next_pointer_;
                i++;
            }
            test->next_pointer_=temp;
            number_of_nods_++;
       }
    }


    Node<T>* operator[](int numer) //niedopuszczalny ampersand przy napisie operator!!!
    {
        int i=0;
        if(numer==0)
        { return this->first_pointer_;}
        else
        {
         i++;
         Node<T> *x;
         x=first_pointer_;
         while(x->next_pointer_)
         {
            if(numer==i)
            {break;}
            i++;
            x=x->next_pointer_;
         }
        return x;
        }
    }//zwraca konkretny wezel

////    void display() // do usuniecia - funkcja wystepuje by w szybki sposob sprawdzic
////    //czy operator przypisania i konstruktor kopiujacy  listy dziala zgodnie z przewidywaniami
////    //do wyswietlania aplikacja ma wlasnie zdefiniowana metode
////    {
////        int i=0;
////        Node<T> *temp;
////        for(i=1;i<=number_of_nods_;i++)
////        {
////            cout<<"Numer "<<i<<":"<<endl;
////            temp=nextNode(i);
////            temp->display();
////        }
////    }

    void deleteElement(int number)
    {
            Node<T>*temp=first_pointer_;

            if(number==1)
            {
                temp=temp->next_pointer_;
                first_pointer_=temp;
                number_of_nods_--;
            }
            else
            {
                Node<T>* temp2;
                temp2=temp->next_pointer_;
                for(int x=1;x<number-1;x++)
                {
                    temp=temp->next_pointer_;
                    temp2=temp->next_pointer_;
                }
                temp2=temp2->next_pointer_;
                temp->next_pointer_=temp2;
                number_of_nods_--;
            }
    }

    void cleanList()
    {
        for(int x=1;x<number_of_nods_;x++)
        {
            deleteElement(x);
        }
        number_of_nods_=0;
    }
    int getNumber_of_nods()
    {
        return number_of_nods_;
    }


    Node<T>* getFirst_pointer()
    {
        return first_pointer_;
    }

private:
    Node<T> *first_pointer_;
    int number_of_nods_;
};

#endif // LISTA_H
