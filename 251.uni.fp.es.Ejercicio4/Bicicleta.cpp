#include <iostream>
#include "Bicicleta.h"

using namespace std;

Bicicleta::Bicicleta(double horasMnto) : horasMantenimiento(horasMnto) {}

double Bicicleta::getHuellaDeCarbono() const {
    return 1/horasMantenimiento * 9.6 * 0.001;         // X t CO2₂ emitidos por cada hora de mantenimiento
}

void Bicicleta::imprimirInfo() const {
    cout << "Bicicleta: " << horasMantenimiento << " horas de mantenimiento anual."<<endl;
}
