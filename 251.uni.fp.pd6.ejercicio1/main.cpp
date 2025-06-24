/*
*Programa que resuelve el ejercicio 9.21 del Cap9 Libro Deitel
*/
#include <iostream>
#include "IntegerSet.h"
int main()
{
    //Crear conjuntos
    IntegerSet set1;//utiliza el 1 constructor, sin parametros
    IntegerSet set2({10,20,30,40});//utiliza el 2 constructor
    IntegerSet set3({30,40,50,60});//utiliza el 2 constructor
    //visualizando los conjuntos
    std::cout<<"Set1: "<<set1.toString()<<std::endl;
    std::cout<<"Set2: "<<set2.toString()<<std::endl;
    std::cout<<"Set3: "<<set3.toString()<<std::endl;
    //insertando elementos en el conjunto1
    set1.insertElement(5);
    set1.insertElement(10);
    set1.insertElement(30);
    //visualizando el conjunto1 despues de insertar datos
    std::cout<<"Set1 despues de inserciones: "<<set1.toString()<<std::endl;
    //eliminado elementos en el conjunto1
    set1.deleteElement(10);
    std::cout<<"Set1 despues de eliminaciones: "<<set1.toString()<<std::endl;
    //Union de conjuntos
    IntegerSet unionSet=IntegerSet::unionOfSets(set2,set3);
    std::cout<<"Union de Set2 y Set3: "<<unionSet.toString()<<std::endl;
    //Interseccion de conjuntos
    IntegerSet intersecSet=IntegerSet::intersectionOfSets(set2,set3);
    std::cout<<"Interseccion de Set2 y Set3: "<<intersecSet.toString()<<std::endl;
    //Igualdad de conjuntos
    std::cout<<"Set2 es igual a Set3? : "<<(set2.isEqualTo(set3)? "Si":"No")    <<std::endl;
    //conjunto vacio: utilizando el primer constructor
    IntegerSet emptySet;
    std::cout<<"Conjunto vacio: "<<emptySet.toString()<<std::endl;

    return 0;
}
