#include <iostream>
#include "cuenta.h"
using std::cerr;
using std::endl;
//implementando el constructor de la clase
Cuenta::Cuenta(double saldoInicial){
    if(saldoInicial>=0.0)
            saldo=saldoInicial;
    else{
        saldo=0.0;
        cerr<<"Saldo inicial es invalido. Se establece a 0.0"<<endl;
     }
}
//Implementando la funcion miembro: depositar
void Cuenta::depositar(double importe){
    saldo+=importe;
}
//Implementando la funcion miembro: retirar
bool Cuenta::retirar(double importe){
    if(importe>saldo){
        cerr<<"Importe a retirar supera el saldo de la cuenta."<<endl;
        return false;
    }else{
        saldo-=importe;
        return true;
    }
}
//Implementando la funcion miembro: obtenerSaldo
double Cuenta::getSaldo() const{
    return saldo;
}
