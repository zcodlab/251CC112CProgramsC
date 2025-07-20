#include <iostream>
#include <iomanip>
using namespace std;

// Normaliza una fila: divide cada elemento por la suma de la fila
void normalizarFila(double* fila, int n) {
    if (!fila) {
        cerr << "Error: puntero a fila es nulo. Revisa el paso de argumentos.\n";
        return;
    }

    if (n <= 0) {
        cerr << "Error: tamaño inválido de la fila. Debe ser mayor que cero.\n";
        return;
    }

    double suma = 0.0;
    for (int i = 0; i < n; ++i)
        suma += fila[i];

    if (suma == 0.0) {
        cerr << "Advertencia: la suma de los elementos de la fila es cero. No se puede normalizar.\n";
        return;
    }

    for (int i = 0; i < n; ++i)
        fila[i] /= suma;

}

// Normaliza una columna: divide cada elemento por la suma de la columna
void normalizarColumna(double* matriz, int filas, int columnas, int col) {
    if (!matriz) {
        cerr << "Error: puntero a matriz es nulo. Revisa el paso de argumentos.\n";
        return;
    }

    if (filas <= 0 || columnas <= 0) {
        cerr << "Error: dimensiones inválidas de la matriz. Ambas deben ser mayores que cero.\n";
        return;
    }

    if (col < 0 || col >= columnas) {
        cerr << "Error: índice de columna fuera de rango. Debe estar entre 0 y " << (columnas - 1) << ".\n";
        return;
    }

    double suma = 0.0;
    for (int i = 0; i < filas; ++i)
        suma += *(matriz + i * columnas + col);

    if (suma == 0.0) {
        cerr << "Advertencia: la suma de la columna es cero. No se puede normalizar.\n";
        return;
    }

    for (int i = 0; i < filas; ++i)
        *(matriz + i * columnas + col) /= suma;
}

void imprimirMatriz(double *matriz, int filas, int columnas) {
    cout << fixed << setprecision(2);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j)
            cout << *(matriz + filas*i +j) << "  ";
        cout << endl;
    }
}

int main() {
    const int filas = 3, columnas = 3;

    double matriz[filas][columnas] = {
        {1.0, 1.0, 1.0},
        {2.0, 3.0, 5.0},
        {0.0, 1.0, 2.0}
    };

    cout <<"\nMatriz original:\n";
    imprimirMatriz(&matriz[0][0], filas, columnas);

    normalizarFila(matriz[1], columnas);

    normalizarColumna(&matriz[0][0], filas, columnas, 2);

    cout <<"\nMatriz resultante:\n";
    imprimirMatriz(&matriz[0][0], filas, columnas);

    return 0;
}
