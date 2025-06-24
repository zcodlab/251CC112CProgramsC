#include <iostream>
#include <iomanip>
#include "Package.cpp"
#include "TwoDayPackage.cpp"
#include "Package.h"
#include "TwoDayPackage.h"
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main() {
    cout << fixed << setprecision(2);

    Package p1("Ana", "Calle 1", "Lima", "Lima", "1001",
               "Luis", "Av. 2", "Cusco", "Cusco", "2002", 5.0, 2.0);

    TwoDayPackage p2("Ana", "Calle 1", "Lima", "Lima", "1001",
                     "Luis", "Av. 2", "Cusco", "Cusco", "2002", 5.0, 2.0, 3.0);

    p1.mostrarInfo();
    cout << "Costo: S/" << p1.calculateCost() <<endl<<endl;

    p2.mostrarInfo();
    cout << "Costo: S/" << p2.calculateCost() <<endl;

    return 0;
}
