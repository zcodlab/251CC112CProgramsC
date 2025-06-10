#include <iostream>
using namespace std;
const int LIMITE_HORAS_ACUMULADAS=100;//cuando supere debera ir a mantenimiento
const int LIMITE_CODIGO=20;//representa el limite del codigo o numero de plaza del vehiculo
//Estructura que permitira manejar la informacion del vehiculo
struct SALIDA{
    int codigo;
    int horas;
    int distancia;
};
SALIDA* ingreso_de_datos(int &numSalidas){
    int codigo, horas, distancia;
    string rpta;
    numSalidas=0;
    SALIDA* V=new SALIDA[1];    //se crea un arreglo dinamico de una fila
    SALIDA*  aux;
    while(rpta!="no"){
            //registrar el codigo o placa del vehiculo
            do{
                cout<<"Ingrese el codigo del vehiculo: ";
                cin>>codigo;
            }while(codigo<1 || codigo>LIMITE_CODIGO);//mientras el codigo ingresado se encuentre fuera de limite
            //registrar las horas de funcionamiento
            cout<<"Ingrese las horas de funcionamiento del vehiculo: ";
            cin>>horas;
            cout<<"Ingrese la distancia recorrida del vehiculo: ";
            cin>>distancia;
            numSalidas++;
            //cada vez que se requiere agregar un nuevo registro al arreglo dinamico V
            aux=new SALIDA[numSalidas];//creando un arreglo dinamico aux de tamaño numSalidas
            for(int i=0;i<numSalidas - 1;i++)
                aux[i]=V[i];    //descargamos el contenido de V en aux, toda vez que aux es un arreglo dinamico mas grande que V, por lo menos en una unidad
            //agregamos el nuevo item al final
            aux[numSalidas-1].codigo=codigo;
            aux[numSalidas-1].horas=horas;
            aux[numSalidas-1].distancia=distancia;
            //liberamos memoria utilizada por V
            delete V;
            V=aux;  //V apunta a aux, que es el nuevo arreglo
            cout<<"Desea registra una entrega de productos?(si/no): ";
            cin>>rpta;
    }
    return V;
}
int* vehiculos_en_mantenimiento(SALIDA* V,int nSalidas,int &nMantenimiento){
    int* S=new int[1];//crea un arreglo de enteros de una fila
    int* aux;               //crea un puntero a enteros
    for(int codigo=1;codigo<=LIMITE_CODIGO;codigo++){
            int horasacumuladas=0;
            for(int i=0;i<nSalidas;i++)
                if(V[i].codigo==codigo)         //ubicando el vehiculo
                        horasacumuladas+=V[i].horas;
            //verificando los vehiculo que superaron el LIMTE_HORAS_ACUMULADAS
            if(horasacumuladas>LIMITE_HORAS_ACUMULADAS){
                    nMantenimiento++;
                    aux=new int[nMantenimiento];
                    for(int i=0;i<nMantenimiento-1;i++)
                        aux[i]=S[i];        //desplazando S en aux, se entiende que el arreglo dinamico aux es mas grande que S
                    //consignamos en la ultima posicion de aux el vehiculo que requiere mantenimiento
                    aux[nMantenimiento-1]=codigo;
                    delete S;//libera memoria del arreglo antiguo
                    S=aux;  //S apunta a aux, que es el nuevo arreglo
            }
    }
    return S; //tiene la relacion de los codigos de los vehiculos que requieren mantenimiento
}

int main()
{
    SALIDA* V;
    int* S;
    int nSalidas=0;             //cuantas salidas ha realizado el vehiculo
    int nMantenimiento=0;
    V=ingreso_de_datos(nSalidas);
    S=vehiculos_en_mantenimiento(V,nSalidas,nMantenimiento);
    cout<<"Listado de Vehiculos para mantenimiento"<<endl;
    for(int i=0;i<=nMantenimiento-1;i++)
        cout<<"\tVehiculo "<<S[i]<<endl;

    return 0;
}
