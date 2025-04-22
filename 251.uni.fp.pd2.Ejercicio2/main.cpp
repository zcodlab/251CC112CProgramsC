#include <iostream>
using namespace std;
int suma_divisores(int n){
    int s=1;
    for(int k=2;k<n;k++)
        if(n%k==0)
            s+=k;
    return s;
}

int son_amigos(int n,int m){
    return (suma_divisores(n)==m && suma_divisores(m)==n);
}

int muestra_amigos(int *p){
    int *q;
    while(*p!=0){
        q=p+1;
        while(*q!=0){
            if(son_amigos(*q,*p))
                cout<<*q<<" y "<<*p<<" son amigos"<<endl;
            q++;
        }
        p++;
    }
}

int main()
{
    int A[]={100,220,300,284,1184,1210,0,0};
    int *p=A;
    muestra_amigos(p);

    return 0;
}
