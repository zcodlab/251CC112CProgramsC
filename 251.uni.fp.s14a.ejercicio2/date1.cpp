//programa que implementa los constructores, destructores y funciones miembro de la clase Date
#include <iostream>
#include "date1.h"
using std::cout;
using std::endl;
//implementacion del constructor de la clase Date
Date::Date(int mn,int dy,int yr){
    //validando el mes
    if(mn>0 && mn<=12)
        month=mn;       //se actualiza el miembro dato de la clase con el valor de mn
    else{
            month=1;
            cout<<"Mes "<<mn<<" invalido. Se establecio el mes a 1"<<endl;
    }
    //seteando año, pendiente implementar la logica de validacion
    year=yr;
    day=checkDay(dy);   //valida el dia
    cout<<"Constructor del objeto Date para fecha ";
    print();
    cout<<endl;
}
void Date::print() const{
    cout<<day<<'/'<<month<<'/'<<year;
}
Date::~Date(){
    cout<<"Destructor del objeto Date para fecha ";
    print();
    cout<<endl;
}
//implementacion de la funcion de utilidad
int Date::checkDay(int testDay){
    static const int daysPerMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(testDay>0 && testDay<=daysPerMonth[month])
        return testDay;
    //Febrero: verificar si el año es bisiesto
    if((month==2 && testDay==29 && year%400==0) ||
       (year%4==0 && year%100!=0))
        return testDay;
    cout<<"Dia "<<testDay<<" invalido. Se establecio el dia a 1"<<endl;
    return 1;
}
