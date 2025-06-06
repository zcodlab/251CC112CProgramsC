#include <fstream>
#include <string>
using namespace std;
int main()
{
    //declarando y creando archivos
    ifstream original("datos.txt");
    ofstream temporal("temporal.txt");
    string linea;
    //recuperando el texto del archivo original en la variable linea
    while(getline(original,linea)){
            if(linea!="Eliminar esto")
                temporal<<linea<<"\n";  //copiando el texto de la variable linea en el segundo archivo: temporal.txt
    }
    //cerrando archivos
    original.close();
    temporal.close();
    //removiendo archivo
    remove("datos.txt");
    //renombrando archivo
    rename("temporal.txt","datos.txt");

    return 0;
}
