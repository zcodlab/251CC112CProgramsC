#include <iostream>
using namespace std;

// =========================
// Configuración de límites
// =========================
const int VALOR_MIN = 1;
const int VALOR_MAX = 5;
const int RANGO = VALOR_MAX - VALOR_MIN + 1;

// =========================
// Funciones
// =========================

// Crear arreglo dinámico
int* crearArreglo(int n) {
    return new int[n];
}

// Leer respuestas del usuario
void leerRespuestas(int* arr, int n) {
    cout << "Ingrese las respuestas (valores entre "<< VALOR_MIN << " y " << VALOR_MAX << "): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        while (arr[i] < VALOR_MIN || arr[i] > VALOR_MAX) {
            cout << "Valor inválido. Ingrese un número entre "<< VALOR_MIN << " y " << VALOR_MAX << ": ";
            cin >> arr[i];
        }
    }
}

// Calcular promedio
float calcularPromedio(int* arr, int n) {
    int suma = 0;
    for (int i = 0; i < n; ++i)
        suma += arr[i];
    return (1.0 * suma) / n;
}

// Mostrar frecuencias
void mostrarFrecuencias(int* arr, int n) {
    int frec[RANGO] = {0};  // Indices de 0 a RANGO-1

    for (int i = 0; i < n; ++i)
        frec[arr[i] - VALOR_MIN]++;

    cout << "Frecuencia de respuestas:"<<endl;
    for (int i = 0; i < RANGO; ++i)
        cout << (VALOR_MIN + i) << ": " << frec[i] << endl;
}

// Calcular moda
int calcularModa(int* arr, int n) {
    int frec[RANGO] = {0};
    for (int i = 0; i < n; ++i)
        frec[arr[i] - VALOR_MIN]++;

    int moda = VALOR_MIN;
    int maxFrec = frec[0];
    for (int i = 1; i < RANGO; ++i) {
        if (frec[i] > maxFrec) {
            maxFrec = frec[i];
            moda = VALOR_MIN + i;
        }
    }
    return moda;
}

// Liberar memoria
void destruirArreglo(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

// =========================
// Funcion Principal Main
// =========================

int main() {
    int n;
    cout << "Ingrese la cantidad de respuestas: ";
    cin >> n;

    if (n <= 0) {
        cout << "Cantidad invalida."<<endl;
        return 1;
    }

    int* respuestas = crearArreglo(n);
    leerRespuestas(respuestas, n);

    float promedio = calcularPromedio(respuestas, n);
    cout << "Promedio de satisfaccion: " << promedio << endl;

    mostrarFrecuencias(respuestas, n);

    int moda = calcularModa(respuestas, n);
    cout << "Moda: " << moda << endl;

    destruirArreglo(respuestas);

    return 0;
}
