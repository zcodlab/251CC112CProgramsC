#include <iostream>
using namespace std;

struct coordenada{
    float _X;
    float _Y;
    string nombre;
};

struct arista{
    coordenada P1;
    coordenada P2;
    float distancia;
    string nombre;
};


int main()
{  string A,B,C;//triangulo con 3 vertices
    float x1,x2,x3,y1,y2,y3,area;
    arista D1,D2,D3//triangulo con 3 aristas
    //ingreso de datos
    cin.ignore();
    cout << "Ingrese el nombre del primer vertice" << endl;
    getline(cin,A);
    cout << "Ingrese la coordenada x del primer vertice" << endl;
    cin>>x1;
    cout << "Ingrese la coordenada y del primer vertice" << endl;
    cin>>y1;
    cout << "Ingrese el nombre del segundo vertice" << endl;
    getline(cin,B);
    cout << "Ingrese la coordenada x del segundo vertice" << endl;
    cin>>x2;
    cout << "Ingrese la coordenada y del segundo vertice" << endl;
    cin>>y2;
    cout << "Ingrese el nombre del tercer vertice" << endl;
    getline(cin,C);
    cout << "Ingrese la coordenada x del tercer vertice" << endl;
    cin>>x3;
    cout << "Ingrese la coordenada y del tercer vertice" << endl;
    cin>>y3;
    //inicializando
    InicializarArista(&D1,A,B,x1,y1,x2,y2);
    InicializarArista(&D2,B,C,x2,y2,x3,y3);
    InicializarArista(&D3,C,A,x3,y3,x1,y1);
    area=calcularArea(D1,D2,D3);
    //mostrar resultados
    mostrarArista(D1);
    mostrarArista(D2);
    mostrarArista(D3);
    cout<<"El area del triangulo formado por las 3 aristas es: "    <<area<<endl;
    return 0;
}
