#ifndef BUILDING_H
#define BUILDING_H
#include "CarbonFootprint.h"

class Building : public CarbonFootprint {
private:
    double electricityUsageKWh;
public:
    Building(double usage);
    double getCarbonFootprint() const override;
    void printInfo() const override;
};
#endif // BUILDING_H
