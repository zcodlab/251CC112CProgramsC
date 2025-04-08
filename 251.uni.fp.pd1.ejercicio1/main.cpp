#include <iostream>
#include <iomanip>
using namespace std;
const int n=7;

int calcula_elemento(int A[n][n],int fil,int col){
    // Verificar que los índices no sean inválidos
    if (col < 0 || fil < col)
        return 0;
    // Condiciones base
    if (fil == 0 && col == 0)
        return 1;
    if (A[fil][col] != 0)  // Si ya está calculado, retornar el valor ya calculado
        return A[fil][col];
    // Si el valor no está calculado, calcular recursivamente
    A[fil][col] = calcula_elemento(A, fil - 1, col) + calcula_elemento(A, fil - 1, col - 1);
    return A[fil][col];
}

//funcion recursiva parar llenar matriz
void forma_matriz(int A[n][n],int fil,int col){
    if(fil<0)
        return;
    if(col>=0){
        A[fil][col]=calcula_elemento(A,fil,col);
        forma_matriz(A,fil,col-1);
    }else
        forma_matriz(A,fil-1,col-1);
}

int main()
{
    int A[n][n]={0};
    forma_matriz(A,n-1,n-1);//llamada inicial para llenar la matriz
    //imprimir la matriz
    for(int fil=0;fil<n;fil++){
            for(int col=0;col<n;col++)
                cout<<setw(4)<<A[fil][col];
            cout <<endl;
    }
    return 0;
}
