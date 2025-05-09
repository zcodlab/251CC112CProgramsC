#include <iostream>
using namespace std;
const int MAX = 100;
bool es_impar(int n){
	return ((n % 2) != 0);
}
void imprime_lista(int lista[], int ic, int c, int d){
	int* p = &lista[ic];
	for(int i=0;i<c;i++,p+=d){
		cout<<*p<<"\t";
	}
}
void secuenciaimparmaslarga(int A[],int i0, int n, int& ini_max, int& max){
	int* p;
	int ini;
	p = &A[i0]; // iniciamos la busqueda en el indice i0
	int cont;
	cont=0;
	max=0;
	ini_max=-1;
	for (int i=i0;i<n;i+=2,p+=2){
		if ( es_impar(*p) ){
			if (cont==0) //empieza una cadena de impares
			    ini=i;
			cont++;
			if (cont>max){ //alcanza longitud maxima
			    max=cont;
			    ini_max=ini;
			}
		}
		else { // terminamos la cadena de impares
			cont=0;
		}	}}
void imprime_secuencia_impar(int lista[], int n){
	int a,b,ia,ib,c,ic;
	secuenciaimparmaslarga(lista,0, n, ia,a);
	secuenciaimparmaslarga(lista,1, n, ib,b);
	if (a<b){
		c=b;ic=ib;
	} else {
		c=a;ic=ia;
	}
	if (c>0) {
		imprime_lista(lista,ic,c,2);
	} else {
		cout<<"No existe secuencia impar";
	}
}


int main(){
	int lista1[MAX]={1,2,3,2,2,1,1,3,3,7,5,1,2,3};
	int lista2[MAX]={2,2,2,2,2,2,2,2,2,2,2,2,2,2};
	int n = 14;
	cout<<"Lista 1:\n";
	imprime_lista(lista1,0,n,1);
	cout<<endl;
	cout<<"Secuencia impar mas larga:\n";
	imprime_secuencia_impar(lista1, n);
	cout<<endl;
	cout<<"Lista 2:\n";
	imprime_lista(lista2,0,n,1);
	cout<<endl;
	cout<<"Secuencia impar mas larga:\n";
	imprime_secuencia_impar(lista2, n);
}
