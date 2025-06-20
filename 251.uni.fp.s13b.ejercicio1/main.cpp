#include <iostream>
using namespace std;
class Persona{
  private:
      string nombre;
      int edad;
  public:
      void setDatos(string n,int e){
          nombre=n;
              edad=e;
      }
      void mostrar(){
          cout<<"Nombre: "<<nombre<<", Edad: "<<edad<<endl;
      }
};
int main()
{
    Persona p1,p2;
    //objeto1
    p1.setDatos("Ana",30);
    p1.mostrar();
    //objeto2
    p2.setDatos("Juan",22);
    p2.mostrar();
    return 0;
}
