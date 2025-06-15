/*
Ejemplo: Acceso aleatorio a registros de empleados
Supongamos que tienes una estructura de empleados con un ID fijo, nombre y sueldo, y quieres:
Guardar varios registros en un archivo.
Leer o escribir un registro en una posición específica (por índice).
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const char NOMBRE_ARCHIVO[] = "empleados.dat";
const int MAX_NOMBRE = 30;

struct Empleado {
    int id;
    char nombre[MAX_NOMBRE];
    float sueldo;
};

// Escribe un registro en la posición 'pos' (índice 0 basado)
void escribirEmpleado(int pos, const Empleado& emp) {
    //abre un archivo binario con acceso de lectura y escritura: ios::in | ios::out | ios::binary	trata el archivo como binario
    fstream archivo(NOMBRE_ARCHIVO, ios::in | ios::out | ios::binary);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo para escritura."<<endl;
        return;
    }
    //seekp() → mueve el puntero de escritura a una posición específica
    archivo.seekp(pos * sizeof(Empleado), ios::beg);
    //Escribe todos los bytes de la estructura emp en el archivo binario
    archivo.write(reinterpret_cast<const char*>(&emp), sizeof(Empleado));
    archivo.close();
}

// Lee un registro desde la posición 'pos'
Empleado leerEmpleado(int pos) {
    Empleado emp{}; //crea una variable emp de tipo Empleado e inicializa todos sus campos
    ifstream archivo(NOMBRE_ARCHIVO, ios::binary);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo para lectura."<<endl;
        return emp;
    }
    // seekg() → mueve el puntero de lectura a una posicion especifica.
    archivo.seekg(pos * sizeof(Empleado), ios::beg);    //ios::beg: empieza desde el inicio del archivo (beginning).
    //se utiliza para leer datos binarios desde un archivo y almacenarlos directamente en la estructura emp.
    archivo.read(reinterpret_cast<char*>(&emp), sizeof(Empleado));
    archivo.close();
    return emp;
}

int main() {
    // Guardamos 3 empleados en posiciones especificas
    Empleado e1 = {1, "Ana Torres", 2800.0f};
    Empleado e2 = {2, "Luis Pérez", 3000.0f};
    Empleado e3 = {3, "Marta Rojas", 2700.0f};

    escribirEmpleado(0, e1);
    escribirEmpleado(1, e2);
    escribirEmpleado(2, e3);

    //Como ejemplo, leemos directamente al empleado en la posición 1 (Luis)
    Empleado leido = leerEmpleado(1);
    cout << "Empleado leido (posicion 1):"<<endl;
    cout << "ID: " << leido.id << endl<<"Nombre: " << leido.nombre << endl<<"Sueldo: " << leido.sueldo << endl;
    return 0;
}
