#include "TwoDayPackage.h"
#include <stdexcept>

TwoDayPackage::TwoDayPackage(string rNom, string rDir, string rCiu, string rEst, string rCP,
                             string dNom, string dDir, string dCiu, string dEst, string dCP,
                             double p, double costo, double tarifa)
    : Package(rNom, rDir, rCiu, rEst, rCP, dNom, dDir, dCiu, dEst, dCP, p, costo) {
    if (tarifa < 0)
        throw invalid_argument("Tarifa fija no puede ser negativa.");
    tarifaFija = tarifa;
}

double TwoDayPackage::calculateCost() const {
    return Package::calculateCost() + tarifaFija;
}
