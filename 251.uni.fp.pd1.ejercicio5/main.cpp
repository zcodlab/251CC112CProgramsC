#include <iostream>
#include <vector>
using namespace std;
void dividir_numero(int num,vector<int> &resultado){
    if (num>0){
            cout<<"Before: resultado "<<num<<endl;
            for(int i:resultado)
                cout<<i<<", ";
            cout<<endl;
            dividir_numero(num/10,resultado);
            resultado.push_back(num%10);
            cout<<"After: resultado"<<num<<endl;
            for(int i:resultado)
                cout<<i<<",";
            cout<<endl;
    }
}

void agregar(vector<int> &a,vector<int> &b,vector<int> &resultado){
    int m=a.size();
    int n=b.size();
    int i=0;
    while(i<m && i<n){
            int sum=a[i]+b[i];
            dividir_numero(sum,resultado);
            i++;
    }
    while(i<m)
        dividir_numero(a[i++],resultado);

    while(i<n)
        dividir_numero(b[i++],resultado);
}

int main()
{
    vector<int> a={23,5,2,7,87};
    vector<int> b={4,67,2,8};
    vector<int> resultado;

    agregar(a,b,resultado);

    cout << "resultado: " << endl;
    for(int i:resultado)
        cout<<i<<", ";
    return 0;
}
