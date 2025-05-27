#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
const int NUM=5;
const int PARTIDOS=100;

struct seleccion{
    string nombre;
    int puntajetotal;
    int pganados;//numero de partidos ganados
    int pempatados;//numero de partidos empatados
    int pperdidos;//numero de partidos perdidos
    double rendimiento;
};

int main()
{
    seleccion tabla[NUM];
    srand(time(NULL));
    int pg,pp,pe,n=NUM;
    int mejorrendimiento=-1, imjr=-1;
    //Generar Tabla
    for(int i=0;i<n;i++){//para recorrer las filas
        tabla[i].nombre="Seleccion "+ to_string(i);
        pg=rand()%PARTIDOS;
        tabla[i].pganados=pg;
        pe=rand()%(PARTIDOS-pg);
        tabla[i].pempatados=pe;
        pp=PARTIDOS-(tabla[i].pganados+tabla[i].pempatados);
        tabla[i].pperdidos=pp;
        tabla[i].puntajetotal=3*pg+1*pe;
        tabla[i].rendimiento=100.0*(double)tabla[i].puntajetotal/(3.0*PARTIDOS);
        //3.0*PARTIDOS: Es el maximo total de puntos que una seleccion puede conseguir en el caso mas favorable o invicto
        if(mejorrendimiento<tabla[i].rendimiento){//quiere decir que existe un equipo con mejor rendimiento
           mejorrendimiento= tabla[i].rendimiento;
           imjr=i;
        }
    }
    //imprimir la tabla
    cout<<"Seleccion \t\t"<<"PG \t"<<"PP \t"<<"PE \t"<<"Puntaje \t"<<"Rendimiento"<<endl;
     for(int i=0;i<n;i++){
            cout<<"Pais "<<tabla[i].nombre<<"\t"
            <<tabla[i].pganados<<"\t"
            <<tabla[i].pperdidos<<"\t"
            <<tabla[i].pempatados<<"\t"
            <<tabla[i].puntajetotal<<"\t\t"
            //setprecision(3): controla cuando digitos significativos o decimales se muestran: 66.0, 70.5, etc uniformizando la vista resultante
            //de no hacer ello podriamos tener un resultado:  66, 70.5, etc, sin vista uniforme
            //showpoint: fuerza la visualizacion del punto decimal y ceros finales
            <<std::setprecision(3)<<std::showpoint<<tabla[i].rendimiento<<"%"<<endl;
     }
    cout<<"La seleccion con mejor rendimiento es:"<<tabla[imjr].nombre<<endl;
    cout<<"Rendimiento: "<<tabla[imjr].rendimiento<<endl;
    return 0;
}
