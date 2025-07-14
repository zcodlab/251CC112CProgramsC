#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
struct Sistema {
    int id;
    float coef[3][4];
    float x = 0, y = 0, z = 0;
    char estado[20] = "No resuelto";
};
float determinante(float m[3][3]) {
    return m[0][0]*(m[1][1]*m[2][2] - m[1][2]*m[2][1]) -
           m[0][1]*(m[1][0]*m[2][2] - m[1][2]*m[2][0]) +
           m[0][2]*(m[1][0]*m[2][1] - m[1][1]*m[2][0]);
}
void registrarSistema() {
    Sistema s;
    cout << "ID del sistema: ";
    cin >> s.id;
    cout << "Ingrese los coeficientes y terminos indpendientes (3x4):"<<endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Ecuacion " << i+1 << ": ";
        for (int j = 0; j < 4; ++j)
            cin >> s.coef[i][j];
    }
    ofstream archivo("sistemas.dat", ios::binary | ios::app);
    if (!archivo) {
        cerr << "Error al abrir el archivo."<<endl;
        return;
    }
    archivo.write(reinterpret_cast<char*>(&s), sizeof(Sistema));
    archivo.close();
    cout << "Sistema registrado con exito."<<endl;
}
void resolverSistemas() {
    fstream archivo("sistemas.dat", ios::in | ios::out | ios::binary);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo sistemas.dat"<<endl;
        return;
    }
    Sistema s;
    while (archivo.read(reinterpret_cast<char*>(&s), sizeof(Sistema))) {
        float D[3][3], Dx[3][3], Dy[3][3], Dz[3][3];
        for (int i = 0; i < 3; ++i) {
            D[i][0] = s.coef[i][0];
            D[i][1] = s.coef[i][1];
            D[i][2] = s.coef[i][2];

            Dx[i][0] = s.coef[i][3];
            Dx[i][1] = s.coef[i][1];
            Dx[i][2] = s.coef[i][2];

            Dy[i][0] = s.coef[i][0];
            Dy[i][1] = s.coef[i][3];
            Dy[i][2] = s.coef[i][2];

            Dz[i][0] = s.coef[i][0];
            Dz[i][1] = s.coef[i][1];
            Dz[i][2] = s.coef[i][3];
        }
        float detD = determinante(D);
        if (detD != 0) {
            s.x = determinante(Dx) / detD;
            s.y = determinante(Dy) / detD;
            s.z = determinante(Dz) / detD;
            strcpy(s.estado, "Unica");
        } else {
            float dx = determinante(Dx);
            float dy = determinante(Dy);
            float dz = determinante(Dz);
            if (dx == 0 && dy == 0 && dz == 0)
                strcpy(s.estado, "Infinita");
            else
                strcpy(s.estado, "Sin solucion");
        }
        archivo.seekp(-static_cast<int>(sizeof(Sistema)), ios::cur);
        archivo.write(reinterpret_cast<char*>(&s), sizeof(Sistema));
        archivo.flush();
    }
    archivo.close();
    cout << "Todos los sistemas han sido resueltos."<<endl;
}
void generarReporte() {
    ifstream archivo("sistemas.dat", ios::binary);
    ofstream reporte("reporte.txt");

    if (!archivo || !reporte) {
        cerr << "Errror al abrir los archivos."<<endl;
        return;
    }
    Sistema s;
    while (archivo.read(reinterpret_cast<char*>(&s), sizeof(Sistema))) {
        reporte << "ID: " << s.id <<endl;
        reporte << "Sistema:"<<endl;
        for (int i = 0; i < 3; ++i) {
            reporte << fixed << setprecision(2)
                    << s.coef[i][0] << "x + "
                    << s.coef[i][1] << "y + "
                    << s.coef[i][2] << "z = "
                    << s.coef[i][3] <<endl;
        }
        reporte << "Estado: " << s.estado <<endl;
        if (strcmp(s.estado, "Unica") == 0) {
            reporte << "Solución: x = " << s.x << ", y = " << s.y << ", z = " << s.z <<endl;
        }
        reporte << "--------------------------"<<endl;
    }
    archivo.close();
    reporte.close();
    cout << "Reporte generado exitosamente (reporte.txt)"<<endl;
}
void menu() {
    int opcion;
    do {
        cout <<endl<<"======= MENU ======="<<endl;
        cout << "1. Registrar sistema"<<endl;
        cout << "2. Resolver todos los sistemas"<<endl;
        cout << "3. Generar reporte"<<endl;
        cout << "0. Salir"<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: registrarSistema(); break;
            case 2: resolverSistemas(); break;
            case 3: generarReporte(); break;
            case 0: cout << "Fin"; break;
            default: cout << "Opcion invalida."<<endl; break;
        }
    } while (opcion != 0);
}
int main() {
    menu();
    return 0;
}
