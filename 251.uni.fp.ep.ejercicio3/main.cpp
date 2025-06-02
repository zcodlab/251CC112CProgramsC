#include <iostream>
using namespace std;

const int MAX = 100;

//dfs:depth first search
void dfs(int** mapa, bool visitado[MAX][MAX], int filas, int columnas, int i, int j) {
    if (i < 0 || i >= filas || j < 0 || j >= columnas) return;
    if (visitado[i][j] || mapa[i][j] == 1) return;

    visitado[i][j] = true;

    // Recorrer en 4 direcciones
    dfs(mapa, visitado, filas, columnas, i - 1, j); // arriba
    dfs(mapa, visitado, filas, columnas, i + 1, j); // abajo
    dfs(mapa, visitado, filas, columnas, i, j - 1); // izquierda
    dfs(mapa, visitado, filas, columnas, i, j + 1); // derecha
}

int contarRegionesConexas(int** mapa, int filas, int columnas) {
    bool visitado[MAX][MAX] = {false};
    int regiones = 0;

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (!visitado[i][j] && mapa[i][j] == 0) {
                dfs(mapa, visitado, filas, columnas, i, j);
                regiones++;
            }
        }
    }

    return regiones;
}

void mostrarMapa(int** mapa, int filas, int columnas) {
    cout << "\nMapa ingresado:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mapa[MAX][MAX];
    int* ptrFilas[MAX];  // Arreglo de punteros a filas
    int** ptrMapa = ptrFilas;

    int filas, columnas;

    cout << "Ingrese el número de filas y columnas (máximo " << MAX << "): ";
    cin >> filas >> columnas;

    if (filas > MAX || columnas > MAX || filas <= 0 || columnas <= 0) {
        cout << "Dimensiones inválidas." << endl;
        return 1;
    }

    // Inicializar el puntero doble para apuntar a las filas del arreglo estático
    for (int i = 0; i < filas; ++i) {
        ptrMapa[i] = mapa[i];
    }

    // Ingreso de datos
    cout << "Ingrese los valores del mapa (0 = camino, 1 = obstáculo):\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cin >> ptrMapa[i][j];
        }
    }

    mostrarMapa(ptrMapa, filas, columnas);

    int regiones = contarRegionesConexas(ptrMapa, filas, columnas);
    cout << "Número de regiones transitables conectadas: " << regiones << endl;

    return 0;
}
