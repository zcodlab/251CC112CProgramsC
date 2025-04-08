#include <iostream>
#include <string>
using namespace std;

void lectura(string A[],int n){
    string nombre,nota;
    for(int i=0;i<n;i++){
            cout << "Ingrese nombre "<<i <<": ";
            getline(cin,nombre);
            cout << "Ingrese nota "<<i <<": ";
            getline(cin,nota);
            A[i]=nombre+" "+nota;
    }
    return;
}
void imprimir(string A[],int n){
    for(int i=0;i<n;i++)
        cout<<A[i]<<endl;
    return;
}
void ordBurbuja(string A[],int n){
    int i;
    bool flag;
    for(int i=0;i<n-1;i++){
            flag=false;
            for(int j=0;j<n-1;j++){
                    if(A[j]>A[j+1]){
                        swap(A[j],A[j+1]);
                        flag=true;
                    }
            }
            if(!flag)
                break;
    }
        return;
}

int main()
{
    string A[30];
    int n;
    cout << "Cuantos alumnos ingresara: " ;
    cin>>n;
    cin.ignore();
    lectura(A,n);
    cout <<endl<< "Imprimiendo Array Inicial";
    imprimir(A,n);
    ordBurbuja(A,n);
    cout <<endl<< "Imprimiendo Array Final" ;
    imprimir(A,n);
    return 0;
}
