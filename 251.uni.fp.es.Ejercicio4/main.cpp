#include <iostream>

#include "HuellaDeCarbono.h"
#include "Edificio.h"
#include "Automovil.h"
#include "Bicicleta.h"

using namespace std;

int main() {
    // Crear un array de punteros a objetos HuellaDeCarbono
    const int numObjetos = 3;
    HuellaDeCarbono* objetos[numObjetos];

    // Asignar objetos concretos al array
    objetos[0] = new Edificio(12000);    // 12000 kWh/año
    objetos[1] = new Automovil(850);     // 850 litros gasolina/año
    objetos[2] = new Bicicleta(12);      // 12 horas de mantenimiento/año

    // Recorrer el array e imprimir la informacion
    for (int i = 0; i < numObjetos; i++) {
        objetos[i]->imprimirInfo();
        cout << "Huella de carbono: "
             << objetos[i]->getHuellaDeCarbono()
             << " toneladas metricas (t) CO2/anio"
             << endl << endl;
    }

    // Liberar memoria
    for (int i = 0; i < numObjetos; ++i) {
        delete objetos[i];
    }

    return 0;
}
