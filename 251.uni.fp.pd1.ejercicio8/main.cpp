// el programa muestra un equipo con formacion 4 - 3 - 3
// 4 en la defensa, 3 en el medio campo y 3 delanteros
#include <iostream>
//#include <stdlib.h>
#include <time.h>
using namespace std;
int const N=11, M=3;

void quicksort(int[], int[], int , int);
int particionar(int[], int[], int, int);

int main(){
	int PLANTEL[N][M];
	int JUGADOR[N];
	int FORMACION[]={4,3,3};
	char TIPO[3][20]={"Defensa", "Mediocampo","Delantero"};
	int R[N];
    int num, c;
    srand(time(NULL));
    // se  mide la habilidad de 100 jugadores de futbol
	// en la escala de 1 a 5
    // en la defensa, mediocampo y como delantero
    for(int i=0;i<N;i++)    {
    	for(int j=0;j<M;j++)    {
	        PLANTEL[i][j]= 1 + rand() % (5);
    	}
    }
    cout<<"\tTABLA DE RENDIMIENTO\n";
    cout<<"\tJUG.\t"<<"DEFEN.\t"<<"MEDIO.\t"<<"DELANT."<<endl;
    for(int i=0;i<N;i++)    {
    	cout<<"\t"<<i+1<<"\t";
    	for(int j=0;j<M;j++)    {
	        cout<<PLANTEL[i][j]<<"\t";
    	}
    	cout<<endl;
    }

    for(int j=0;j<M;j++)    {
    	for(int i=0;i<N;i++)    {
    		R[i]=PLANTEL[i][j];
    		JUGADOR[i]=i;
    	}
    	quicksort(R,JUGADOR,0,N-1);

    	int nJugadores=FORMACION[j];// numero de jugadores a seleccionar
    	cout<<"\tJugadores de "<<TIPO[j]<<endl;
    	for(int i=0;i<nJugadores;i++){
    		cout<<"\t"<<JUGADOR[i]+1<<"\t"<<R[i]<<endl;
        	// ponemos ceros al rendimiento de los jugadores seleccionados
        	for(int k=0;k<M;k++){
        		PLANTEL[JUGADOR[i]][k]=0;
			}
		}
	}
    return 0;
}

void quicksort(int a[], int b[],int low, int high){
    if (low<high){
        //particionar desde a[low] hasta a[high]
        //y devolver el indice del pivote
        int pivotIdx=particionar(a,b,low,high);

        //recursivamente ordenar las dos partes
        quicksort(a,b,low,pivotIdx-1);
        quicksort(a,b,pivotIdx+1,high);
    }
}

int particionar(int a[],int b[], int i, int j){
    float p=a[i]; // p es el pivote
    // Las sublistas S1, S2, (Antes y despues del pivote)
    // estan vacias al inicio
    int m = i;
    // pasamos por cada elemento en la
    // region no particionada
    for (int k=i+1; k<=j; k++){
        if (a[k]>p)
        {
            m++;
            swap(a[k],a[m]);
            swap(b[k],b[m]);
        }
    }
    // intercambiar el pivote con a[m]
    swap(a[i],a[m]);
    swap(b[i],b[m]);
    //retornamos el indice del pivote
    return m;
}

