#include <iostream>
#include <ctime>
using namespace std;
int X[100];//numeros generados aleatoriamente
int XB[10][10];//matriz resultante
int generador(void);
void quicksort(int a[],int low,int high);
int particionar(int a[],int low,int high);

int main()
{
    srand(time(NULL));
    for(int i=0;i<100;i++)
        X[i]=generador();
    //ordenar array
    quicksort(X,0,99);
    //imprimir array
    for(int i=0;i<100;i++)
        cout << X[i]<<" ";
    cout<< endl;
    //rellenando 4 cuadrante de la matriz
    int k=75;
    for(int i=5;i<10;i++){
        for(int j=5;j<10;j++){
            XB[i][j]=X[k];
            k++;
        }
    }
    //imprimir matriz
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
            cout<<"\t"<<XB[i][j];
        cout<<endl;
    }
    return 0;
}
int generador(){
    int valor;
    valor=100+ (rand()%101);
    return valor;
}
void quicksort(int a[],int low,int high){
    if(low<high){
            int pivotIdx=particionar(a,low,high);
            //invocar recursivamente a las listas generadas
            quicksort(a,low,pivotIdx-1);//L1
            quicksort(a,pivotIdx+1,high);//L2
    }
}
int particionar(int a[],int i,int j){
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
