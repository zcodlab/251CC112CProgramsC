#include <iostream>
#include <string>
using namespace std;
struct Estudiante{
    string nombre;
    float nota;
};
int main()
{
    int n;
    cout << "Ingrese el numero de estudiantes:" ;
    cin>>n;
    //creando un puntero a estructura
    Estudiante* estudiantes=new Estudiante[n];
    cin.ignore();//limpiando el buffer
    for(int i=0;i<n;i++){
            cout<<"Ingrese el nombre del estudiante "<<i+1<<":";
            getline(cin,estudiantes[i].nombre);
            cout<<"Ingrese el nota del estudiante "<<i+1<<":";
            cin>>estudiantes[i].nota;
            cin.ignore();
    }
    //determinando el estudiante con mayor nota
    int indiceMayorNota=0;
    float mayorNota=estudiantes[0].nota;
    for(int i=1;i<n;i++){
        if(estudiantes[i].nota>mayorNota){
            mayorNota=estudiantes[i].nota;
            indiceMayorNota=i;
         }
    }
    //imprimir el estudiante con mayor nota
    cout<<"El estudiante con mayor nota es:"<<estudiantes[indiceMayorNota].nombre<<endl;
    cout<<"Nota: "<<estudiantes[indiceMayorNota].nota<<endl;
    delete[] estudiantes;
    return 0;
}
