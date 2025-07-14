#include <iostream>
#include <iomanip>
#include <sstream>  // Para construir la salida simbolica
#include <cmath>
using namespace std;

// Funcion para construir el polinomio de Lagrange como texto
string construirPolinomioLagrange(double** puntos, int n) {
    ostringstream polinomio;
    for (int j = 0; j < n; ++j) {
        double denominador = 1.0;
        ostringstream termino;
        termino << fixed << setprecision(3);
        termino << "(" << puntos[j][1] << ")";
        for (int m = 0; m < n; ++m) {
            if (m != j) {
                double xj = puntos[j][0];
                double xm = puntos[m][0];
                denominador *= (xj - xm);
                termino << " * (x - " << xm << ")";
            }
        }
        termino << " / " << denominador;
        // Agregar signo + entre terminos, excepto el primero
        if (j > 0)
            polinomio << " + ";
        polinomio << termino.str();
    }
    return polinomio.str();
}

// Funcion que evalua el polinomio de Lagrange en x_eval
double interpolarLagrange(double** puntos, int n, double x_eval) {
    double resultado = 0.0;
    for (int j = 0; j < n; ++j) {
        double termino = puntos[j][1];
        for (int m = 0; m < n; ++m) {
            if (m != j) {
                double numerador = x_eval - puntos[m][0];
                double denominador = puntos[j][0] - puntos[m][0];
                if (fabs(denominador) < 1e-9) {
                    cerr << "Error: Division por cero (valores x_i repetidos)." << endl;
                    return 0.0;
                }
                termino *= (numerador / denominador);
            }
        }
        resultado += termino;
    }
    return resultado;
}

int main() {
    int n;
    cout << "Ingrese la cantidad de puntos (N >= 2): ";
    cin >> n;
    if (n < 2) {
        cerr << "Se requieren al menos 2 puntos para interpolar." << endl;
        return 1;
    }
    // Asignacion dinamica de la matriz Nx2
    double** puntos = new double*[n];
    for (int i = 0; i < n; ++i) {
        puntos[i] = new double[2];
    }
    // Ingreso de puntos (x_i, y_i)
    cout << "Ingrese los " << n << " puntos (formato: x y):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Punto " << i + 1 << ": ";
        cin >> puntos[i][0] >> puntos[i][1];
    }
    // Mostrar el polinomio como expresion simbolica
    cout <<endl<<"Polinomio de Lagrange (forma simbolica):" << endl;
    string polinomioTexto = construirPolinomioLagrange(puntos, n);
    cout << "P(x) = " << polinomioTexto << endl;
    // Evaluacion en un punto
    double x_eval;
    cout <<endl<< "Ingrese el valor de x para evaluar el polinomio: ";
    cin >> x_eval;
    double resultado = interpolarLagrange(puntos, n, x_eval);
    cout << fixed << setprecision(6);
    cout << "P(" << x_eval << ") = " << resultado << endl;
    // Liberar memoria
    for (int i = 0; i < n; ++i) {
        delete[] puntos[i];
    }
    delete[] puntos;

    return 0;
}
