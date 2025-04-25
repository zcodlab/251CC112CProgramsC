#include <iostream>
using namespace std;
void imprime(int *p,int n){
    cout<<"\n p(x)="<<*p++;
    for(int i=1; i<n; i++){
        cout<<((*p<0)?"-":"+")<<abs(*p)<<"x^"<<i;
        p++;
    }
    cout<<endl;
}
void derivada(int *p,int n,int k){
    int t;
    for(int i=0;i<n;i++){
            t=i+1;
            if(i<n-k){
                for(int j=2;j<k+1;j++)
                    t=t*(i+j);
                *p=*(p+k)*t;
            }else
                *p=0;
            p++;
    }
}

int main()
{
    int A[100];
    int k,n;
    cout << "Ingrese el grado del polinomio: " ; cin>>n;
    cout << "Ingrese los coeficientes del polinomio: " ;
    for(int i=0;i<n+1;i++){
        cout <<"A["<<i<<"]= ";
        cin>>A[i];
      }
    imprime(A,n+1);
    cout << "Ingrese el orden k: " ; cin>>k;
    derivada(A,n+1,k);
    cout << "\n La derivada k-esima es: " ;
    imprime(A,n-k+1);
    return 0;
}
