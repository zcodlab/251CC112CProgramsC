#include <iostream>
#include <string>
using namespace std;
unsigned int strlen(const char *p){
    int i=0;
    while(*(p+i)!='\0')
        i++;
    return i;
}
void rev(char *a){
    int n=strlen(a);
    for(auto i=0;i<n/2;i++)//auto especifica un unsigned int
        swap(*(a+i),*(a+n-i-1));

}
int main()
{   char a[10]={};
    cout << "Ingrese la palabra a invertir:" << endl;
    cin>>a;
    rev(a);
    cout << "La palabra invertida es:" << endl;
    for(auto i:a)//auto infiere que i es un char, por la variable a
        cout<<i;
    return 0;
}
