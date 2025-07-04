#include <iostream>
#include <vector>
#include <memory>

#include "CarbonFootprint.h"
#include "Building.h"
#include "Car.h"
#include "Bicycle.h"

using namespace std;

int main() {
    //vector de punteros que apuntan a objetos de tipo CarbonFootprint
    //Permite polimorfismo: puedes almacenar en el vector objetos Building, Car, Bicycle, etc., todos como shared_ptr<CarbonFootprint>.
    //permite esta conversion porque Building, Car, Bicycle heredan de CarbonFootprint.
    vector<shared_ptr<CarbonFootprint>> objetos;

    objetos.push_back(make_shared<Building>(12000));  // 12000 kWh/anio
    /*
    *shared_ptr<CarbonFootprint> ptr = shared_ptr<Building>(new Building(12000));
    *objetos.push_back(ptr);
    *make_shared es mas limpio, mas rapido, y evita errores comunes.
    */
    objetos.push_back(make_shared<Car>(850));         // 850 litros/anio
    objetos.push_back(make_shared<Bicycle>(12));      // 12 horas de mantenimiento
    /*
    forma moderna y eficiente de iterar sobre todos los elementos del contenedor objetos (vector<shared_ptr<CarbonFootprint>>)
    auto: El compilador deduce automaticamente el tipo de cada elemento (shared_ptr<CarbonFootprint>)
    & (referencia): Se accede a cada elemento por referencia, evitando copias innecesarias
    */
    for (const auto& obj : objetos) {
        obj->printInfo();
        cout << "Huella de carbono: " << obj->getCarbonFootprint() << " kg CO2/anio"<<endl<<endl;
    }

    return 0;
}
