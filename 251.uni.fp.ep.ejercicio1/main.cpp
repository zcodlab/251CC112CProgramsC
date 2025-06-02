#include <iostream>
using namespace std;

// =======================
// FUNCIONES
// =======================

void crearArray(int*& pArray, int* arreglo) {
    pArray = arreglo;
}

void ReadArray(int* pArray, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        cout << "Ingrese valor[" << i << "]: ";
        cin >> pArray[i];
    }
}

void PrintArray(int* pArray, size_t n) {
    for (size_t i = 0; i < n; ++i)
        cout << pArray[i] << " ";
    cout << endl;
}

void intercambiar(int* a, int* b, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

bool ascendente(const int& a, const int& b) {
    return a < b;
}

bool descendente(const int& a, const int& b) {
    return a > b;
}

void BurbujaRecursivo(int* arr, int n, bool (*pComp)(const int&, const int&)) {
    if (n <= 1)
        return;
    for (int j = 1; j < n; ++j)
        if (pComp(arr[j], arr[0])) {
            int temp = arr[0];
            arr[0] = arr[j];
            arr[j] = temp;
        }
    BurbujaRecursivo(arr + 1, n - 1, pComp);
}

// =======================
// MAIN
// =======================

int main() {
    const size_t size = 5;
    int vec1[size], vec2[size];
    int* pVec1 = nullptr;
    int* pVec2 = nullptr;

    crearArray(pVec1, vec1);
    crearArray(pVec2, vec2);

    cout << "--- Leer vec1 ---\n";
    ReadArray(pVec1, size);
    BurbujaRecursivo(pVec1, size, ascendente);
    cout << "Vec1 ordenado ascendente:\n";
    PrintArray(pVec1, size);

    cout << "--- Leer vec2 ---\n";
    ReadArray(pVec2, size);
    BurbujaRecursivo(pVec2, size, descendente);
    cout << "Vec2 ordenado descendente:\n";
    PrintArray(pVec2, size);

    cout << "--- Intercambio de contenido ---\n";
    intercambiar(pVec1, pVec2, size);

    cout << "Vec1 después del intercambio:\n";
    PrintArray(pVec1, size);

    cout << "Vec2 después del intercambio:\n";
    PrintArray(pVec2, size);

    return 0;
}
