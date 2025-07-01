#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
const int ANIO_INI=2020;
const int ANIO_FIN=2030;
const int NDIA_MES=30;
const int NMES_ANIO=12;
const int NHORA_LIMIT_SUP=23;
const int NMINUTO_LIMIT_SUP=59;
const int NSEGUNDO_LIMIT_SUP=59;
const int NHORA_LIMIT_INF=0;
const int NMINUTO_LIMIT_INF=0;
const int NSEGUNDO_LIMIT_INF=0;
const int FECHA_LONG_LIMIT=10;
const int HORA_LONG_LIMIT=8;
const int MAX_SISMOS = 100;
const string SALTO_LINEA = "\n";

struct Sismo {
    int id;
    string fecha;   // dd/mm/aaaa
    string hora;    // hh:mm:ss
    float magnitud;
    string lugar;
};

// Validar fecha con formato dd/mm/aaaa
bool validarFecha(const string& fecha) {
    if (fecha.length() != FECHA_LONG_LIMIT) return false;
    if (fecha[2] != '/' || fecha[5] != '/') return false;

    int dia = stoi(fecha.substr(0, 2));
    int mes = stoi(fecha.substr(3, 2));
    int anio = stoi(fecha.substr(6, 4));

    if (dia < 1 || dia > NDIA_MES) return false;
    if (mes < 1 || mes > NMES_ANIO) return false;
    if (anio < ANIO_INI || anio > ANIO_FIN) return false;

    return true;
}

// Validar hora con formato hh:mm:ss
bool validarHora(const string& hora) {
    if (hora.length() != HORA_LONG_LIMIT) return false;
    if (hora[2] != ':' || hora[5] != ':') return false;

    int h = stoi(hora.substr(0, 2));
    int m = stoi(hora.substr(3, 2));
    int s = stoi(hora.substr(6, 2));

    if (h < NHORA_LIMIT_INF || h > NHORA_LIMIT_SUP) return false;
    if (m < NMINUTO_LIMIT_INF || m > NMINUTO_LIMIT_SUP) return false;
    if (s < NSEGUNDO_LIMIT_INF || s > NSEGUNDO_LIMIT_SUP) return false;

    return true;
}

// Mostrar todos los sismos
void mostrarSismos(const Sismo sismos[], int total) {
     cout <<endl;
    cout << left << setw(5) << "ID" << setw(12) << "Fecha" << setw(10) << "Hora"
         << setw(10) << "Magnitud" << "Lugar" << endl;
    cout << string(50, '-') << endl;
    for (int i = 0; i < total; ++i) {
        cout << left << setw(5) << sismos[i].id
             << setw(12) << sismos[i].fecha
             << setw(10) << sismos[i].hora
             << setw(10) << sismos[i].magnitud
             << sismos[i].lugar << endl;
    }
}

// Leer archivo
int leerArchivo(Sismo sismos[], const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    int total = 0;

    while (archivo >> sismos[total].id
                  >> sismos[total].fecha
                  >> sismos[total].hora
                  >> sismos[total].magnitud
                  >> sismos[total].lugar) {
        total++;
        if (total >= MAX_SISMOS) break;
    }

    archivo.close();
    return total;
}

// Registrar nuevo sismo con validacion
void registrarSismo(const string& nombreArchivo, int id) {
    ofstream archivo(nombreArchivo, ios::app);
    Sismo s;
    s.id = id;

    do {
        cout << "Fecha (dd/mm/aaaa): ";
        getline(cin, s.fecha);
        if (!validarFecha(s.fecha))
            cout << "Fecha invalida. Intente nuevamente."<<endl;
    } while (!validarFecha(s.fecha));

    do {
        cout << "Hora (hh:mm:ss): ";
        getline(cin, s.hora);
        if (!validarHora(s.hora))
            cout << "Hora invalida. Intente nuevamente."<<endl;
    } while (!validarHora(s.hora));

    cout << "Magnitud: ";
    cin >> s.magnitud;
    cin.ignore(); // limpiar entrada

    cout << "lugar: ";
    getline(cin, s.lugar);

    archivo <<SALTO_LINEA<< s.id << " " << s.fecha << " " << s.hora << " "
            << s.magnitud << " " << s.lugar <<SALTO_LINEA;

    archivo.close();
}

int main() {
    Sismo sismos[MAX_SISMOS];
    string archivo= "sismos.txt";
    int total = leerArchivo(sismos,archivo);

    int opcion;
    do {
        cout <<endl<< "Programa de Registro de Sismos en Peru"<<endl;
        cout << "1. Mostrar sismos registrados"<<endl;
        cout << "2. Registrar nuevo sismo"<<endl;
        cout << "3. Salir"<<endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); // limpiar buffer

        switch (opcion) {
            case 1:
                mostrarSismos(sismos, total);
                break;
            case 2:
                registrarSismo( archivo, total + 1);
                total = leerArchivo(sismos, archivo);
                break;
            case 3:
                cout << "Finalizando el programa"<<endl;
                break;
            default:
                cout << "Opcion invalida"<<endl;
        }

    } while (opcion != 3);

    return 0;
}
