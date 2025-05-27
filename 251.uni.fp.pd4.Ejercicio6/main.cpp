#include <iostream>
#include <cmath>
using namespace std;

struct Punto{
    double x;
    double y;
    double z;
};

int main()
{
    Punto punto1,punto2;
    cout << "Ingrese las coordenadas del primer punto:" << endl;
    cout << "X:";
    cin>>punto1.x;
    cout << "Y:";
    cin>>punto1.y;
    cout << "Z:";
    cin>>punto1.z;
    cout << "Ingrese las coordenadas del segundo punto:" << endl;
    cout << "X:";
    cin>>punto2.x;
    cout << "Y:";
    cin>>punto2.y;
    cout << "Z:";
    cin>>punto2.z;

    double dx=punto2.x-punto1.x;
    double dy=punto2.y-punto1.y;
    double dz=punto2.z-punto1.z;
    double distancia=sqrt(dx*dx + dy*dy + dz*dz);
    cout<<"La distancia entre los dos puntos es:"<<distancia<<endl;
    return 0;
}
