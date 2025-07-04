#include <iostream>
#include "Car.h"

using namespace std;

Car::Car(double liters) : litersPerYear(liters) {}
//obtiene la contaminacion que genera la gasolina en litros por anio
double Car::getCarbonFootprint() const {
    return litersPerYear * 2.31;
}

void Car::printInfo() const {
    cout << "Auto: " << litersPerYear << " litros de gasolina/anio."<<endl;
}
