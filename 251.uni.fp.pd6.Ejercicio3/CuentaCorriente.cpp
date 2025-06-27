#include <iostream>
#include "CuentaCorriente.h"
using std::cout;
using std::endl;
CuentaCorriente::CuentaCorriente(double saldo,double comision)
                            : Cuenta(saldo), comisionTransaccion(comision){}

void  CuentaCorriente:: cobrarComision(){
    if(saldo>= comisionTransaccion)
        saldo-=comisionTransaccion;     //cobrando la comision
    else
        cout<<"No se pudo cobrar la comision, saldo insuficiente."<<endl;
}

void CuentaCorriente::depositar(double importe){
    Cuenta::depositar(importe);
    cobrarComision();
}

bool CuentaCorriente::retirar(double importe){
    if(Cuenta::retirar(importe)){
        cobrarComision();
        return true;    //operacion exitosa
    }
    return false;      //aborta la operacion
}



