#include <iostream>
#include <iomanip>
using namespace std;
unsigned long factorial(unsigned long);//funcion prototipo
int main()
{
    //calcular los factoriales 0 a 10
    for(int i=0;i<=10;i++)
        cout << setw(2) <<i<<"!="<<factorial(i)<<endl;
    return 0;
}
unsigned long factorial(unsigned long n){
    if(n<=1)//caso base
        return 1;
    else
        return n*factorial(n-1);
}
