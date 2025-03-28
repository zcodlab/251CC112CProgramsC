#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int nDesaprobado=0,nAprobado=0,nBueno=0,nMuyBueno=0,nExcelente=0;
    int numNotas;
    float nota;
    cout << "Ingrese el numero de notas:" ;
    cin>>numNotas;
    for(int i=0;i<numNotas;i++){
            bool valido=false;
            do{
                cout<<"Ingrese nota:";cin>>nota;
                valido=(nota<=20 && nota>=0);
                if(!valido)
                    cout<<"Error.intente de nuevo."<<endl;
            }while(!valido);
            nota=trunc(nota*10.0)/10.0;
            if(nota<=9.9) nDesaprobado++;
            else if (nota<=10.9) nAprobado++;
            else if (nota<=12.9) nBueno++;
            else if (nota<=13.9) nMuyBueno++;
            else nExcelente++;
    }
    cout<<"Se tiene "<<nExcelente<< " alumnos en la escala A+"<<endl;
    cout<<"Se tiene "<<nMuyBueno<< " alumnos en la escala A"<<endl;
    cout<<"Se tiene "<<nBueno<< " alumnos en la escala B"<<endl;
    cout<<"Se tiene "<<nAprobado<< " alumnos en la escala C"<<endl;
    cout<<"Se tiene "<<nDesaprobado<< " alumnos en la escala D"<<endl;
    return 0;
}
