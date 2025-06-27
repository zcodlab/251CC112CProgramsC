#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H
#include "cuenta.h"
class CuentaCorriente: public Cuenta{
private:
  double comisionTransaccion;
  void cobrarComision();
public:
    CuentaCorriente(double,double);
    void depositar(double) override;
    bool retirar(double) override;
};


#endif // CUENTACORRIENTE_H
