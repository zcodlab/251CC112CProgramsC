//programa que inicializa un miembro dato const,
#include <iostream>
using namespace std;
class Increment{
//miembros dato
private:
    int count;
    const int increment;    //miembro dato const
//funciones miembro
public:
    //constructor
    Increment(int c=0,int i=1);
    //funciones miembro
    void addIncrement(){
        count+=increment;}  //acumula en cuenta el valor de la const increment
    void print() const;         //es const por que no altera ninguno de los miembros dato
};
//implementacion del constructor
Increment::Increment(int c,int i): increment(i) //inicializamos el miembro dato increment con el valor i, pues increment es const
{    count=c;  }
//imprimir la data
void Increment::print() const{  //const, por que no altera la informacion de los miembros dato
    cout<<"count= "<<count<<" , increment= "<<increment<<endl;
}

int main()
{
    //declaracion el objeto value, precisando en su constructor los valores con los que se inicializa sus miembros dato
    Increment value(10,5);
    //observamos el contenido de los miembros dato del objeto
    cout<<"antes de incrementar: ";
    value.print();
    //realizaremos 3 incrementos para observar el comportamiento de los miembros dato
    for(int j=0; j<3;j++){
            value.addIncrement();
            cout<<"despues del incremento: "<<j+1<<": ";
            value.print();
    }
    return 0;
}
