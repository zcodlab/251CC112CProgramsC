#include <iostream>
using namespace std;

void invertirArray(int *arr,int inicio,int fin){
    while(inicio<fin){
            int temp=*(arr+inicio);
            *(arr+inicio)=*(arr+fin);
            *(arr+fin)=temp;
            inicio++;
            fin--;
    }
}

void rotacionDerecha(int *arr,int n,int k){
    k=k%n;
    invertirArray(arr,0,n-1);
    invertirArray(arr,0,k-1);
    invertirArray(arr,k,n-1);
}

void rotacionIzquierda(int *arr,int n,int k){
    k=k%n;
    invertirArray(arr,0,n-1);
    invertirArray(arr,0,n-k-1);
    invertirArray(arr,n-k,n-1);
}
void  imprimirArray(int *arr,int n){
      for(int i=0;i<n;i++)
        cout<<*(arr+i)<<" ";
      cout<<endl;
}

int main()
{
    int arr[100], n, k;
    string direccion;

    cout << "Ingrese el tamaño del arreglo(max 100)" << endl;
    cin>>n;

    cout<<"Ingrese "<<n<<" elementos"<<endl;
    for(int i=0;i<n;i++)
        cin>>*(arr+i);

    cout<<"Ingrese el valor de k (numero de posiciones a rotar):"<<endl;
    cin>>k;

    cout<<"¿Desea rotar a la derecha o izquierda?:"<<endl;
    cin>>direccion;

    if(direccion=="derecha"){
            rotacionDerecha(arr,n,k);
            cout<<"Arreglo rotado a la derecha"<<endl;
            imprimirArray(arr,n);
    }else if(direccion=="izquierda"){
            rotacionIzquierda(arr,n,k);
            cout<<"Arreglo rotado a la izquierda"<<endl;
            imprimirArray(arr,n);
    }else
            cout<<"Direccion invalida"<<endl;

    return 0;
}
