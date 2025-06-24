#include "emply1.cpp"
#include "emply1.h"
using std::cout;
using std::endl;

int main()
{
    //declarando un objeto de tipo Empleado
    Employee e("Bob","Jones",7,24,2000,3,12,2020);
    cout<<endl;
    e.print();
    cout<<"Constructor de prueba de la Date, utilizando valores invalidos"<<endl;
    Date d(14,35,1994);
    cout<<endl;
    return 0;
}
