#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

const int N = 3;
const int M = 3;
const int ID_LEN = 10;
const int ESTADO_LEN = 20;

struct Sistema {
    char id[ID_LEN];
    float matriz[N][M + 1]; // Matriz aumentada
    char estado[ESTADO_LEN];
    float solucion[M];
};

// Gauss-Jordan
void resolverSistema(Sistema &s) {
    float a[N][M + 1];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= M; ++j)
            a[i][j] = s.matriz[i][j];

    for (int i = 0; i < N; ++i) {
        if (a[i][i] == 0) {
            bool cambiado = false;
            for (int k = i + 1; k < N; ++k) {
                if (a[k][i] != 0) {
                    for (int j = 0; j <= M; ++j) {
                        float temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                    cambiado = true;
                    break;
                }
            }
            if (!cambiado)
                continue;
        }

        float pivote = a[i][i];
        for (int j = 0; j <= M; ++j)
            a[i][j] /= pivote;

        for (int k = 0; k < N; ++k) {
            if (k != i) {
                float factor = a[k][i];
                for (int j = 0; j <= M; ++j)
                    a[k][j] -= factor * a[i][j];
            }
        }
    }

    bool inconsistente = false, infinita = false;

    for (int i = 0; i < N; ++i) {
        bool coefCero = true;
        for (int j = 0; j < M; ++j)
            if (a[i][j] != 0) coefCero = false;

        if (coefCero && a[i][M] != 0)
            inconsistente = true;
        else if (coefCero && a[i][M] == 0)
            infinita = true;
    }

    if (inconsistente) {
        strcpy(s.estado, "sin solucion");
    } else if (infinita) {
        strcpy(s.estado, "infinita");
    } else {
        strcpy(s.estado, "unica");
        for (int i = 0; i < M; ++i)
            s.solucion[i] = a[i][M];
    }
}

void registrarSistema() {
    Sistema s;
    string idTemp;
    cout << "ID del sistema: ";
    cin >> idTemp;
    strncpy(s.id, idTemp.c_str(), ID_LEN);
    s.id[ID_LEN - 1] = '\0'; // asegurar terminación

    cout << "Ingrese los coeficientes y terminos independientes:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Ecuacion " << i + 1 << ": ";
        for (int j = 0; j <= M; ++j)
            cin >> s.matriz[i][j];
    }

    strcpy(s.estado, "pendiente");

    ofstream out("sistemas.dat", ios::binary | ios::app);
    out.write(reinterpret_cast<char*>(&s), sizeof(Sistema));
    out.close();
}

void resolverTodos() {
    fstream file("sistemas.dat", ios::in | ios::out | ios::binary);
    Sistema s;

    while (file.read(reinterpret_cast<char*>(&s), sizeof(Sistema))) {
        resolverSistema(s);
        file.seekp(-static_cast<int>(sizeof(Sistema)), ios::cur);
        file.write(reinterpret_cast<char*>(&s), sizeof(Sistema));
    }

    file.close();
    cout << "Todos los sistemas han sido resueltos." << endl;
}

void generarReporte() {
    ifstream in("sistemas.dat", ios::binary);
    ofstream out("reporte.txt");

    Sistema s;

    while (in.read(reinterpret_cast<char*>(&s), sizeof(Sistema))) {
        out << "ID: " << s.id << endl;
        out << fixed << setprecision(2);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j)
                out << s.matriz[i][j] << (j < M - 1 ? "x + " : "x = ");
            out << s.matriz[i][M] << endl;
        }
        out << "Estado: " << s.estado << endl;

        if (strcmp(s.estado, "unica") == 0) {
            out << "Solucion: ";
            for (int i = 0; i < M; ++i)
                out << "x" << i + 1 << " = " << s.solucion[i] << " ";
            out << endl;
        }
        out << "------------------------" << endl;
    }

    in.close();
    out.close();
    cout << "Reporte generado: reporte.txt" << endl;
}

int main() {
    int opcion;
    do {
        cout << endl << "=== MENU ===" << endl;
        cout << "1. Registrar sistema" << endl;
        cout << "2. Resolver todos los sistemas" << endl;
        cout << "3. Generar reporte" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: registrarSistema(); break;
            case 2: resolverTodos(); break;
            case 3: generarReporte(); break;
            case 0: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
