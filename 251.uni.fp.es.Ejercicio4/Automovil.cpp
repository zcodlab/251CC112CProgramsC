#include <iostream>
#include "Automovil.h"
using namespace std;

Automovil::Automovil(double gasoLitros) : gasoLitrosPorAnio(gasoLitros) {}

double Automovil::getHuellaDeCarbono() const {
    return gasoLitrosPorAnio * 2.36*0.001;               //Emisiones(tCO2) toneladas metricas de dioxido de carbono al año
}

void Automovil::imprimirInfo() const {
    cout << "Auto: " << gasoLitrosPorAnio << " litros de gasolina/anio."<<endl;
}
