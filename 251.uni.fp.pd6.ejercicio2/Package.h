#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
using namespace std;

class Package {
protected:
    string remitenteNombre, destinatarioNombre;
    string remitenteDireccion, destinatarioDireccion;
    string remitenteCiudad, destinatarioCiudad;
    string remitenteEstado, destinatarioEstado;
    string remitenteCP, destinatarioCP;
    double peso;
    double costoPorOnza;

public:
    Package(string rNom, string rDir, string rCiu, string rEst, string rCP,
            string dNom, string dDir, string dCiu, string dEst, string dCP,
            double p, double costo);

    virtual double calculateCost() const;
    virtual void mostrarInfo() const;
    virtual ~Package() {}
};
#endif // PACKAGE_H
