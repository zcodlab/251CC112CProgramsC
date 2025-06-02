#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 10;

void leerMatriz(double** A, int n);
void ObtenerMenor(double** A, double** M, int n, int filaEliminar, int colEliminar);
double Determinante(double** A, int n);

int main() {
    double Arr[MAX][MAX];
    int n;

    cout << "Ingrese el tama?o de la matriz (máximo " << MAX << "): ";
    cin >> n;
    double* A[MAX];
    for (int i = 0; i < n; ++i)
        A[i] = Arr[i];


    cout << "Ingrese los elementos de la matriz: " << endl;
    leerMatriz(A, n);


    double det = Determinante(A, n);
    cout << "\nDeterminante = " << det << endl;

    return 0;
}


void leerMatriz(double** A, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> *(*(A + i) + j);
}


void ObtenerMenor(double** A, double** M, int n, int filaEliminar, int colEliminar) {
    int fila = 0;
    for (int i = 0; i < n; ++i) {
        if (i != filaEliminar) {
            int col = 0;
            for (int j = 0; j < n; ++j) {
                if (j != colEliminar) {;
                    *(*(M + fila) + col) = *(*(A + i) + j);
                    ++col;
                }
            }
            ++fila;
        }
    }
}



double Determinante(double** A, int n) {
    if (n == 1)
        return *(*A);

    if (n == 2)
        return *(*A) * *(*(A + 1) + 1) - *(*A + 1) * *(*(A + 1));

    int mejorFila = 0;
    int maxCeros = -1;
    bool filaCero = false;

    for (int i = 0; i < n; ++i) {
        int ceros = 0;
        for (int j = 0; j < n; ++j)
            if (*(*(A + i) + j) == 0.0)
                ceros++;

        if (ceros == n) {
            filaCero = true;
            break;
        }

        if (ceros > maxCeros) {
            maxCeros = ceros;
            mejorFila = i;
        }
    }

    if (filaCero)
        return 0.0;

    double det = 0.0;
    double mArray[MAX][MAX];

    double* M[MAX];
    for (int i = 0; i < MAX; ++i)
        M[i] = mArray[i];

    for (int col = 0; col < n; ++col) {
        double val = *(*(A + mejorFila) + col);
        if (val != 0.0) {
            ObtenerMenor(A, M, n, mejorFila, col);
            det += pow(-1,mejorFila + col)* val * Determinante(M, n - 1);
        }
    }

    return det;
}


