#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string apellidos,nombre,cadena,apeMax,nomMax;
    int n,i,num,indMax;
    float* prom, promMax;
    float nota1, nota2;
    ifstream ar;
    ar.open("baseUNI.txt"); //abrimos el archivo de modo lectura
    n=0;
    while(!ar.eof()){    //eof: funcion que señala fin del archivo
        getline(ar,cadena);
        n++;
     }
     ar.close();
     prom=new float[n]; //n refiere al numero de filas del archivo
     cout<<"Num\tApellidos\tNombre\tNota1\tNota2\tPromedio"<<endl;
     ar.open("baseUNI.txt"); //abrimos el archivo de modo lectura
     indMax=0;
     promMax=0;
     apeMax="";
     nomMax="";
     for(i=0;i<n;i++){
            getline(ar,cadena,'.'); //recupera la linea de texto hasta el primer punto(num)
            num=stoi(cadena); //stoi convierte un string a int
            getline(ar,cadena,',');//recupera la linea de texto hasta la primera coma(apellidos)
            apellidos=cadena;
            getline(ar,cadena,'-');//recupera la linea de texto hasta el primer guion(nombre)
            nombre=cadena;
            getline(ar, cadena, '-');//recupera la linea de texto hasta el segundo guion(nota1)
            nota1=stof(cadena);//stof convierte un string a float
            getline(ar,cadena);
            nota2=stof(cadena);
            prom[num-1]=(nota1+nota2)/2;
            if(prom[num-1]>promMax){
                    promMax=prom[num-1];
                    indMax=num - 1;
                    apeMax=apellidos;
                    nomMax=nombre;
            }
            cout<<num<<"\t"<<apellidos<<"\t"<<nombre<<"\t"
            <<nota1<<"\t"<<nota2<<"\t"<<prom[num-1]<<endl;
     }
     ar.close();
     cout<<"\nEl promedio maximo: "<<promMax<<endl;
     cout<<"Alumno: "<<nomMax<<" "<<apeMax<<endl;
     delete[] prom; //liberar memoria

     return 0;
}
