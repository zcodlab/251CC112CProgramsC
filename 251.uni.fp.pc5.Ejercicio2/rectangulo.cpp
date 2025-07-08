#include "Rectangulo.h"
#include <iostream>
#include <cmath>
#include <iomanip>
const double COMPARADOR_MIN=1e-3;
const double RANGO_INI=0;
const double RANGO_FIN=20.0;
using namespace std;

bool Rectangulo::dentroDelRango(Punto p) {
    return (p.x >= RANGO_INI && p.x <= RANGO_FIN && p.y >= RANGO_INI && p.y <= RANGO_FIN);
}

bool Rectangulo::coordenadasValidas(Punto a, Punto b, Punto c, Punto d) {
    return dentroDelRango(a) && dentroDelRango(b) &&
           dentroDelRango(c) && dentroDelRango(d);
}

double Rectangulo::distancia(Punto a, Punto b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

bool Rectangulo::esRectangulo(Punto a, Punto b, Punto c, Punto d) {
    double d1 = distancia(a, b);
    double d2 = distancia(b, c);
    double d3 = distancia(c, d);
    double d4 = distancia(d, a);
    double diag1 = distancia(a, c);
    double diag2 = distancia(b, d);

    return fabs(d1 - d3) < COMPARADOR_MIN &&
           fabs(d2 - d4) < COMPARADOR_MIN &&
           fabs(diag1 - diag2) < COMPARADOR_MIN;
}

void Rectangulo::calcularLargoAncho() {
    double lado1 = this->distancia(p1, p2);
    double lado2 = this->distancia(p2, p3);
    this->largo = max(lado1, lado2);
    this->ancho = min(lado1, lado2);
}

Rectangulo::Rectangulo(double x1, double y1, double x2, double y2,
                       double x3, double y3, double x4, double y4) {
    Punto a = {x1, y1}, b = {x2, y2}, c = {x3, y3}, d = {x4, y4};
    if (!coordenadasValidas(a, b, c, d)) {
        cerr << "Coordenadas fuera del rango permitido (0-20)."<<endl;
        exit(1);
    }
    if (!esRectangulo(a, b, c, d)) {
        cerr << "Las coordenadas no forman un rectangulo valido."<<endl;
        exit(1);
    }

    this->p1 = a;
    this->p2 = b;
    this->p3 = c;
    this->p4 = d;

    this->calcularLargoAncho(); // uso de this
}

double Rectangulo::getLargo() const {
    return this->largo;
}

double Rectangulo::getAncho() const {
    return this->ancho;
}

double Rectangulo::getArea() const {
    return this->largo * this->ancho;
}

double Rectangulo::getPerimetro() const {
    return 2 * (this->largo + this->ancho);
}

bool Rectangulo::esCuadrado() const {
    return fabs(this->largo - this->ancho) < COMPARADOR_MIN;
}

void Rectangulo::mostrarDatos() const {
    cout << fixed << setprecision(2);
    cout << "Largo: " << this->getLargo() << endl;
    cout << "Ancho: " << this->getAncho() << endl;
    cout << "Area: " << this->getArea() << endl;
    cout << "Perimetro: " << this->getPerimetro() << endl;
    cout << (this->esCuadrado() ? "Es un cuadrado." : "No es un cuadrado.")<<endl;
}

Rectangulo::~Rectangulo() {
    cout << "Destructor llamado: liberando memoria del objeto Rectangulo: ["<<this->getLargo()<<","<<getAncho()<<"]"<<endl;
}
