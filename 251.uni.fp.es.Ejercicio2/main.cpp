#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//problema 3

struct Venta {
    string codigoProducto;
    int cantidad;
    float precioUnitario;
};

void registrarVentas() {
    ofstream archivo("ventas.txt", ios::app);
    if (!archivo) {
        cout<< "error al abrir el archivo." << endl;
        return;
    }

    char opcion;
    do {
        Venta v;
        cout<< "\nCodigo del producto: ";
        cin>> v.codigoProducto;
        cout<< "Cantidad vendida: ";
        cin>> v.cantidad;
        cout<< "Precio unitario: ";
        cin>> v.precioUnitario;

        archivo<< v.codigoProducto << " "
            	<< v.cantidad << " "
                << v.precioUnitario << endl;

        cout << "Desea ingresar otra venta? (si=1/no=2): ";
        cin >> opcion;
    } while (opcion=='1');

    archivo.close();
}

void procesarVentas() {
    ifstream archivo("ventas.txt");
    if (!archivo) {
        cout<<"No se pudo abrir el archivo de ventas." << endl;
        return;
    }

    string codigo;
    int cantidad;
    float precio;
    float totalGeneral = 0.0;
    string codigoMax;
    float ingresoMax = 0.0;

    cout<< "\nDetalle de ventas:\n";
    while (archivo >> codigo >> cantidad >> precio) {
        float totalVenta = cantidad * precio;
        totalGeneral += totalVenta;

        cout<< "Producto: " <<codigo
            << " | Cantidad: " <<cantidad
            << " | Precio: " <<precio
            << " | Total: " <<totalVenta<<endl;

        if (totalVenta > ingresoMax) {
            ingresoMax=totalVenta;
            codigoMax=codigo;
        }
    }

    cout<< "\nProducto con mayor ingreso: " << codigoMax << " con S/." << ingresoMax << endl;
    cout<< "Total general del dia: S/." << totalGeneral << endl;

    archivo.close();
}

int main() {
    int opcion;
        cout<<"\n    MENU    \n";
        cout<<"1.Registrar ventas\n";
        cout<<"2.Procesar archivo de ventas\n";
        cout<<"3.Salir\n";
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        switch (opcion) {
            case 1: registrarVentas(); break;
            case 2: procesarVentas(); break;
            default: cout<<"Opcion invalida.\n";
        }

    return 0;
}


