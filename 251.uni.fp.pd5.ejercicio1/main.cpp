#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int N=100;

int main()
{
    ifstream i1("input1.txt",ios::in); //in: abrir archivo en modo lectura
    ifstream i2("input2.txt",ios::in); //in: abrir archivo en modo lectura
    //i1,i2 son flujos de entrada para leer dos archivos

    //para determinar si los archivos fueron abiertos correctamente
    if(!i1.good() || !i1.good()){
        cout<<"Error al abrir los archivos"<<endl;
        return 1;
    }

    char line1[N], line2[N];  //buffers para guardar una linea de cada archivo
    int sz1,sz2;                    //mantiene la longitud de la linea
    int line=0;                     //contador de lineas
    while(i1.getline(line1,N)){
            int search=0;
            if(i2.getline(line2,N)){     //si el segundo archivo tiene contenido
                 if(strcmp(line1,line2))  {
                        sz1=strlen(line1);      //obtiene la longitud de la linea<=N
                        sz2=strlen(line2);      //obtiene la longitud de la linea<=N
                        int column=-1;
                        for(int i=0; i<sz1 && i<sz2 && column==-1;i++){
                            if( line1[i] !=line2[i])
                                column=i;
                        }  //reserva en la variable column, la columna con el error detectado
                        if(column==-1){
                            column=sz1;
                            if(sz1>=sz2)
                                column=sz2;
                        }
                        cout<<"Diferencia en la linea y columna:("<<line<<" , "<<column<<")"<<endl;
                    }//if interno
                    search=1;
            } //if externo
            //si el archivo no tiene  mas lineas; si el segundo archivo concluyo antes que el primer archivo, se marca la diferencia en la columa cero
            if(!search)
                cout<<"Diferencia en la linea y columna:("<<line<<" , "<<0<<")"<<endl;
            line++;
    }//while
    return 0;
}
