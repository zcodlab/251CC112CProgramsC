#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H
#include "cuenta.h"
class CuentaAhorros:public Cuenta{
private:
    double tasaInteres;                //porcentaje
public:
    CuentaAhorros(double,double);
    double calcularInteres() const;
};
#endif // CUENTAAHORROS_H
