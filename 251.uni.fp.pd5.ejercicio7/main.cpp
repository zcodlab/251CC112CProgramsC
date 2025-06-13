#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
const int DIAS_DEL_ANIO=360;
const int DIAS_POR_MES=30;
const int MESES_DEL_ANIO=DIAS_DEL_ANIO/DIAS_POR_MES;
const int CARGA_BASE=500;
const int CARGA_VARIACION=201;
const double FACTOR_CARGA_MINIMA=0.95;
//definiendo las estructuras
struct TFECHA{
    int dia,mes;
};
struct TCARGA{
    int numPasajeros;
    TFECHA fecha;
};
//definiendo las funciones
void generarDatos(int A[], int size){
    for(int i=0;i<size;i++)
        A[i]=CARGA_BASE+rand()%CARGA_VARIACION;
}
int calcularCargaMaxima(int A[], int size){
    int maxCarga=A[0];
    for(int i=1;i<size;i++){
            if(A[i]>maxCarga)
                maxCarga=A[i];
    }
    return maxCarga;
}
//funcion que determina cuantos elementos de carga superar la carga minima (95% de capacidad)
int contarDiasMinimos(const int A[],int size,int minCarga){
    int contador=0;
    for(int i=0;i<size;i++){
            if(A[i]>=minCarga)
                contador++;
    }
    return contador;
}

TCARGA* filtrarDiasMinimos(const int A[], int size, int minCarga, int& cantidadFiltrada){
    cantidadFiltrada=contarDiasMinimos(A,size,minCarga);
    TCARGA* lista=new TCARGA[cantidadFiltrada];
    int k=0;
    for(int i=0;i<size;i++){
            if(A[i]>=minCarga){
                    lista[k].numPasajeros=A[i];
                    lista[k].fecha.mes=1 + i/DIAS_POR_MES;
                    lista[k].fecha.dia=1 + i%DIAS_POR_MES;
                    k++;
            }
    }
    return lista;
}
void mostrarResumen(const TCARGA lista[], int cantidad,int minCarga){
    cout<<"Se encontraron "<<cantidad<<" dias con carga minima de "<<minCarga<<" pasajeros."<<endl;
    for(int i=0;i<cantidad;i++){
            cout<<setw(6)<<lista[i].fecha.dia<<"/"<<setw(2)<<lista[i].fecha.mes
            <<": "<<setw(5)<<lista[i].numPasajeros<< " pasajeros"<<endl;

    }
}

int main()
{
    int A[DIAS_DEL_ANIO];
    srand(time(NULL));
    generarDatos(A, DIAS_DEL_ANIO);
    int cargaMaxima=calcularCargaMaxima(A, DIAS_DEL_ANIO);
    //static_cast en C++, operador de conversion, se utiliza para convertir un valor de tipo double en int
    //cargaMinima es aquella que supera el 95% de la capacidad maxima
    int cargaMinima=static_cast<int>(FACTOR_CARGA_MINIMA*cargaMaxima);
    //determinar cuantos envios y/o traslados superan la carga minima
    int cantidadFiltrada;
    TCARGA* lista=filtrarDiasMinimos(A, DIAS_DEL_ANIO,cargaMinima,cantidadFiltrada);
    mostrarResumen(lista,cantidadFiltrada,cargaMinima);
    delete[] lista;//liberar memoria

    return 0;
}
