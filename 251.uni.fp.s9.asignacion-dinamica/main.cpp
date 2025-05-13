#include <iostream>
using namespace std;

int main()
{
    //Asignacion de memoria dinamica a tipo simple
    int* edad=new int(25);
    cout<<"Edad: "<< *edad<<endl;
    delete edad;
    edad=nullptr;//es una buena practica para evitar punteros colgantes

    //Asignacion de memoria dinamica a array
    int n=3;
    int* arr=new int[n];
    //Asignacion de valores de manera demostrativa
    for(int i=0;i<n;i++)
        arr[i]=i*10;
    //visualizar el array dinamico
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    //Liberar la memoria
    delete[] arr;
    arr=nullptr;

    return 0;
}
