#include <iostream>
#include <ctime> //para rand()
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1])
                    swap(arr[j], arr[j+1]);
        }
    }
}

int main() {
    int arr[100];
    int n, k;
    cout << "Ingrese la longitud n del arreglo: ";
    cin >> n;
    //generar el arreglo aleatoriamente
    srand(time(NULL)); //semilla aleatoria
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100; //generar número aleatorio entre 0 y 99
    }

    cout << "Arreglo original: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Ingrese la posición k: ";
    cin >> k;
    bubbleSort(arr, n);
    cout << "Arreglo ordenado: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "El elemento en la posición " << k << " es: " << arr[k-1] << endl;
    return 0;
}
