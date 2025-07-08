#ifndef RECTANGULO_H
#define RECTANGULO_H
class Rectangulo {
private:
    struct Punto {
        double x, y;
    };

    Punto p1, p2, p3, p4;
    double largo;
    double ancho;

    bool coordenadasValidas(Punto a, Punto b, Punto c, Punto d);
    bool dentroDelRango(Punto p);
    bool esRectangulo(Punto a, Punto b, Punto c, Punto d);
    double distancia(Punto a, Punto b);
    void calcularLargoAncho();

public:
    Rectangulo(double x1, double y1, double x2, double y2,
               double x3, double y3, double x4, double y4);

    double getLargo() const;
    double getAncho() const;
    double getArea() const;
    double getPerimetro() const;
    bool esCuadrado() const;
    void mostrarDatos() const;

    ~Rectangulo();
};


#endif // RECTANGULO_H
