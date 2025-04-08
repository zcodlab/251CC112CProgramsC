#include <iostream>
#include <ctime>
using namespace std;
const int m=50;//10 alumnos * 5 notas cada uno
const int n=10;
const int nn=5;
void quicksort(float a[],int low,int high);
int particionar(float a[],int low,int high);
int NotasGeneradas[m];
float pAlumnos[n];
float ranking[n];

int main()
{
    int tmp,k;
    float promedio;
    srand(time(NULL));
    for(int i=0;i<m;i++){
        tmp=rand()%21;
        NotasGeneradas[i]=tmp;
      }
      //asignacion de notas y promedios
      k=0;
      cout<<"Promedios de Alumnos"<<endl;
      for(int i=0;i<n;i++){
          promedio=0;
          for(int j=0;j<nn;j++)
                promedio=promedio+NotasGeneradas[k++];
          promedio=promedio/nn;
          pAlumnos[i]=promedio;
          ranking[i]=promedio;
          cout<<"pAlumnos["<<i<<"]="<<pAlumnos[i]<<endl;
      }
      quicksort(ranking,0,n-1);
      cout<<endl<<"Mejores Notas"<<endl;
      int puesto=0;
      for(int i=n-1;i>=(n-3);i--)
            cout<<"Puesto "<<++puesto<<": "<<ranking[i]<<endl;

      cout<<endl<<endl;
      //imprimir array Notas Generadas
     cout<<"Notas Generadas"<<endl;
     for(int i=0;i<m;i++)
         cout<<NotasGeneradas[i]<<" ";
    //imprimir array Ranking
    cout<<endl<<"Raking"<<endl;
    for(int i=0;i<n;i++)
         cout<<ranking[i]<<" ";

    return 0;
}
void quicksort(float a[],int low,int high){
    if(low<high){
            int pivotIdx=particionar(a,low,high);
            //invocar recursivamente a las listas generadas
            quicksort(a,low,pivotIdx-1);//L1
            quicksort(a,pivotIdx+1,high);//L2
    }
}
int particionar(float a[],int i,int j){
    int p=a[i];//valor del pivote
    int m=i;   //posicion del pivote
    for(int k=i+1;k<=j;k++){
            if(a[k]<p){
                m++;
                if(a[k]!=a[m])
                    swap(a[k],a[m]);
            }
    }
    swap(a[i],a[m]); //intercambia el pivote con el elemento mas pequeño
    return m;
}
