#include <iostream>
#include <ctime>
const int NB=2;
const int NRAND=5;//para generar los valores aleatorios
using namespace std;

struct MatrizEstructura{
    int B[NB][NB];
    int suma;
};
void imprimirMatriz(MatrizEstructura** matrizA,int filas,int columnas){
     for(int i=0;i<filas;i++){
             for(int j=0;j<columnas;j++){
                 cout<<"MatrizA["<<i<<"]["<<j<<"] (suma= "<<matrizA[i][j].suma<<").";
                 cout<<"Direccion de memoria de B:"<<&matrizA[i][j].B<<endl;
                 for(int row=0;row<NB;row++)
                        for(int col=0;col<NB;col++)
                            cout<<"B["<<row<<"]["<<col<<"]="<<matrizA[i][j].B[row][col]<<" ";
                    cout<<endl;
             }
             cout<<endl;
     }
}
void encontrarMayorSuma(MatrizEstructura** matrizA,int filas,int columnas){
    int mayorSuma=matrizA[0][0].suma;
     for(int i=0;i<filas;i++){
             for(int j=0;j<columnas;j++){
                    if(matrizA[i][j].suma>mayorSuma)
                        mayorSuma=matrizA[i][j].suma;
             }
      }
      cout<<"La mayor Suma de Elementos de B es:"<<mayorSuma<<" y se encuentra en:";
       for(int i=0;i<filas;i++){
             for(int j=0;j<columnas;j++){
                    if(matrizA[i][j].suma==mayorSuma){
                            cout<<"MatrizA["<<i<<"]["<<j<<"].";
                            cout<<"Valor de suma: "<<matrizA[i][j].suma;
                            cout<<" .Direccion de memoria de B: "<<&matrizA[i][j].B<<endl;

                    }

             }

       }

}

int main()
{
    srand(time(NULL));
    int filas, columnas;
    cout << "Numero de Filas de A:";
    cin>> filas;
    cout << "Numero de Columnas de A:";
    cin>> columnas;
    MatrizEstructura** matrizA=new MatrizEstructura*[filas];
    for(int i=0;i<filas;i++){
            matrizA[i]=new MatrizEstructura[columnas];
            for(int j=0;j<columnas;j++){
                for(int row=0;row<NB;row++)
                    for(int col=0;col<NB;col++)
                        matrizA[i][j].B[row][col]=rand()%NRAND+1;//genera valores aleatorios entre 1 y 5
                //calcular la suma de los elementos de la matriz B
                matrizA[i][j].suma=matrizA[i][j].B[0][0]+matrizA[i][j].B[0][1]+matrizA[i][j].B[1][0]+matrizA[i][j].B[1][1];
            }
    }
    cout<<"Matriz A:"<<endl;
    imprimirMatriz(matrizA,filas,columnas);
    encontrarMayorSuma(matrizA,filas,columnas);
    //liberando espacio de memoria utilizado
    for(int i=0;i<filas;i++)
        delete[] matrizA[i];
    delete[] matrizA;
    return 0;
}
