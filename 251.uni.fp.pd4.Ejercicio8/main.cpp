#include <iostream>
#include <cmath>
#include <string>
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
void InicializarArista(arista *A,string np1,string np2,float x1, float y1, float x2,float y2 ){
    A->P1.nombre=np1;
    A->P2.nombre=np2;
    A->P1._X=x1;
    A->P1._Y=y1;
    A->P2._X=x2;
    A->P2._Y=y2;
    A->nombre=A->P1.nombre+"-"+A->P2.nombre;
    A->distancia=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}
float calcularArea(arista a,arista b,arista c){
    //aplicando el metodo de heron
    float s=(a.distancia+b.distancia+c.distancia)/2.0;
    float area=sqrt(s*(s-a.distancia)*(s-b.distancia)*(s-c.distancia));
    return area;
}
void mostrarArista(arista A){
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"Nombre de arista:"<<A.nombre<<endl;
    cout<<"Coordenadas del punto:"<<A.P1.nombre<<": ("<<A.P1._X<<","<<A.P1._Y<<")"<<endl;
    cout<<"Coordenadas del punto:"<<A.P2.nombre<<": ("<<A.P2._X<<","<<A.P2._Y<<")"<<endl;
    cout<<"Distancia de la arista: "<<A.distancia<<endl;
}

int main()
{  string A,B,C;//triangulo con 3 vertices
    float x1,x2,x3,y1,y2,y3,area;
    arista D1,D2,D3;//triangulo con 3 aristas
    //ingreso de datos
    cout << "Ingrese el nombre del primer vertice: ";
    getline(cin,A);
    cin.ignore();
    cout << "Ingrese la coordenada x del primer vertice: " << endl;
    cin>>x1;
    cout << "Ingrese la coordenada y del primer vertice: " << endl;
    cin>>y1;
    cin.ignore();
    cout << "Ingrese el nombre del segundo vertice: " << endl;
    getline(cin,B);
    cout << "Ingrese la coordenada x del segundo vertice: " << endl;
    cin>>x2;
    cout << "Ingrese la coordenada y del segundo vertice: " << endl;
    cin>>y2;
    cin.ignore();
    cout << "Ingrese el nombre del tercer vertice: " << endl;
    getline(cin,C);
    cout << "Ingrese la coordenada x del tercer vertice: " << endl;
    cin>>x3;
    cout << "Ingrese la coordenada y del tercer vertice: " << endl;
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
