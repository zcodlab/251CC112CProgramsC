#include <iostream>
#include <ctime>
using namespace std;
const int ndato=4;
const int ndseguros=10;

struct datoSeguro{
    int dato[ndato];
    int paridad;
    int error;
};

int fParidad(datoSeguro& dS);
int fVerificacion(datoSeguro& dS);
void imprimirArreglo(datoSeguro arr[],int n,const string& titulo="");

int main()
{
    datoSeguro ArrayDS[ndseguros];
    int xVerificacion, iModificar;
    //1.-Inicializacion aleatoria
    srand(time(NULL));
    for(int i=0;i<ndseguros;i++){
            for(int j=0;j<ndato;j++)
                ArrayDS[i].dato[j]=rand()%2;

            ArrayDS[i].error=-1;
            //2.Calculo de la paridad
            fParidad(ArrayDS[i]);
    }
    //3.-visualizar el estado inicial del array
    imprimirArreglo(ArrayDS,ndseguros,"Valores Generados Inicialmente");
    //4.-Modificar dato[0] de un indice seleccionado
    cout<<"Ingrese el indice del elemento del arreglo a modificar (0-"<<ndseguros-1<<"): ";
    cin>>iModificar;        //captura el indice a modificar

    //5.-Invertir el valor de dato[0], con fines experimentales
    ArrayDS[iModificar].dato[0]=(ArrayDS[iModificar].dato[0]==0)?1:0;
    //6.-Verificar Errores
    cout<<"Verificacion de errores"
    for(int i=0;i<ndseguros;i++){
        xVerificacion=fVerificacion(ArrayDS[i]);
        if(xVerificacion!=0){
            cout<<"Error en ArrayDS["<<i<<"]:";
            cout<<"Paridad:"<<ArrayDS[i].paridad<<",";
            cout<<"Error:"<<ArrayDS[i].error<<endl;
        }
    }



    return 0;
}

int fParidad(datoSeguro& dS){
    int xParidad;
    int x0=dS.dato[0];
    for(int j=1;j<ndato;j++){
            xParidad=(x0==dS.dato[j])?0:1;//comprar x0 con el resto de columnas del elemento dato, si el igual se consigna cero como paridad, caso contrario se consigna 1
            x0=xParidad;        //x0 se actualiza en funcion de la paridad anteriormente generada
    }
    dS.paridad=xParidad;
    return 0;
}
void imprimirArreglo(datoSeguro arr[],int n,const string& titulo){
    if(!titulo.empty())
        cout<<endl<<titulo<<endl;
    for(int i=0;i<n;i++){
        cout<<"ArrayDS["<<i<<"]=";
        for(int j=0;j<ndato;j++)
            cout<<arr[i].dato[j]<<" ";
        cout<<"; Paridad: "<<arr[i].paridad<<"; Error: "<<arr[i].error<<endl;
    }
}
