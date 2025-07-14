#include <iostream>
#include <string>
using namespace std;

// Estructura para representar una evaluacion
struct Evaluacion {
    string idEvaluacion;                    // Ej: "PC1", "EF"
    string nombreEvaluacion;        // Ej: "1° Practica Calificada"
    float calificacion;                     // Nota obtenida
    Evaluacion* siguiente;          // Puntero al siguiente nodo
};

// Puntero al inicio de la lista
Evaluacion* cabeza = nullptr;

// Funcion para registrar una evaluacion al inicio
void registrarEvaluacion(const string& id, const string& nombre, float nota) {
    Evaluacion* nueva = new Evaluacion;
    nueva->idEvaluacion = id;
    nueva->nombreEvaluacion = nombre;
    nueva->calificacion = nota;
    nueva->siguiente = cabeza;
    cabeza = nueva;
}

// Funcion para mostrar todas las evaluaciones
void mostrarEvaluaciones() {
    if (cabeza == nullptr) {
        cout << "No hay evaluaciones registradas." << endl;
        return;
    }

    cout << endl << "Evaluaciones registradas (de la mas reciente a la mas antigua):" << endl;
    Evaluacion* actual = cabeza;
    while (actual != nullptr) {
        cout << "ID: " << actual->idEvaluacion
             << " | Nombre: " << actual->nombreEvaluacion
             << " | Nota: " << actual->calificacion << endl;
        actual = actual->siguiente;
    }
}

// Elimina la primera evaluacion que tenga el ID especificado
bool eliminarEvaluacion(const string& id) {
    Evaluacion* actual = cabeza;
    Evaluacion* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->idEvaluacion == id) {
            if (anterior == nullptr) {
                cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return false;
}

// Libera memoria dinamica
void liberarEvaluaciones() {
    while (cabeza != nullptr) {
        Evaluacion* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

// Programa principal para probar
int main() {
    registrarEvaluacion("PE", "Prueba de Entrada", 12.5);
    registrarEvaluacion("PC1", "1° Practica Calificada", 15.0);
    registrarEvaluacion("PC2", "2° Practica Calificada", 14.2);
    registrarEvaluacion("EP", "Examen Parcial", 13.0);
    registrarEvaluacion("EF", "Examen Final", 17.3);

    mostrarEvaluaciones();

    cout << endl << "Eliminando evaluacion con ID 'PC1'..." << endl;
    if (eliminarEvaluacion("PC1")) {
        cout << "Evaluacion eliminada correctamente." << endl;
    } else {
        cout << "No se encontro la evaluacion." << endl;
    }
    mostrarEvaluaciones();
    liberarEvaluaciones();
    return 0;
}
