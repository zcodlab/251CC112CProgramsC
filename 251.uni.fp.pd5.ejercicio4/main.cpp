#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int COLUM=3;
const int INC=2;

int contarLineas(const string& filename) {
    ifstream ar(filename);
    int count = 0;
    string linea;
    while (getline(ar, linea))
        count++;

    ar.close();
    return count;
}

string** cargarDatos(const string& filename, int filas) {
    ifstream ar(filename);
    string** base = new string* [filas];
    for (int i = 0; i < filas; i++)
        base[i] = new string[COLUM];

    string apellidos, nombre, nota;
    for (int i = 0; i < filas; i++) {
        getline(ar, apellidos, ',');
        getline(ar, nombre, ',');
        getline(ar, nota);

        // Aumentar nota en 2
        nota = to_string(stoi(nota) + INC);
        if (nota.length() == 1)
            nota = "0" + nota;

        base[i][0] = apellidos;
        base[i][1] = nombre;
        base[i][2] = nota;
    }
    ar.close();
    return base;
}

void ordenarDatos(string** base, int filas) {
    string aux;
    for (int i = 0; i < filas - 1; i++) {
        for (int j = 0; j < filas - 1 - i; j++) {
            if (base[j][0] > base[j + 1][0])
                swap(base[j], base[j + 1]);
            else if (base[j][0] == base[j + 1][0]) {
                if (base[j][1] > base[j + 1][1])
                    swap(base[j], base[j + 1]);
                else if (base[j][1] == base[j + 1][1]) {
                    if (base[j][2] > base[j + 1][2])
                        swap(base[j][2], base[j + 1][2]);
                }
            }
        }
    }
}

void guardarSalida(const string& filename, string** base, int filas) {
    ofstream ar(filename);
    for (int i = 0; i < filas; i++) {
        ar << base[i][0] << "," << base[i][1] << ",";
        if (base[i][2].at(0) == '0')
            base[i][2] = base[i][2].substr(1);  //indica considerar desde el indice 1, ignorando el indice cero(0), ejm: 08->8
        ar << base[i][2] << endl;
    }
    ar.close();
}

void liberarMemoria(string** base, int filas) {
    for (int i = 0; i < filas; i++)
        delete[] base[i];
    delete[] base;
}

int main() {
    const string entrada = "Entrada.csv";
    const string salida = "Salida.csv";

    int totalLineas = contarLineas(entrada);
    if (totalLineas <= 1) {
        //Estándar de error cerr Mensajes de error o advertencia
        cerr << "Archivo vacío o con solo encabezado.\n";
        //return 1; indica un error en la ejecución del programa (por convención, 0 es éxito y != 0 es error).
        return 1;
    }

    int filas = totalLineas - 1; // omitir encabezado si existe
    string** base = cargarDatos(entrada, filas);
    ordenarDatos(base, filas);
    guardarSalida(salida, base, filas);
    liberarMemoria(base, filas);

    return 0;
}
