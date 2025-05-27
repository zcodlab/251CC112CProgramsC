#include <iostream>
using namespace std;
const int DIM=5;

struct posicion{
    int x;
    int y;
};

struct elemento{
  posicion pos;
  char ch; // 'X' ó '_' ó '*'
  int estado; //1=ocupado; 0=vacio; 2= impactado
};
//declara la matriz y la inicializa
int mBase[DIM][DIM]={
    {0,1,0,0,0},
    {1,1,1,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

elemento juego[DIM][DIM];
int mostrar(elemento tablero[][DIM]);
int inicializar(elemento tablero[][DIM]);

int main()
{
    int x,y;
    int vidas=-1;
    vidas=inicializar(juego);
    mostrar(juego);
    cout<<"Tenemos "<<vidas<< " vidas"<<endl;
    //Jugar
    while(vidas>0){
            cout<<"(coord. x:)";
            cin>>x;
            cout<<"(coord. y:)";
            cin>>y;
            if(x<0||x>DIM-1|| y<0||y>DIM-1){
                cout<<"Posicion Invalida, Intente nuevamente";
                continue;
            }
            mBase[x][y]=2;//valor que representa el impacto o disparo
            vidas=inicializar(juego);
            mostrar(juego);
            if(vidas==0)
                cout<<"Ganaste, El juego terminó";
            else
                cout<<"Aun quedan "<< vidas<<" vidas"<<endl;
    }

    return 0;
}

int inicializar(elemento tablero[][DIM]){
    int vidas=0;
    for(int i=0;i<DIM;i++){//para recorrer las filas
        for(int j=0;j<DIM;j++){//para recorrer las columnas
            tablero[i][j].pos.x=i;
            tablero[i][j].pos.y=j;
            if(mBase[i][j]==1){
                    tablero[i][j].ch='X';//representa un barco o una vida
                    tablero[i][j].estado=1;
                    vidas++;
            }else if(mBase[i][j]==2){
                    tablero[i][j].ch='*';//representa barco impactado o una vida menos
                    tablero[i][j].estado=2;
            }else if(mBase[i][j]==0){
                    tablero[i][j].ch='_';//representa espacio libre o vacio
                    tablero[i][j].estado=0;
              }
        }
    }
    return vidas;
}

int mostrar(elemento tablero[][DIM]){
    for(int i=0;i<DIM;i++){//para recorrer las filas
        for(int j=0;j<DIM;j++)//para recorrer las columnas
                cout<<tablero[i][j].ch<<" ";
        cout<<endl;
     }
    return 0;
}
