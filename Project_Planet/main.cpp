///*Projekt PROE
///*Tworca - Mateusz Kusy



#include <iostream>
#include <ctime>
#include "include/Cialo_Niebieskie.h"
#include "include/Aplikacja.h"
#include "include/Lista.h"
#include <fstream>

#include <unistd.h>
#include <time.h>

using namespace std;


void program()
{
    time_t start_= time(0);
    Aplikacja *apl=new Aplikacja();
    delete apl;
    time_t end_=time(0);
    double time=difftime(end_,start_);
    cout<<"Czas trwania programu :"<<time<<" sec"<<endl;

}

int main()
{
    program();
    return 0;
}
