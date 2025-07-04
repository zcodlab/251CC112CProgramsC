#ifndef CAR_H
#define CAR_H
#include "CarbonFootprint.h"

class Car : public CarbonFootprint {
private:
    double litersPerYear;//litros de gasolina que consume por anio
public:
    Car(double liters);
    double getCarbonFootprint() const override;
    void printInfo() const override;
};

#endif // CAR_H
