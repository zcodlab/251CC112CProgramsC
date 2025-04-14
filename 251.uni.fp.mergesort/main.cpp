#include <iostream>
using namespace std;

const int MAX = 100;

// Función para mezclar dos subarreglo ordenados
void merge(int X[], int left, int mid, int right) {
    int n1 = mid - left + 1;    // Tamaño del subarreglo izquierdo
    int n2 = right - mid;       // Tamaño del subarreglo derecho

    // Arreglos temporales
    int L[MAX], R[MAX];

    // Copiar datos a los Arreglos temporales
    for (int i = 0; i < n1; i++)
        L[i] = X[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = X[mid + 1 + j];

    // Combinar los subarreglos
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            X[k++] = L[i++];
        else
            X[k++] = R[j++];
    }

    // Copiar elementos restantes de L (si hay)
    while (i < n1)
        X[k++] = L[i++];

    // Copiar elementos restantes de R (si hay)
    while (j < n2)
        X[k++] = R[j++];
}

// Función principal de Merge Sort
void mergeSort(int X[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        // Ordenar primera mitad
        mergeSort(X, left, mid);
        // Ordenar segunda mitad
        mergeSort(X, mid + 1, right);
        // Fusionar ambas mitades ordenadas
        merge(X, left, mid, right);
    }
}

// Función para imprimir el Arreglo
void imprimirarreglo(int X[], int n) {
    for (int i = 0; i < n; i++)
        cout << X[i] << " ";
    cout << endl;
}

// Programa principal
int main() {
    int X[MAX];
    int n;

    cout << "Ingrese cantidad de elementos: ";
    cin >> n;

    cout << "Ingrese los elementos:\n";
    for (int i = 0; i < n; i++)
        cin >> X[i];

    mergeSort(X, 0, n - 1);

    cout << "Arreglo ordenado:\n";
    imprimirarreglo(X, n);

    return 0;
}
