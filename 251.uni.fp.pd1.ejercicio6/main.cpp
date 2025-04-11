#include <iostream>
#include <vector>
using namespace std;
vector<int> encuentraKElementosCercanos(vector<int> &entrada,int objetivo,int k){
    int i=lower_bound(entrada.begin(),entrada.end(),objetivo) - entrada.begin();
    cout<<i<<endl;
    int izq=i-1;
    int der=i;
    while(k-- >0){
            if(izq<0 || (der<entrada.size() && abs(entrada[izq]-objetivo) > abs(entrada[der]-objetivo)))
                der++;
            else
                izq--;
    }
    return vector<int> (entrada.begin()+izq+1,entrada.begin()+der);
}

int main()
{
    //vector<int> entrada={10,12,15,17,18,20,25};
    //int objetivo=16,k=4;
    vector<int> entrada={2,3,4,5,6,7};
    int objetivo=1,k=3;
    vector<int> result=encuentraKElementosCercanos(entrada,objetivo,k);

    cout << "imprimir resultado: " << endl;
    for(int i:result)
        cout<<i<<", ";

    return 0;
}
