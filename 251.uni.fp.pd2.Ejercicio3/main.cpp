#include <iostream>
using namespace std;
int FilasEnSucesion(int **A,int f,int c){
    int total=0;
    bool enSucesion=true;
    for(int i=0;i<f;i++){
            enSucesion=true;
            for(int j=1;j<c-1;j++){
                    int dif1=*(*A + c*i +j)-*(*A+ c*i +j-1);
                    int dif2=*(*A + c*i+ j+1)- *(*A + c*i + j);
                    if(dif1!=dif2){
                        enSucesion=false; break;
                    }
            }
            if(enSucesion) total++;
    }
    return total;
}

int main()
{
    const int MAXFIL=3;
    const int MAXCOL=4;
    int A[MAXFIL][MAXCOL]={{5,7,9,11},{4,2,0,-1},{7,6,5,4}};
    int *a=&A[0][0];
    cout << "Filas en Sucesion aritmetica; " <<FilasEnSucesion(&a,MAXFIL,MAXCOL)<< endl;
    return 0;
}
