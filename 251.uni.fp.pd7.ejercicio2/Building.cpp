#include <iostream>
#include "Building.h"

using namespace std;

Building::Building(double usage) : electricityUsageKWh(usage) {}

double Building::getCarbonFootprint() const {
    return electricityUsageKWh * 0.475;
}

void Building::printInfo() const {
    cout << "Edificio: " << electricityUsageKWh << " kWh/anio de electricidad."<<endl;
}
