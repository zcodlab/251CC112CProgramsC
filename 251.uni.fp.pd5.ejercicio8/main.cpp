#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

// -------------------- DECLARACIÓN DE FUNCIONES --------------------
bool abrirArchivos(ifstream &entrada, ofstream &salida,
                   const string &archivoEntrada, const string &archivoSalida);
void leerDatos(ifstream &entrada, int &nv, int &nt, float **&V, int **&T);
float calcularArea(int nv, int nt, float **V, int **T);
void liberarMemoria(float **V, int nv, int **T, int nt);

// -------------------- FUNCIÓN VRINCIVAL --------------------
int main() {
    const string archivoEntrada = "laguna.txt";
    const string archivoSalida = "area.txt";

    ifstream entrada;
    ofstream salida;

    if (!abrirArchivos(entrada, salida, archivoEntrada, archivoSalida)) {
        return EXIT_FAILURE;
    }

    int nv, nt;
    float **V = nullptr;
    int **T = nullptr;

    leerDatos(entrada, nv, nt, V, T);
    float areaTotal = calcularArea(nv, nt, V, T);
    salida << areaTotal << endl;
    entrada.close();
    salida.close();
    liberarMemoria(V, nv, T, nt);
    return 0;
}

// -------------------- DEFINICIONES DE FUNCIONES --------------------

bool abrirArchivos(ifstream &entrada, ofstream &salida,
                   const string &archivoEntrada, const string &archivoSalida) {
    entrada.open(archivoEntrada, ios::in);
    if (!entrada.good()) {
        cout << "Error al abrir archivo de entrada: " << archivoEntrada << endl;
        return false;
    }

    salida.open(archivoSalida, ios::out);
    if (!salida.good()) {
        cout << "Error al abrir archivo de salida: " << archivoSalida << endl;
        entrada.close(); // cerramos el que sí abrió
        return false;
    }

    return true;
}

void leerDatos(ifstream &entrada, int &nv, int &nt, float **&V, int **&T) {
    entrada >> nt >> nv;

    V = new float*[nv];
    for (int i = 0; i < nv; ++i) {
        V[i] = new float[2];
    }

    T = new int*[nt];
    for (int i = 0; i < nt; ++i) {
        T[i] = new int[3];
    }

    for (int i = 0; i < nv; ++i) {
        entrada >> V[i][0] >> V[i][1];
    }

    for (int i = 0; i < nt; ++i) {
        entrada >> T[i][0] >> T[i][1] >> T[i][2];
    }
}

float calcularArea(int nv, int nt, float **V, int **T) {
    float area = 0.0;

    for (int i = 0; i < nt; ++i) {
        int a = T[i][0] - 1;
        int b = T[i][1] - 1;
        int c = T[i][2] - 1;

        float x1 = V[a][0], y1 = V[a][1];
        float x2 = V[b][0], y2 = V[b][1];
        float x3 = V[c][0], y3 = V[c][1];

        area += 0.5f * abs(x1*(y3 - y2) + x2*(y1 - y3) + x3*(y2 - y1));
    }

    return area;
}

void liberarMemoria(float **V, int nv, int **T, int nt) {
    for (int i = 0; i < nv; ++i) {
        delete[] V[i];
    }
    delete[] V;

    for (int i = 0; i < nt; ++i) {
        delete[] T[i];
    }
    delete[] T;
}
