#include <iostream>
using namespace std;
bool esta(int n,int*U,int k){
    for(int i=0;i<k;i++)
        if(n==*(U+i))
            return true;
    return false;
}
int main()
{
    int A[20], B[20], U[40];
    int n,k=0,m;
    cout << "Cuantos elementos desea ingresar al conjunto A:";
    cin>>n;
    for(int i=0;i<n;i++){
            cout<<"Elemento "<<i<<": ";
             cin>>*(A+i) ;
            if(!esta(*(A+i) ,U,k)){//si no esta en U entonces lo agregamos
                *(U+k)=*(A+i);
                k++;
            }
    }
    cout << "Cuantos elementos desea ingresar al conjunto B:";
    cin>>m;
    for(int i=0;i<m;i++){
        cout<<"Elemento "<<i<<": ";
        cin>>*(B+i) ;
        if(!esta(*(B+i) ,U,k)){//si no esta en U entonces lo agregamos
                *(U+k)=*(B+i);
                k++;
         }
    }
    //visualizando el resultado de la Union
    for(int i=0;i<k;i++)
        cout<<*(U+i)<<"-";

    return 0;
}
