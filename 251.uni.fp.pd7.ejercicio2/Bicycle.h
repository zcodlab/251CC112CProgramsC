#ifndef BICYCLE_H
#define BICYCLE_H
#include "CarbonFootprint.h"

class Bicycle : public CarbonFootprint {
private:
    double maintenanceHours;
public:
    Bicycle(double hours);
    double getCarbonFootprint() const override;
    void printInfo() const override;
};

#endif // BICYCLE_H
