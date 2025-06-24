#include "Package.h"
#include <stdexcept>
#include <iostream>

Package::Package(string rNom, string rDir, string rCiu, string rEst, string rCP,
                 string dNom, string dDir, string dCiu, string dEst, string dCP,
                 double p, double costo)
    : remitenteNombre(rNom), remitenteDireccion(rDir), remitenteCiudad(rCiu),
      remitenteEstado(rEst), remitenteCP(rCP),
      destinatarioNombre(dNom), destinatarioDireccion(dDir), destinatarioCiudad(dCiu),
      destinatarioEstado(dEst), destinatarioCP(dCP) {
    if (p <= 0 || costo <= 0)
        throw invalid_argument("Peso y costo por onza deben ser positivos.");
    peso = p;
    costoPorOnza = costo;
}
//Colocar const despues de la declaracion del metodo indica que el metodo no modifica el estado del objeto. Es decir:
//No puede cambiar ninguno de los atributos (miembros de datos) del objeto.
double Package::calculateCost() const {
    return peso * costoPorOnza;
}

void Package::mostrarInfo() const {
    cout << "De: " << remitenteNombre << " -> Para: " << destinatarioNombre << endl;
}
