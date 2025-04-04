#include <iostream>
#include <stdexcept>//para manejo de excepciones
using namespace std;

void carga(){
    cout<<"Carga Fija de Datos en Array"<<endl;
    int X[8]={5,14,24,39,43,65,84,45};
}

void copiarArray(int*X,int*C,int n){
    for(int i=0;i<n;i++)
        C[i]=X[i];
}

void cargarDatos(int X[],int C[],int n){
    cout<<"Carga Personalizada de Datos en el Array"<<endl;
    cout<<"Introduce "<<n<<" numeros para el array"<<endl;
    for(int i=0;i<n;i++)
         cin>>X[i];
    copiarArray(X,C,n);
}

void visualizar(int X[],int n){
    cout<<"Visualizando el Array"<<endl;
    for(int i=0;i<n;i++)
        cout<<X[i]<<" ";

    cout<<endl;
}
void bubbleSort(int X[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<(n-1)-i;j++){
            if(X[j]>X[j+1]){
                    //intercambio
                    int temp=X[j];
                    X[j]=X[j+1];
                    X[j+1]=temp;
            }

        }
    }
}
void selectionSort(int X[],int n){
    for(int i=0;i<n-1;i++){
            int minIndex=i;
            //en busqueda de la posicion con elemento mas pequeño
            for(int j=i+1;j<n;j++){
                    if(X[j]<X[minIndex])
                        minIndex=j;
            }
            if(minIndex!=i){
                    //intercambio con el mas pequeño
                    int temp=X[i];
                    X[i]=X[minIndex];
                    X[minIndex]=temp;
            }
    }
}

void liberarMemoria(int* X){
    delete[] X;
}

void menu(){
    cout<<"\nAlgoritmos de Busqueda y Ordenamiento"<<endl;
    cout<<"1.- Cargar datos en el Array"<<endl;
    cout<<"2.- Visualizar Array"<<endl;
    cout<<"3.- Ordenamiento Burbuja"<<endl;
    cout<<"4.- Ordenamiento Seleccion"<<endl;
    cout<<"5.- Salir"<<endl;
    cout<<"Elija una opcion: ";
}

int main()
{
    int* X=nullptr;//puntero para manejar arrays dinamicos
    int* C=nullptr;//puntero para manejar arrays dinamicos
    int n=0;
    int opcion=0;
    cout << "Ingrese el tamaño del array: ";
    cin>>n;
    X=new int[n];
    C=new int[n];
    do{
            menu();
            cin>>opcion;
            switch(opcion){
                case 1: cargarDatos(X,C,n); break;
                case 2: visualizar(X,n); break;
                case 3: copiarArray(C,X,n);visualizar(X,n);bubbleSort(X,n);visualizar(X,n); break;
                case 4: copiarArray(C,X,n);visualizar(X,n);selectionSort(X,n); visualizar(X,n); break;
                case 5: cout<<"Saliendo del programa...."<<endl; liberarMemoria(X); break;
                default: cout<<"Opcion no valida...., elija una opcion correcta"<<endl; break;
            }
    }while(opcion!=5);//bucle se ejecuta hasta pulsar opcion 4

    return 0;
}
