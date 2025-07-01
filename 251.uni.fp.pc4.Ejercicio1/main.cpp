#include <iostream>
using namespace std;

struct Punto {
    int x, y;
};

struct Conjunto {
    Punto* puntos;
    int size;
};

// Función para leer un conjunto
void leerConjunto(Conjunto& c) {
    cout << "Ingrese la cantidad de puntos: ";
    cin >> c.size;

    c.puntos = new Punto[c.size];
    cout << "Ingrese los puntos (x y):"<<endl;
    for (int i = 0; i < c.size; ++i)
        cin >> c.puntos[i].x >> c.puntos[i].y;
}

// Función para mostrar un conjunto
void mostrarConjunto(Conjunto& c) {
    for (int i = 0; i < c.size; ++i)
        cout << "(" << c.puntos[i].x << "," << c.puntos[i].y << ") ";
    cout << endl;
}

// Función para unir dos conjuntos sin duplicados
Conjunto unirConjuntos(const Conjunto& A, const Conjunto& B) {
    Conjunto resultado;
    resultado.size = 0;
    resultado.puntos = new Punto[A.size + B.size];

    for (int i = 0; i < A.size; ++i)
        resultado.puntos[resultado.size++] = A.puntos[i];

    // Añadir los puntos de B si no están en resultado
    for (int i = 0; i < B.size; ++i) {
        bool existe = false;
        for (int j = 0; j < resultado.size; ++j) {
            if (resultado.puntos[j].x == B.puntos[i].x &&
                resultado.puntos[j].y == B.puntos[i].y) {
                existe = true;
                break;
            }
        }
        if (!existe) {
            resultado.puntos[resultado.size++] = B.puntos[i];
        }
    }

    return resultado;
}


// Función para liberar la memoria
void liberarConjunto(Conjunto& c) {
    delete[] c.puntos;
    c.puntos = nullptr;
    c.size = 0;
}

// Función principal
int main() {
    Conjunto A, B, C;

    cout << "Conjunto A:"<<endl;
    leerConjunto(A);

    cout <<endl<< "Conjunto B:"<<endl;
    leerConjunto(B);

    C = unirConjuntos(A, B);

    cout <<endl<< "Union de A y B:"<<endl;
    mostrarConjunto(C);

    // Liberar memoria
    liberarConjunto(A);
    liberarConjunto(B);
    liberarConjunto(C);

    return 0;
}
