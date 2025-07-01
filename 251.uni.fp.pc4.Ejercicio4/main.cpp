#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Alumno {
    int codigo;
    char nombre[30];
    float nota;
};

// Función para ingresar registros
void ingresarAlumnos(const char* nombreArchivo, int n) {
    ofstream archivo(nombreArchivo, ios::binary | ios::out);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para escritura."<<endl;
        return;
    }

    Alumno a;
    for (int i = 0; i < n; ++i) {
        cout << "Alumno " << i + 1 << ":"<<endl;
        cout << "Codigo: "; cin >> a.codigo;
        cout << "Nombre: "; cin >> a.nombre;
        cout << "Nota: "; cin >> a.nota;
        archivo.write(reinterpret_cast<char*>(&a), sizeof(Alumno));
    }

    archivo.close();
}

// Función para ordenar los registros en el archivo por nota descendente
void ordenarPorNota(const char* nombreArchivo) {
    fstream archivo(nombreArchivo, ios::in | ios::out | ios::binary);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para ordenar."<<endl;
        return;
    }

    archivo.seekg(0, ios::end);
    int totalRegistros = archivo.tellg() / sizeof(Alumno);

    Alumno a1, a2;

    for (int i = 0; i < totalRegistros - 1; ++i) {
        for (int j = i + 1; j < totalRegistros; ++j) {
            archivo.seekg(i * sizeof(Alumno));
            archivo.read(reinterpret_cast<char*>(&a1), sizeof(Alumno));

            archivo.seekg(j * sizeof(Alumno));
            archivo.read(reinterpret_cast<char*>(&a2), sizeof(Alumno));

            if (a2.nota > a1.nota) {
                archivo.seekp(i * sizeof(Alumno));
                archivo.write(reinterpret_cast<char*>(&a2), sizeof(Alumno));

                archivo.seekp(j * sizeof(Alumno));
                archivo.write(reinterpret_cast<char*>(&a1), sizeof(Alumno));
            }
        }
    }

    archivo.close();
}

// Función para mostrar los registros
void mostrarAlumnos(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para lectura." << endl;
        return;
    }

    Alumno a;
    cout << endl << "Listado de estudiantes ordenados por nota:" << endl;
    cout << fixed << setprecision(1);  // Formato de 1 decimal para notas

    while (archivo.read(reinterpret_cast<char*>(&a), sizeof(Alumno))) {
        cout << "Codigo: " << a.codigo
             << " - Nombre: " << a.nombre
             << " - Nota: " << a.nota << endl;
    }

    archivo.close();
}

int main() {
    const char* nombreArchivo = "alumnos.dat";
    int n;

    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    ingresarAlumnos(nombreArchivo, n);
    ordenarPorNota(nombreArchivo);
    mostrarAlumnos(nombreArchivo);

    return 0;
}
