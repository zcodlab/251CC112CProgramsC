#include <iostream>
using namespace std;
void cargarDatos(int arr[],int n){
    cout << "Ingrese la data del array: "<<endl ;
    for(int i=0;i<n;i++)
        cin>>arr[i];
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int searchBinaria(int arr[],int n,int valor){
    int izq=0;
    int der=n-1;
    while(izq<=der){
            int medio=(izq+der)/2;
            if(arr[medio]==valor)
                return medio;

            if(arr[medio]<valor)
                izq=medio+1;
            else
                der=medio -1;
    }
    return -1;
}

int main()
{
    int n,valor;
    cout << "Ingrese el tamaño del array: " ;
    cin>>n;
    //Declarar y asignar el tamaño
    int arr[n];
    //invocar funcion de carga de data
    cargarDatos(arr,n);
    cout<<"Data del arreglo: ";
    printArray(arr,n);
    //Falta incorporar un metodo de ordenamiento (pendiente)
    //probar con esta data: 5,12,17,23,38,44,77,84,90
    cout<<"Ingrese el valor a buscar: ";
    cin>>valor;
    int resultado=searchBinaria(arr,n,valor);
    if(resultado!=-1)
       cout<<"El valor "<<valor<<" se encontro en la posicion "<<resultado<<endl;
    else
       cout<<"El valor "<<valor<<" No se encontro en el arreglo "<<endl;
    return 0;
}
