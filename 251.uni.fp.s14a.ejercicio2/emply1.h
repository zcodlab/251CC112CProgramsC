#ifndef EMPLY1_H
#define EMPLY1_H
//incluimos la clase Date
#include "date1.h"
//definicion de la clase Empleado
class Employee{
private:
    char firstName[25];//nombre
    char lastName[25];//apellido
    const Date birthDate; //fecha de cumpleaños, miembro dato de tipo composicion
    const Date hireDate; //fecha de contrato, miembro dato de tipo composicion
public:
    Employee(char*,char*,int,int,int,int,int,int);
    void print() const;
    ~Employee();    //observar el orden de destruccion de los objetos
};
#endif // EMPLY1_H
