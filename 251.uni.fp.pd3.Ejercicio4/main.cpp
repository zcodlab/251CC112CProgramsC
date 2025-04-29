#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

int longitudEntrada(char entrada[]){
    int i=0;
    char *token;
    token=strtok(entrada,",");
    while(token){//while(token!=nullptr)
            token=strtok(NULL,",");
            i++;
            cout<<"tokenI: "<<token<<" i= "<<i<<endl;
    }
    return i;
}
void guardarData(char entrada[],char nombre[],char direccion[],char celular[],int &edad,float &talla){
    char *token;
    //guardando nombre
    token=strtok(entrada,",");
    strcpy(nombre,token);
    //guardando direccion
    token=strtok(NULL,",");
    strcpy(direccion,token);
    //guardando celular
    token=strtok(NULL,",");
    strcpy(celular,token);
    //guardando edad
    token=strtok(NULL,",");
    edad=stoi(token);
    //guardando talla
    token=strtok(NULL,",");
    talla=stof(token);
}

int main()
{
    int N=3;
    int in=0;
    char *token;
    char nombre[N][50];
    char direccion[N][40];
    char celular[N][20];
    int edad[N];
    float talla[N];
    char entrada[200];
    char auxiliar[200];
    for(int k=0;k<N;k++){
        cout << "Ingrese entrada "<<k+1<<":"<<endl;
        cin.getline(entrada,sizeof(entrada),'\n');
        strcpy(auxiliar,entrada);
        if(longitudEntrada(auxiliar)==5){//si son 5 subcadenas
            guardarData(entrada,nombre[in],direccion[in],celular[in],edad[in],talla[in]);
            in++;
        }
        strcpy(entrada,"");//se limpian las variables
        strcpy(auxiliar,"");//se limpian las variables
    }
    cout<<"Los datos en el directorio son: "<<endl;
    cout<<left<<setw(20)<<"Nombre"<<left<<setw(40)<<"Direccion"<<left<<setw(15)<<"Celular"<<left<<setw(10)<<"Edad"<<left<<setw(10)<<"Talla"<<endl;
    for(int i=0;i<in;i++)
        cout<<left<<setw(20)<<nombre[i]<<left<<setw(40)<<direccion[i]<<left<<setw(15)<<celular[i]<<left<<setw(10)<<edad[i]<<left<<setw(10)<<talla[i]<<endl;
    return 0;
}
