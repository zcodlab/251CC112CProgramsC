#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class CuentaBancaria {
private:
    string titular;          // Nombre del cliente
    double saldo;            // Saldo actual de la cuenta
    int numeroCuenta;        // N�mero �nico de cuenta
    int transaccionesDelDia; // Cantidad de operaciones realizadas hoy

public:
    // Constructor
    CuentaBancaria(string nombre, double saldoInicial, int numero)
        : titular(nombre), saldo(saldoInicial), numeroCuenta(numero), transaccionesDelDia(0) {}

    // M�todo para depositar dinero
    void depositar(double monto) {
        if (monto <= 0) {
            cout << "[Error] El monto a depositar debe ser mayor que cero."<<endl;
            return;
        }

        saldo += monto;
        cout << fixed << setprecision(2);
        cout << "[Dep�sito] Se deposit� " << monto << ". Saldo actual: " << saldo << endl;
    }

    // M�todo para retirar dinero
    void retirar(double monto) {
        if (monto <= 0) {
            cout << "[Error] El monto a retirar debe ser mayor que cero."<<endl;
            return;
        }

        if (transaccionesDelDia >= 3) {
            cout << "[Error] Ha alcanzado el l�mite de 3 retiros diarios."<<endl;
            return;
        }

        if (monto > saldo) {
            cout << "[Error] Fondos insuficientes. Saldo disponible: " << saldo << endl;
            return;
        }

        saldo -= monto;
        transaccionesDelDia++;
        cout << fixed << setprecision(2);
        cout << "[Retiro] Se retiro " << monto << ". Saldo actual: " << saldo << endl;
    }

    // M�todo para mostrar la informacion de la cuenta
    void mostrarSaldo() const {
        cout <<endl<<"Resumen de la cuenta:"<<endl;
        cout << "Titular: " << titular << endl;
        cout << "N�mero de cuenta: " << numeroCuenta << endl;
        cout << fixed << setprecision(2);
        cout << "Saldo actual: " << saldo << endl;
        cout << "Retiros realizados hoy: " << transaccionesDelDia << " de 3 permitidos"<<endl;
    }

    // M�todo para reiniciar el contador de transacciones diarias
    void resetearTransacciones() {
        transaccionesDelDia = 0;
        cout << "[Info] El contador de transacciones diarias ha sido reiniciado."<<endl;
    }
};


int main() {
    CuentaBancaria cuenta1("Carlos Garcia", 500.0, 123456);

    cuenta1.mostrarSaldo();

    cuenta1.depositar(200);
    cuenta1.retirar(100);
    cuenta1.retirar(250);
    cuenta1.retirar(50);
    cuenta1.retirar(10); // excede el limite

    cuenta1.mostrarSaldo();

    cuenta1.resetearTransacciones();
    cuenta1.retirar(10);

    cuenta1.mostrarSaldo();

    return 0;
}
