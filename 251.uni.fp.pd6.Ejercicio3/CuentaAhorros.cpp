#include "CuentaAhorros.h"

CuentaAhorros::CuentaAhorros(double saldo,double tasa):
    Cuenta(saldo),tasaInteres(tasa){}

double CuentaAhorros::calcularInteres() const{
                return saldo*tasaInteres;
        }
