#include <iostream>
using namespace std;

void cargarDatos(int arr[],int n){
    cout << "Ingrese " <<n<<" numeros para el array:"<< endl;
    for(int i=0;i<n;i++)
        cin>>arr[i] ;
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" " ;
    cout<<endl;
}
int searchLineal(int arr[],int n,int valor){
    for(int i=0;i<n;i++){
            if(arr[i]==valor)
                return i;
    }
    return -1;
}

int main()
{
    int n,valor;
    cout << "Ingrese el tamaño del array:" << endl;
    cin>>n;
    //Declarar el array con el tamaño proporcionado por el usuario
    int arr[n];
    //invocamos la funcion cargarDatos
    cargarDatos(arr,n);
    cout<<"Visualizando la data del array: ";
    //invocamos la funcion printArray
    printArray(arr,n);
    //Pedir al usuario el valor a buscar
    cout<<"Ingrese el valor a buscar:";
    cin>>valor;
    //invocamos la funcion searchLineal
    int resultado=searchLineal(arr,n,valor);
    if(resultado!=-1)
        cout<<"El valor "<<valor<<" se encontro en la posicion: "<<resultado<<endl;
    else
        cout<<"El valor "<<valor<<" no se encontro en el arreglo: "<<endl;
    return 0;
}
