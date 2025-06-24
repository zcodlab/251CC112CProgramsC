//programa que implementa los constructores, destructores y funciones miembro de la clase Empleado
#include <cstring>
#include "date1.cpp"
#include "date1.h"
#include "emply1.h"
using std::cout;
using std::endl;
//implementar la logica del construccion de la clase empleado
Employee::Employee(char *fname,char *lname,
                   int bmonth,int bday,int byear,
                   int hmonth,int hday,int hyear )
: birthDate(bmonth,bday,byear),hireDate(hmonth,hday,hyear){
    //copiando fname en el miembro dato firstName
    int length=strlen(fname);
    length=(length <25 ? length : 24);
    strncpy(firstName,fname,length);
    firstName[length]='\0';     //caracter nulo

    //copiando lname en el miembro dato lastName
    length=strlen(lname);
    length=(length <25 ? length : 24);
    strncpy(lastName,lname,length);
    lastName[length]='\0';     //caracter nulo

    cout<<"constructor del objeto Empleado: "
    <<firstName<<" "<<lastName<<endl;
}
//implementacion de la funcion print
void Employee::print() const{
    cout<<firstName<<" , "<<lastName<<" contratado: ";
    hireDate.print();       //invocando al metodo print de la clase Date
    cout<<" Cumpleaño: ";
    birthDate.print();     //invocando al metodo print de la clase Date
    cout<<endl;
}
//implementacion del destructor de la clase
Employee::~Employee(){
    cout<<"destructor del objeto Empleado: "
    <<firstName<<","<<lastName<<endl;
}
