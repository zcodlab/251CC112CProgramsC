#ifndef CUENTA_H
#define CUENTA_H
//Definicion de la clase Cuenta Bancaria
class Cuenta{
protected:
    double saldo;     //saldo
public:
    Cuenta(double);
    virtual void depositar(double);       //virtual permite redefinir la funcion miembro por las clases derivadas
    virtual bool retirar(double);
    double getSaldo() const;
    virtual ~Cuenta()=default;
};

#endif // CUENTA_H
