#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include "Package.h"

class TwoDayPackage : public Package {
private:
    double tarifaFija;

public:
    TwoDayPackage(string rNom, string rDir, string rCiu, string rEst, string rCP,
                  string dNom, string dDir, string dCiu, string dEst, string dCP,
                  double p, double costo, double tarifa);

    double calculateCost() const override;
};

#endif // TWODAYPACKAGE_H
