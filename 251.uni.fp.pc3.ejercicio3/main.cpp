#include <iostream>
#include <cmath>    // para abs()
using namespace std;

const int MAX_TERMINOS = 20;
const float EPS = 1e-6;  // Para comparar coeficientes con cero

struct Termino {
    float coef;
    int exp;
};

// Prototipos
void leerPolinomio(Termino poli[], int &n);
void mostrarPolinomio(const Termino poli[], int n);
void ordenarPolinomio(Termino poli[], int &n);
void simplificarPolinomio(Termino poli[], int &n);
void sumarPolinomios(const Termino p1[], int n1, const Termino p2[], int n2, Termino resultado[], int &nr);
void multiplicarPolinomios(const Termino p1[], int n1, const Termino p2[], int n2, Termino resultado[], int &nr);

int main() {
    Termino p1[MAX_TERMINOS], p2[MAX_TERMINOS], suma[MAX_TERMINOS*2], producto[MAX_TERMINOS*2];
    int n1, n2, nsuma, nproducto;

    cout << "Ingrese el número de términos del primer polinomio: ";
    leerPolinomio(p1, n1);

    cout << "Ingrese el número de términos del segundo polinomio: ";
    leerPolinomio(p2, n2);

    cout << "\nPrimer polinomio: ";
    mostrarPolinomio(p1, n1);

    cout << "Segundo polinomio: ";
    mostrarPolinomio(p2, n2);

    sumarPolinomios(p1, n1, p2, n2, suma, nsuma);
    cout << "\nSuma: ";
    mostrarPolinomio(suma, nsuma);

    multiplicarPolinomios(p1, n1, p2, n2, producto, nproducto);
    cout << "Producto: ";
    mostrarPolinomio(producto, nproducto);

    return 0;
}

// ======================================
// Leer polinomio desde entrada
// ======================================
void leerPolinomio(Termino poli[], int &n) {
    cin >> n;
    if(n > MAX_TERMINOS) {
        cout << "Número de términos excede el máximo permitido (" << MAX_TERMINOS << "). Se truncará a ese valor"<<endl;
        n = MAX_TERMINOS;
    }
    for(int i = 0; i < n; i++) {
        cout << "Ingrese coeficiente y exponente del término " << (i+1) << ": ";
        cin >> poli[i].coef >> poli[i].exp;
    }
    ordenarPolinomio(poli, n);
    simplificarPolinomio(poli, n);
}

// ======================================
// Mostrar polinomio en forma legible
// ======================================
void mostrarPolinomio(const Termino poli[], int n) {
    if (n == 0) {
        cout << "0"<<endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        float c = poli[i].coef;
        int e = poli[i].exp;

        // Manejo del signo
        if(i > 0 && c >= 0) cout << " + ";
        else if(c < 0) cout << " - ";

        // Valor absoluto del coeficiente
        float absC = fabs(c);

        // Mostrar coeficiente, excepto cuando es 1 o -1 y hay exponente > 0
        if(absC != 1 || e == 0) cout << absC;

        // Mostrar la x y exponente si es necesario
        if(e > 0) {
            cout << "x";
            if(e > 1) cout << "^" << e;
        }
    }
    cout << endl;
}

// ======================================
// Ordenar términos por exponente descendente (burbuja simple)
// ======================================
void ordenarPolinomio(Termino poli[], int &n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(poli[j].exp < poli[j+1].exp) {
                Termino temp = poli[j];
                poli[j] = poli[j+1];
                poli[j+1] = temp;
            }
        }
    }
}

// ======================================
// Simplificar polinomio sumando términos con mismo exponente
// ======================================
void simplificarPolinomio(Termino poli[], int &n) {
    if(n <= 1) return;

    ordenarPolinomio(poli, n);
    int idx = 0;
    for(int i = 1; i < n; i++) {
        if(poli[idx].exp == poli[i].exp) {
            poli[idx].coef += poli[i].coef;
        } else {
            idx++;
            poli[idx] = poli[i];
        }
    }
    n = idx + 1;

    // Eliminar términos con coeficiente muy cercano a cero
    int validos = 0;
    for(int i = 0; i < n; i++) {
        if(fabs(poli[i].coef) > EPS)
            poli[validos++] = poli[i];
    }
    n = validos;
}

// ======================================
// Sumar dos polinomios
// ======================================
void sumarPolinomios(const Termino p1[], int n1, const Termino p2[], int n2, Termino resultado[], int &nr) {
    // Copiar p1
    nr = 0;
    for(int i = 0; i < n1; i++)
        resultado[nr++] = p1[i];
    // Agregar p2
    for(int i = 0; i < n2; i++)
        resultado[nr++] = p2[i];
    simplificarPolinomio(resultado, nr);
}

// ======================================
// Multiplicar dos polinomios
// ======================================
void multiplicarPolinomios(const Termino p1[], int n1, const Termino p2[], int n2, Termino resultado[], int &nr) {
    nr = 0;
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            resultado[nr].coef = p1[i].coef * p2[j].coef;
            resultado[nr].exp = p1[i].exp + p2[j].exp;
            nr++;
            if(nr >= MAX_TERMINOS*2) {
                cout << "Advertencia: producto excede limite de terminos."<<endl;
                break;
            }
        }
    }
    simplificarPolinomio(resultado, nr);
}
