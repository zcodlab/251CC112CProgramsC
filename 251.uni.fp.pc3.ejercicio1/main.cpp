#include <iostream>
#include <string>
#include <iomanip> // Necesario para setw y setfill

using namespace std;
const int N=3;              //tamaño inicial del arreglo dinamico

struct EntradaHistorial {
    int id;
    string url;
    string titulo;
    string fecha;
    string hora;
};

// Prototipos
void mostrarMenu(EntradaHistorial*& historial, int& totalEntradas, int& capacidad);
void agregarEntrada(EntradaHistorial*& historial, int& totalEntradas, int& capacidad);
void mostrarHistorial(const EntradaHistorial* historial, int totalEntradas);
void eliminarEntrada(EntradaHistorial*& historial, int& totalEntradas, int id);
void buscarPorURL(const EntradaHistorial* historial, int totalEntradas, const string& url);
void limpiarHistorial(EntradaHistorial*& historial, int& totalEntradas, int& capacidad);

// Función principal
int main() {
    int capacidad=N;
    EntradaHistorial* historial = new EntradaHistorial[capacidad];
    int totalEntradas = 0;
    mostrarMenu(historial, totalEntradas, capacidad);

    delete[] historial;
    return 0;
}

// Muestra el menu principal
void mostrarMenu(EntradaHistorial*& historial, int& totalEntradas, int& capacidad) {
    int opcion;
    do {
        cout << "HISTORIAL DE NAVEGACION WEB"<<endl;
        cout << "1. Agregar entrada al historial"<<endl;
        cout << "2. Mostrar historial completo"<<endl;
        cout << "3. Eliminar una entrada por ID"<<endl;
        cout << "4. Buscar visitas por URL"<<endl;
        cout << "5. Limpiar historial completo"<<endl;
        cout << "0. Salir"<<endl;
        cout << "Opción:"<<endl;
        cin >> opcion;

        switch (opcion) {
            case 1: agregarEntrada(historial, totalEntradas, capacidad); break;
            case 2: mostrarHistorial(historial, totalEntradas); break;
            case 3: {
                int id;
                cout << "Ingrese el ID a eliminar: ";
                cin >> id;
                eliminarEntrada(historial, totalEntradas, id);
                break;
            }
            case 4: {
                string url;
                cin.ignore();
                cout << "Ingrese URL a buscar: ";
                getline(cin, url);
                buscarPorURL(historial, totalEntradas, url);
                break;
            }
            case 5: limpiarHistorial(historial, totalEntradas, capacidad); break;
            case 0: cout << "Finalizando"<<endl; break;
            default: cout << "Opcion invalida"<<endl;
        }
    } while (opcion != 0);
}

// Agrega una nueva entrada
void agregarEntrada(EntradaHistorial*& historial, int& totalEntradas, int& capacidad) {
    if (totalEntradas >= capacidad) {
        capacidad *= capacidad;
        EntradaHistorial* nuevo = new EntradaHistorial[capacidad];
        for (int i = 0; i < totalEntradas; ++i)
            nuevo[i] = historial[i];
        delete[] historial;
        historial = nuevo;
    }

    EntradaHistorial& e = historial[totalEntradas];
    e.id = totalEntradas + 1;

    cin.ignore();
    cout << "Ingrese la URL: ";
    getline(cin, e.url);
    cout << "Titulo de la pagina: ";
    getline(cin, e.titulo);
    cout << "Fecha (dd/mm/aaaa): ";
    getline(cin, e.fecha);
    cout << "Hora (hh:mm): ";
    getline(cin, e.hora);
    totalEntradas++;
}

// Mostrar historial
void mostrarHistorial(const EntradaHistorial* historial, int totalEntradas) {
    if (totalEntradas == 0) {
        cout << "--- Historial vacio ---"<<endl;
        return;
    }

    cout << "--- Historial de navegacion ---"<<endl;
    for (int i = 0; i < totalEntradas; ++i) {
        const EntradaHistorial& e = historial[i];
        cout << "ID: " << e.id<< " | URL: " << e.url<< " | Titulo: " << e.titulo<< " | Fecha y hora: "<<e.fecha<<" "<<e.hora<< endl;
    }
}

// Eliminar una entrada por ID
void eliminarEntrada(EntradaHistorial*& historial, int& totalEntradas, int id) {
    bool encontrado = false;
    for (int i = 0; i < totalEntradas; ++i) {
        if (historial[i].id == id) {
            for (int j = i; j < totalEntradas - 1; ++j)
                historial[j] = historial[j + 1];
            totalEntradas--;
            encontrado = true;
            cout << ">> Entrada eliminada exitosamente.\n";
            break;
        }
    }
    if (!encontrado)
        cout << ">> ID no encontrado.\n";
}

// Buscar por URL
void buscarPorURL(const EntradaHistorial* historial, int totalEntradas, const string& url) {
    bool encontrado = false;
    for (int i = 0; i < totalEntradas; ++i) {
        if (historial[i].url == url) {
            const EntradaHistorial& e = historial[i];
            cout << "ID: " << e.id<< " | URL: " << e.url<< " | Titulo: " << e.titulo<< " | Fecha y hora: "<<e.fecha<<" "<<e.hora<< endl;
            encontrado = true;
        }
    }
    if (!encontrado)
        cout << ">> No se encontraron visitas a esa URL"<<endl;
}

// Limpiar historial
void limpiarHistorial(EntradaHistorial*& historial, int& totalEntradas, int& capacidad) {
    char confirm;
    cout << "¿Estás seguro que deseas borrar todo el historial? (s/n): ";
    cin >> confirm;

    if (confirm == 's' || confirm == 'S') {
        delete[] historial;
        totalEntradas = 0;
        historial = new EntradaHistorial[capacidad];
        cout << ">> Historial limpiado correctamente"<<endl;
    } else
        cout << ">> Operacion cancelada."<<endl;
}

