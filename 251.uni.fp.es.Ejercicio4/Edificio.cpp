#include <iostream>
#include "Edificio.h"

using namespace std;

Edificio::Edificio(double usoElectricidad) : usoElectricidadKWh(usoElectricidad) {}

double Edificio::getHuellaDeCarbono() const {
    return usoElectricidadKWh * 0.86*0.001;         //Emisiones(tCO2e) toneladas metricas de dioxido de carbono incluye otros gases
}

void Edificio::imprimirInfo() const {
    cout << "Edificio: " << usoElectricidadKWh << " kWh/anio de electricidad."<<endl;
}
