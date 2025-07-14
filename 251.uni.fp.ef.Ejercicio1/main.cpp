#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double EPSILON = 1e-9;
// Crear matriz dinamica
double** crearMatriz(int filas, int columnas) {
    double** matriz = new double*[filas];
    for (int i = 0; i < filas; ++i)
        matriz[i] = new double[columnas];
    return matriz;
}
// Liberar memoria
void liberarMatriz(double** matriz, int filas) {
    for (int i = 0; i < filas; ++i)
        delete[] matriz[i];
    delete[] matriz;
}
// Mostrar matriz
void mostrarMatriz(double** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j)
            cout << setw(8) << fixed << setprecision(2) << matriz[i][j] << " ";
        cout << endl;
    }
}
// Reduccion Gaussiana (sin intercambio de filas)
int reduccionGaussSinPivoteo(double** A, int filas, int columnas) {
    int filaPivote = 0;
    for (int col = 0; col < columnas && filaPivote < filas; ++col) {
        // Si el pivote es cero, no se puede hacer eliminacion en esta columna
        if (fabs(A[filaPivote][col]) < EPSILON)
            continue;  // saltar esta columna

        // Eliminar los valores debajo del pivote
        for (int i = filaPivote + 1; i < filas; ++i) {
            double factor = A[i][col] / A[filaPivote][col];
            for (int j = col; j < columnas; ++j) {
                A[i][j] -= factor * A[filaPivote][j];
                if (fabs(A[i][j]) < EPSILON) A[i][j] = 0.0;
            }
        }
        filaPivote++;  // avanzar solo si hubo un pivote valido
    }

    // Calcular el rango: contar filas no nulas
    int rango = 0;
    for (int i = 0; i < filas; ++i) {
        bool filaNoNula = false;
        for (int j = 0; j < columnas; ++j) {
            if (fabs(A[i][j]) > EPSILON) {
                filaNoNula = true;
                break;
            }
        }
        if (filaNoNula) rango++;
    }
    return rango;
}

int main() {
    int filas, columnas;
    cout << "Ingrese el numero de filas y columnas: ";
    cin >> filas >> columnas;

    double** matriz = crearMatriz(filas, columnas);

    cout <<endl<<"Ingrese los elementos de la matriz:"<<endl;
    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j)
            cin >> matriz[i][j];

    cout <<endl<<"Matriz original:"<<endl;
    mostrarMatriz(matriz, filas, columnas);

    int rango = reduccionGaussSinPivoteo(matriz, filas, columnas);

    cout <<endl<<"Matriz en forma escalonada (sin intercambio de filas):"<<endl;
    mostrarMatriz(matriz, filas, columnas);

    cout <<endl<<"Rango de la matriz: " << rango << endl;
    liberarMatriz(matriz, filas);
    return 0;
}
