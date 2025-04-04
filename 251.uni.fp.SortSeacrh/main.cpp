#include <iostream>
#include <stdexcept>//para manejo de excepciones
using namespace std;

void carga(){
    cout<<"Carga Fija de Datos en Array"<<endl;
    int X[8]={5,14,24,39,43,65,84,45};
}
void cargarDatos(int X[],int n){
    cout<<"Carga Personalizada de Datos en el Array"<<endl;
    cout<<"Introduce "<<n<<" numeros para el array"<<endl;
    for(int i=0;i<n;i++)
         cin>>X[i];
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

void liberarMemoria(int* X){
    delete[] X;
}

void menu(){
    cout<<"\nAlgoritmos de Busqueda y Ordenamiento"<<endl;
    cout<<"1.- Cargar datos en el Array"<<endl;
    cout<<"2.- Visualizar Array"<<endl;
    cout<<"3.- Ordenamiento Burbuja"<<endl;
    cout<<"4.- Salir"<<endl;
    cout<<"Elija una opcion: ";
}

int main()
{
    int* X=nullptr;//puntero para manejar arrays dinamicos
    int n=0;
    int opcion=0;
    cout << "Ingrese el tamaño del array: ";
    cin>>n;
    X=new int[n];
    do{
            menu();
            cin>>opcion;
            switch(opcion){
                case 1: cargarDatos(X,n); break;
                case 2: visualizar(X,n); break;
                case 3: bubbleSort(X,n); break;
                case 4: cout<<"Saliendo del programa...."<<endl; liberarMemoria(X); break;
                default: cout<<"Opcion no valida...., elija una opcion correcta"<<endl; break;
            }
    }while(opcion!=4);//bucle se ejecuta hasta pulsar opcion 4

    return 0;
}
