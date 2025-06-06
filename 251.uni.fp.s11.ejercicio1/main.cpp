#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ofstream archivo("saludo.txt");//crea un archivo fisico
    archivo<<"Hola, mundo";   //escribiendo datos en el archivo
    archivo.close();
    return 0;
}
