#include <iostream>
using namespace std;
const int NUM_VENDEDORES=99;
const int BLOQUE_INICIAL=3;

//funcion para expandir tamaño del array dinamico
int* expandirArrayInt(int* original,int tamanioActual,int nuevoTamanio){
    int* nuevoArray=new int[nuevoTamanio];
    //Realizando la reasignacion
     for(int i=0;i<tamanioActual;i++)
            nuevoArray[i]=original[i];
    delete[] original;
    return nuevoArray;
}

//funcion para expandir tamaño del array dinamico
float* expandirArrayFloat(float* original,int tamanioActual,int nuevoTamanio){
    float* nuevoArray=new float[nuevoTamanio];
    //Realizando la reasignacion
     for(int i=0;i<tamanioActual;i++)
            nuevoArray[i]=original[i];
    delete[] original;
    return nuevoArray;
}

void ingresarVentas(float*& montos,int*& codigos,int& numVentas){
    float monto;
    int codigo;
    int capacidad=BLOQUE_INICIAL;
    numVentas=0;
    montos=new float[capacidad];
    codigos=new int[capacidad];
    while(true){
            cout<<"Ingrese el monto de ventas (-1 para terminar): ";
            cin>>monto;
            if(monto < 0 ) break;//salimos del bucle while
            cout<<"Ingrese el codigo del vendedor (1-99): ";
            cin>>codigo;
            //validando el codigo ingresado
            if(codigo<1 || codigo>NUM_VENDEDORES){
                    cout<<"Codigo Invalido. Intente nuevamente.";
                    continue;
            }
            //si supero la capacidad del array dinamico, incrementar su tamaño
            if(numVentas>=capacidad){
                capacidad+= BLOQUE_INICIAL;
                montos=expandirArrayFloat(montos,numVentas,capacidad);
                codigos=expandirArrayInt(codigos,numVentas,capacidad);
            }
            montos[numVentas]=monto;
            codigos[numVentas]=codigo;
            numVentas++;
    }

}
 float calcularTotalYPromedio(float* montos,int* codigos,int numVentas,float totalVentas[]){
     float sumaTotal=0.0f;
     for(int i=0;i<numVentas;i++){
            int cod=codigos[i];
            totalVentas[cod-1]+=montos[i];//acumulando las ventas del vendedor
            sumaTotal+=montos[i];//acumulando el importe total vendido para calcular el promedio de ventas
     }
     return (numVentas>0)? sumaTotal/numVentas : 0.0f;
 }
 int obtenerCodigosUnicos(int* codigos,int numVentas,int codigosUnicos[]){
     int totalUnicos=0;
     for(int i=0;i<numVentas;i++){
            int cod=codigos[i];
            bool existe=false;
            for(int j=0;j<totalUnicos;j++){
                    if(codigosUnicos[j]==cod){
                        existe=true;
                        break;
                    }
            }
             if(!existe)
                        codigosUnicos[totalUnicos++]=cod;
     }
     return totalUnicos;
 }
 void mostrarVendedoresSuperiores(float totalVentas[],int codigosUnicos[],int totalUnicos,float promedio){
     cout<<"Monto Promedio de Ventas: "<<promedio<<endl;
     cout<<"Vendedores que superan el promedio: "<<endl;
     bool hay=false;
     for(int i=0;i<totalUnicos;i++){
         int cod=codigosUnicos[i];
         if(totalVentas[cod-1]>promedio){
                cout<<"Vendedor: "<<cod<<" | Monto vendido: "<<totalVentas[cod-1]<<endl;
                hay=true;
         }
     }
     if(!hay)
        cout<<"Ningun vendedor supero el promedio."<<endl;
 }

int main()
{
    float* vecMontos=nullptr;
    int* vecCodigos=nullptr;
    int numVentas=0;
    //Paso1: Ingreso de Ventas
    ingresarVentas(vecMontos,vecCodigos,numVentas);
    //Paso2: Calcular el total por vendedor y el promedio de ventas
    float totalVentas[NUM_VENDEDORES]={0.0f};
    float promedio=calcularTotalYPromedio(vecMontos,vecCodigos,numVentas,totalVentas);
    //Paso3: Obtener los codigos unicos utilizados
    int codigosUnicos[NUM_VENDEDORES];
    int totalUnicos=obtenerCodigosUnicos(vecCodigos,numVentas,codigosUnicos);
    //Paso4: Mostrar los vendedores que superan el promedio de ventas
    mostrarVendedoresSuperiores(totalVentas,codigosUnicos,totalUnicos,promedio);
    //Liberar memoria dinamica
    delete[] vecMontos;
    delete[] vecCodigos;
    vecMontos=nullptr;
    vecCodigos=nullptr;
    return 0;
}
