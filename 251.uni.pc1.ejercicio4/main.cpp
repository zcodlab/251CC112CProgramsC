#include <iostream>
using namespace std;
int es_posible_grupo(int A[], int k,int n, int max_viaje){
	int cont = 1;//cont es el numero de grupos posibles
	int sum = 0;
	for (int i=0;i<k;i++){
		int distancia = A[i];
		if ( distancia > max_viaje)
			return 0; // imposible, un pedido excede el límite
		if (sum + distancia > max_viaje){
			cont++;// termina un grupo y abre uno nuevo
			sum = distancia;
		} else { // continua acumulando en el grupo
			sum += distancia;
		}
	}
	return (cont <= n);
}
void mostrar_grupo_minimo(int A[], int k,int n, int max_viaje){
	int cont = 1;//cont es el numero de grupos posibles
	int sum = 0;
	cout<<"Grupo 1:\n";
	for (int i=0;i<k;i++){
		int distancia = A[i];
		if (sum + distancia > max_viaje){
			cont++;// termina un grupo y abre uno nuevo
			cout<<"\nGrupo "<<cont<<":\n";
			sum = distancia;
		} else { // continua acumulando en el grupo
			sum += distancia;
		}
		cout<<distancia<<"\t";

	}
}
int max_vector(int A[], int k){
	int max = A[0];
	for (int i=1;i<k;i++){
		if (max<A[i]) max=A[i];
	}
	return max;
}
int suma_vector(int A[], int k){
	int suma = A[0];
	for (int i=1;i<k;i++){
		suma+=A[i];
	}
	return suma;
}
int reparto_minimo(int A[], int k,int n){
	int menor_viaje = max_vector(A,k);  // un paquete en un grupo
	int mayor_viaje = suma_vector(A,k);  // todos los paquetes en un grupo
	int resultado = mayor_viaje;
	while (menor_viaje <= mayor_viaje){
		int max_viaje = (menor_viaje + mayor_viaje)/2;
		if (es_posible_grupo(A, k, n, max_viaje)){
			resultado = max_viaje;
			mayor_viaje = max_viaje - 1;// intentar con una menor distancia
		} else {
			menor_viaje = max_viaje + 1;  // intentar con una mayor distacia
		}
	}
	return resultado;
}
int main(int argc, char *argv[]) {
	int A[] = {7, 2, 5, 10, 8};
	int k = 5;
	int n = 2;
	int dmax = reparto_minimo(A, k, n);
	mostrar_grupo_minimo(A,k, n, dmax);
	cout<<"\nLa menor distancia maxima es "<<dmax<<endl;
}
