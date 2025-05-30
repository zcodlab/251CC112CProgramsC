#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char texto[] = "La Universidad Nacional de Ingenieria,\n"
"es una institucion educativa la cual fue fundada en 1876\n" "por el ingeniero polaco Eduardo de Habich.";

    cout << "El texto ingresado es:" <<endl<<endl;
    cout << texto<< endl<<endl;

    int num_columnas;
    cout<<"Ingrese el ancho de la matriz de texto:";
    cin>>num_columnas;

    int num_filas;
    char* ptr_texto;
    ptr_texto=&texto[0]; //que apunte a la posicion dememoria del primer caracter
    num_filas=(strlen(ptr_texto)/num_columnas)+1;//dividir la longitud del texto entre el numero de columnas

    char** celda=new char*[num_filas];//arreglo de punteros a caracteres
    int fil,col;
    for(fil=0;fil<num_filas;fil++){
            celda[fil]=new char[num_columnas];//para cada fila le creamos su arreglo de columnas
            for(col=0;col<num_columnas;col++)
                celda[fil][col]=' ';
    }
    //proceso de descarga del texto en la matriz
    ptr_texto=&texto[0];
    fil=0;col=0;
    while(*ptr_texto){
            celda[fil][col]=*ptr_texto;
            col++;
            if(col>=num_columnas){
                col=0;
                fil++;
            }
            ptr_texto++;
    }

    cout<<"El parrafo ajustado es:"<<endl<<endl;
    int cont=0;
    for(fil=0;fil<num_filas;fil++){
            for(col=0;col<num_columnas;col++){
                if(celda[fil][col]=='\n'){
                        cout<<endl;
                        cont=0;
                }else{
                        cout<<celda[fil][col];
                        cont++;
                }if(cont>=num_columnas){
                    cont=0;
                    cout<<endl;
                }
            }
    }
    return 0;
}
