#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Venta {
    string codigoProducto;
    int cantidad;
    float precioUnitario;
};

int main() {
    const int MAX = 100;
    Venta ventas[MAX];
    int n;

    cout << "¿Cuántas ventas desea ingresar (máximo 100)?: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        cout << "\nVenta #" << (i + 1) << "\n";
        cout << "Código producto: "; getline(cin, ventas[i].codigoProducto);
        cout << "Cantidad: "; cin >> ventas[i].cantidad;
        cout << "Precio unitario: "; cin >> ventas[i].precioUnitario;
        cin.ignore();
    }

    ofstream archivo("ventas.txt");
    for (int i = 0; i < n; ++i) {
        archivo << ventas[i].codigoProducto << "|"
                << ventas[i].cantidad << "|"
                << ventas[i].precioUnitario << "\n";
    }
    archivo.close();

    // Leer archivo y calcular ingresos
    ifstream lectura("ventas.txt");
    string linea;
    string codigos[MAX];
    float ingresos[MAX];
    int usados = 0;
    float totalGeneral = 0;

    while (getline(lectura, linea)) {
        stringstream ss(linea);
        string codigo, cantidadStr, precioStr;
        getline(ss, codigo, '|');
        getline(ss, cantidadStr, '|');
        getline(ss, precioStr);

        int cantidad = stoi(cantidadStr);
        float precio = stof(precioStr);
        float ingreso = cantidad * precio;
        totalGeneral += ingreso;

        // Buscar si ya existe ese código
        bool encontrado = false;
        for (int i = 0; i < usados; ++i) {
            if (codigos[i] == codigo) {
                ingresos[i] += ingreso;
                encontrado = true;
                break;
            }
        }
        // Si no existe, agregar nuevo
        if (!encontrado && usados < MAX) {
            codigos[usados] = codigo;
            ingresos[usados] = ingreso;
            usados++;
        }
    }
    lectura.close();

    // Mostrar resultados
    string productoMayor = "";
    float mayorIngreso = 0;

    cout << "\nIngresos por producto:\n";
    for (int i = 0; i < usados; ++i) {
        cout << "Producto " << codigos[i] << " - Ingreso: S/ " << ingresos[i] << "\n";
        if (ingresos[i] > mayorIngreso) {
            mayorIngreso = ingresos[i];
            productoMayor = codigos[i];
        }
    }

    cout << "\nProducto con mayor ingreso: " << productoMayor << " (S/ " << mayorIngreso << ")\n";
    cout << "Total general del día: S/ " << totalGeneral << "\n";

    return 0;
}
