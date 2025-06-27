#include <iostream>
#include <iomanip>
#include "cuenta.h"
#include "CuentaAhorros.h"
#include "CuentaCorriente.h"
#include "cuenta.cpp"
#include "CuentaAhorros.cpp"
#include "CuentaCorriente.cpp"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
    cout <<fixed<<setprecision(2);
    //Crear cuenta de Ahorros
    CuentaAhorros ca(1000.0,0.05);  //5% de interes
    double interes=ca.calcularInteres();
    cout<<"Interes generado: S/ "<<interes<<endl;
    //Ralizando un retiro de la cuenta
    ca.retirar(interes);
    cout<<"Nuevo Saldo en la cuenta de ahorros: S/ "<<ca.getSaldo()<<endl;

    //operaciones con la cuenta corriente
    CuentaCorriente cc(500.0,2.0);   //2.0 es el importe de la comision por Transaccion
    cc.depositar(100.0);
    cout<<"Saldo despues de realizar el deposito en la cuenta corriente: S/ "
    <<cc.getSaldo()<<endl;
    //Ralizando un retiro de la cuenta corriente
    cout<<"Realizando un retiro de S/600.0 "<<endl;
    cc.retirar(600.0);
    cout<<"Saldo despues de realizar el retiro en la cuenta corriente: S/ "
    <<cc.getSaldo()<<endl;

    return 0;
}
