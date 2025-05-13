#include <iostream>
using namespace std;
int main()
{
    //Array Estatico
    int edades1[3]={10,20,30};
    //Array Dinamico
    int n;
    cout<<"Ingrese el tamaño del array dinamico:";
    cin>>n;
    int* edades=new int[n];
    //Lectura de edades
    cout<<"Ingrese las edades:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Ingrese la edad["<<i<<"]=";
        cin>>edades[i];
    }
    //Visualizacion de edades
    cout<<"Visualizando las edades:"<<endl;
    for(int i=0;i<n;i++)
        cout<<edades[i]<<" ";
    //Liberar la memoria utilizada
    cout<<endl<<"Liberando la memoria utilizada";
    delete[] edades;
    return 0;
}
