#include <iostream>
using namespace std;
class Persona{
  private:
      string nombre;
  public:
      //constructor, debe tener el mismo nombre de la clase
      Persona(string n){
          //Uso del operador this.
          this->nombre=n;
          cout<< "Constructor llamado para "<<nombre<<endl;
      }
      //Destructor, obtenemos la virgula: ALT+126
      ~Persona(){
          cout<< "Destructor llamado para "<<nombre<<endl;
      }
      void saludar(){
          cout<< "Hola, soy "<<nombre<<endl;
      }
};

int main()
{
    Persona  p("Carlos");
    p.saludar();
    return 0;
}
