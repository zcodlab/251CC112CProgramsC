#include <iostream>
#include "rectangulo.h"
using std::cout;
using std::endl;

int main()
{
    cout << "Rectangulo 1:"<<endl;
    Rectangulo r1(2, 1, 8, 1, 8, 5, 2, 5);
    r1.mostrarDatos();
    cout <<endl;
    cout << "Rectangulo 2:"<<endl;
    Rectangulo r2(1, 1, 5, 1, 5, 5, 1, 5);
    r2.mostrarDatos();

    return 0;
}
