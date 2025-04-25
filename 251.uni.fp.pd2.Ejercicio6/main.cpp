#include <iostream>
using namespace std;
const int NCOL=9;
const int NFIL=9;

void mostrar(int **A,int n,int m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout<<*(*A+i*m+j)<<" ";
            cout<<endl;
        }
}

void generar(int **A,int n,int m){
    int C[m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            C[j]=1+j;
        for(int j=0;j<m;j++){
                int pos=rand()%(m-j);
                *(*A+i*m+j)=C[pos];
                swap(C[pos],C[m-j-1]);
        }
    }
}
void actualizar(int **A,int n,int m,int fil,int col){
    int valor=*(*A+fil*m+col);
    int fila_actual[m];
    int *p=fila_actual;
    cout<<"Valor seleccionado: "<<valor<<endl;
    for(int i=0;i<n;i++){
            int col0;
            for(int j=0;j<m;j++){
                  *(p+j)=*(*A+i*m+j);
                  if(*(p+j)==valor)
                    col0=j;
            }
            for(int j=0;j<m;j++){
                 int col_origen=j-col+col0;
                 if(col_origen<0) col_origen=col_origen+m;
                 if(col_origen>=m) col_origen=col_origen-m;
                 *(*A+i*m+j)=*(p+col_origen);
            }
    }
}

int main()
{
    int M[NFIL][NCOL];
    int FIL_ACTUAL,COL_ACTUAL;
    int *F=&M[0][0];
    int **A=&F;
    generar(A,NFIL,NCOL);
    cout<<"Tabla inicial"<<endl;
    mostrar(A,NFIL,NCOL);
    cout<<endl;
    cout<<"Fila Inicial(1-9)";cin>>FIL_ACTUAL;
    FIL_ACTUAL--;
    cout<<"Columna Inicial(1-9)";cin>>COL_ACTUAL;
    COL_ACTUAL--;
    actualizar(A,NFIL,NCOL,FIL_ACTUAL,COL_ACTUAL);
    cout<<endl;
    cout<<"Tabla final"<<endl;
    mostrar(A,NFIL,NCOL);
    return 0;
}
