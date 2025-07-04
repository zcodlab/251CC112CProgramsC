#include <iostream>
#include "Bicycle.h"

using namespace std;
//implementa el constructor de Bicicleta
Bicycle::Bicycle(double hours) : maintenanceHours(hours) {}
//impementando el metodo virtual
double Bicycle::getCarbonFootprint() const {
    return maintenanceHours * 0.5;
}

void Bicycle::printInfo() const {
    cout << "Bicicleta: " << maintenanceHours << " horas de mantenimiento anual."<<endl;
}
