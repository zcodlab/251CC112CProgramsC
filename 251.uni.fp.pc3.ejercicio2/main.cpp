#include <iostream>
#include <cmath>
using namespace std;

const float PI = 3.141592;

struct PUNTO2D {
    float x;
    float y;
};

struct POLIGONAL {
    int numv;
    PUNTO2D* vertices;
};

POLIGONAL* crearPoligonoRegular(int n, float R) {
    POLIGONAL* poligono = new POLIGONAL;
    poligono->numv = n + 1;
    float ang0 = 2 * PI / (poligono->numv - 1);
    poligono->vertices = new PUNTO2D[poligono->numv];

    for (int i = 0; i < poligono->numv; i++) {
        poligono->vertices[i].x = R * cos(i * ang0);
        poligono->vertices[i].y = R * sin(i * ang0);
    }

    return poligono;
}

void imprimirPoligono(const POLIGONAL* poligono, const string& titulo) {
    cout << titulo << endl;
    for (int i = 0; i < poligono->numv; i++) {
        cout << "(" << poligono->vertices[i].x << ";" << poligono->vertices[i].y << ") "<<endl;
    }
    cout << endl;
}

POLIGONAL* crearPoligonoFinal(const POLIGONAL* p) {
    POLIGONAL* c = new POLIGONAL;
    c->numv = 4 * p->numv - 3;
    c->vertices = new PUNTO2D[c->numv];

    int j = 0;
    for (int i = 0; i < p->numv - 1; i++) {
        float dx = p->vertices[i + 1].x - p->vertices[i].x;
        float dy = p->vertices[i + 1].y - p->vertices[i].y;

        c->vertices[j].x = p->vertices[i].x;
        c->vertices[j].y = p->vertices[i].y;

        c->vertices[j + 1].x = p->vertices[i].x + (1 / 3.0) * dx;
        c->vertices[j + 1].y = p->vertices[i].y + (1 / 3.0) * dy;

        c->vertices[j + 3].x = p->vertices[i].x + (2 / 3.0) * dx;
        c->vertices[j + 3].y = p->vertices[i].y + (2 / 3.0) * dy;

        c->vertices[j + 2].x = p->vertices[i].x + 0.5 * dx + (sqrt(3) / 6) * (dy);
        c->vertices[j + 2].y = p->vertices[i].y + 0.5 * dy + (sqrt(3) / 6) * (-dx);

        j += 4;
    }

    c->vertices[c->numv - 1].x = p->vertices[p->numv - 1].x;
    c->vertices[c->numv - 1].y = p->vertices[p->numv - 1].y;

    return c;
}

void liberarPoligono(POLIGONAL* poligono) {
    delete[] poligono->vertices;
    delete poligono;
}

int main() {
    int n;
    float R;

    cout << "Ingrese el numero de vertices: ";
    cin >> n;
    cout << "Ingrese el radio del poligono regular: ";
    cin >> R;

    POLIGONAL* p = crearPoligonoRegular(n, R);
    imprimirPoligono(p, "Los vertices del poligono inicial son:");

    POLIGONAL* c = crearPoligonoFinal(p);
    imprimirPoligono(c, "Los vertices del poligono final son:");

    liberarPoligono(p);
    liberarPoligono(c);

    return 0;
}
