#include <iostream>
using namespace std;

string unir(string E1, string E2){
        string s=E1;
        for(int i=0; i<E2.length();i++){
            if(E1.find(E2.at(i))  > E2.length())
                s=s+E2.at(i);
        }
        return s;
}
string resta(string U, string E3){
    string s="";
    for(int i=0;i<U.length();i++){
            if(E3.find(U.at(i)) > E3.length())
                    s=s+U.at(i);
    }
    return s;
}

int main()
{
    string U,R;
    string E1="ABCDEFG";
    string E2="ABCDHIJ";
    string E3="BCGHJKL";
    U=unir(E1,E2);
    R=resta(U,E3);
    cout << "Los proveedores seleccionados serian:" <<R<< endl;
    return 0;
}
