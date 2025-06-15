/*
9.	Caso de Registro de Estudiantes en archivo binario
*/
#include <iostream>
#include <fstream>
using namespace std;
const int N=50;

struct Estudiante {
    int id;
    char nombre[N]; //No use string dentro de estructuras para binarios, ya que su contenido no se guarda correctamente.
    float promedio;
};

void escribirEstudiante(const string& archivo, const Estudiante& e) {
    //ios::binary	Abre el archivo en modo binario, no en modo texto.
    //ios::app	Abre el archivo para anexar (append): los nuevos datos se escriben al final, sin sobrescribir los anteriores.
    ofstream salida(archivo, ios::binary | ios::app);
    if (!salida) {
        cerr << "Error al abrir el archivo para escritura"<<endl;
        return;
    }
    //write() para escribir bloques de memoria completos (no como texto).
    //write(const char* s, streamsize n);puntero a un Estudiante lo convertimos a const char*.
    //reinterpret_cast es un operador de conversión en C++ que permite convertir un puntero (o referencia) de un tipo a otro
    salida.write(reinterpret_cast<const char*>(&e), sizeof(Estudiante));
    //Usa read() para leer bloques de memoria completos (no como texto).
    salida.close();
}

void leerEstudiantes(const string& archivo) {
    ifstream entrada(archivo, ios::binary);
    if (!entrada) {
        cerr << "Error al abrir el archivo para lectura"<<endl;
        return;
    }

    Estudiante e;
    cout << "Lista de estudiantes"<<endl;
    while (entrada.read(reinterpret_cast<char*>(&e), sizeof(Estudiante)))
        cout << "ID: " << e.id<< " | Nombre: " << e.nombre<< " | Promedio: " << e.promedio <<endl;

    entrada.close();
}

int main() {
    string archivo = "estudiantes.dat"; //nombre del archivo de salida

    // Agregar estudiantes
    Estudiante e1 = {1, "Ana Torres", 17.8f};
    Estudiante e2 = {2, "Luis Gomez", 15.3f};
    Estudiante e3 = {3, "Valeria Cruz", 19.0f};

    escribirEstudiante(archivo, e1);
    escribirEstudiante(archivo, e2);
    escribirEstudiante(archivo, e3);

    // Leer estudiantes
    leerEstudiantes(archivo);

    return 0;
}
