#include <iostream>
#include <iomanip>
using namespace std;

void multiplicar(long long** A, long long** B, long long** R){
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            *(*(R+i)+j)=0;
                for(int k=0;k<2;k++){
                    cout<<"(i,j,k) "<<i<<j<<k<<" *(*(R+i)+j) "<<*(*(R+i)+j)<<" *(*(A+i)+k) "<<*(*(A+i)+k)<<" *(*(B+k)+j) "<<*(*(B+k)+j)<<endl;
                    *(*(R+i)+j)=*(*(R+i)+j) + *(*(A+i)+k)**(*(B+k)+j);
                  }
        }
}

void copiar(long long** A, long long** B){
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            *(*(A+i)+j)=*(*(B+i)+j);
}

void imprimir(long long** M){
    for(int i=0;i<2;i++)
        cout<<setw(20)<<*(*(M+i)+0)<<setw(20)<<*(*(M+i)+1)<<endl;
}

int main()
{
    int k;
    cout << "Ingrese un numero natural: " << endl;
    cin>>k;

    long long M[2][2]={{2,3},{4,5}};
    long long resul[2][2]={{1,0},{0,1}};
    long long tempo[2][2]={};

    long long* A[2];
    long long* resultado[2];
    long long* temporal[2];

    for(int i=0; i<2;i++){
            resultado[i]=resul[i];
            temporal[i]=tempo[i];
            A[i]=M[i];
    }

    for(int i=0; i<k;i++){
      multiplicar(resultado,A,temporal) ;
      copiar(resultado,temporal);        //acumula el resultado de la multiplicacion
    }

    cout<<"Mostrando resultado:"<<endl;
    imprimir(resultado);
    return 0;
}
