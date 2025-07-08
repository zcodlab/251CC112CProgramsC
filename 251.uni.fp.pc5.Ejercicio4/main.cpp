#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const double PI = 3.141592653589793;

class Figura3D {
public:
    virtual double volumen() const = 0;
    virtual string descripcion() const = 0;
    virtual ~Figura3D() {}
};

// ==================== CUBO ====================
class Cubo : public Figura3D {
private:
    double lado;
public:
    Cubo(double lado) {
        if (lado <= 0) {
            cout << "[Error] El lado debe ser positivo. Usando 1 por defecto."<<endl;
            this->lado = 1;
        } else {
            this->lado = lado;
        }
    }

    double volumen() const override {
        return lado * lado * lado;
    }

    string descripcion() const override {
        return "Cubo de lado " + to_string(lado);
    }
};

// ==================== ESFERA ====================
class Esfera : public Figura3D {
private:
    double radio;
public:
    Esfera(double radio) {
        if (radio <= 0) {
            cout << "[Error] El radio debe ser positivo. Usando 1 por defecto."<<endl;
            this->radio = 1;
        } else {
            this->radio = radio;
        }
    }

    double volumen() const override {
        return (4.0 / 3.0) * PI * pow(radio, 3);
    }

    string descripcion() const override {
        return "Esfera de radio " + to_string(radio);
    }
};

// ==================== CILINDRO ====================
class Cilindro : public Figura3D {
private:
    double radio;
    double altura;
public:
    Cilindro(double r, double h) {
        if (r <= 0 || h <= 0) {
            cout << "[Error] Radio y altura deben ser positivos. Usando 1 por defecto."<<endl;
            radio = altura = 1;
        } else {
            radio = r;
            altura = h;
        }
    }

    double volumen() const override {
        return PI * pow(radio, 2) * altura;
    }

    string descripcion() const override {
        return "Cilindro de radio " + to_string(radio) + " y altura " + to_string(altura);
    }
};

// ============== PIRAMIDE CUADRADA ===============
class PiramideCuadrada : public Figura3D {
private:
    double base;
    double altura;
public:
    PiramideCuadrada(double b, double h) {
        if (b <= 0 || h <= 0) {
            cout << "[Error] Base y altura deben ser positivos. Usando 1 por defecto."<<endl;
            base = altura = 1;
        } else {
            base = b;
            altura = h;
        }
    }

    double volumen() const override {
        return (1.0 / 3.0) * pow(base, 2) * altura;
    }

    string descripcion() const override {
        return "Piramide cuadrada de base " + to_string(base) + " y altura " + to_string(altura);
    }
};

// ==================== MAIN ====================
int main() {
    const int N = 6;
    Figura3D* figuras[N];

    // Crear las figuras
    figuras[0] = new Cubo(4);
    figuras[1] = new Esfera(3);
    figuras[2] = new Cilindro(2, 5);
    figuras[3] = new PiramideCuadrada(6, 10);
    figuras[4] = new Esfera(1.5);
    figuras[5] = new Cubo(2);

    double volumenTotal = 0;
    int indiceMax = 0;
    int indiceMin = 0;

    cout << fixed;
    cout.precision(2);

    cout <<endl<<"==== Volumenes de las figuras ===="<<endl;
    for (int i = 0; i < N; i++) {
        double v = figuras[i]->volumen();
        cout << "Figura " << (i + 1) << ": " << figuras[i]->descripcion()
             << " → Volumen: " << v << endl;

        volumenTotal += v;

        if (v > figuras[indiceMax]->volumen()) {
            indiceMax = i;
        }
        if (v < figuras[indiceMin]->volumen()) {
            indiceMin = i;
        }
    }

    cout <<endl<<"Volumen total de todas las figuras: " << volumenTotal << endl;
    cout << "Figura de mayor volumen: " << figuras[indiceMax]->descripcion()
         << " → " << figuras[indiceMax]->volumen() << endl;
    cout << "Figura de menor volumen: " << figuras[indiceMin]->descripcion()
         << " → " << figuras[indiceMin]->volumen() << endl;

    // Liberar memoria
    for (int i = 0; i < N; i++) {
        delete figuras[i];
    }

    return 0;
}
