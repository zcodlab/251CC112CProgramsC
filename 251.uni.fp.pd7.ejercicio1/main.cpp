#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int META = 70;

// Funcion para mover a la tortuga
void moverTortuga(int* pos) {
    int i = rand() % 50 + 1;

    if (i <= 25)         // Paso rapido (50%)
        *pos += 3;
    else if (i <= 33)    // Deslizamiento (16%)
        *pos -= 6;
    else                 // Paso lento (34%)
        *pos += 1;

    if (*pos < 1) *pos = 1;
    if (*pos > META) *pos = META;
}

// Funcion para mover a la liebre
void moverLiebre(int* pos) {
    int i = rand() % 50 + 1;

    if (i <= 19)         // Sueño (38%)
        ;                // Sin movimiento
    else if (i <= 27)    // Gran salto (16%)
        *pos += 11;
    else if (i <= 35)    // Gran deslizamiento (16%)
        *pos -= 9;
    else if (i <= 45)    // Pequeño salto (20%)
        *pos += 1;
    else                // Pequeño deslizamiento (10%)
        *pos -= 2;

    if (*pos < 1) *pos = 1;
    if (*pos > META) *pos = META;
}

// Funcion para mostrar el estado de la pista
void mostrarPista(int tortuga, int liebre) {
    //una variable string puede ser accedida como si fuera un arreglo de caracteres usando el operador [].
    // Crea una cadena de 70 espacios y lo inicializa con espacio en blanco
    string pista(META, ' ');

    if (tortuga == liebre) {
        if (tortuga <= META - 3)
            //pista.replace(pos_inicial, longitud_a_reemplazar, nuevo_texto);
            pista.replace(tortuga - 1, 3, "¡AY!");
        else
            pista[tortuga - 1] = 'A'; // ambos caen en la misma casilla
    } else {
        if (tortuga >= 1 && tortuga <= META)
            pista[tortuga - 1] = 'T';
        if (liebre >= 1 && liebre <= META)
            pista[liebre - 1] = 'L';
    }

    cout << pista << endl;
}

int main() {
     srand(time(nullptr));
    // Asignacion dinamica de memoria
    int* posTortuga = new int(1);
    int* posLiebre = new int(1);

    cout << "¡¡¡BANG!!!!!"<< endl<<"¡¡¡Y YA SALE!!!!!"<< endl<< endl;

    while (true) {
        moverTortuga(posTortuga);
        moverLiebre(posLiebre);
        mostrarPista(*posTortuga, *posLiebre);

        if (*posTortuga >= META && *posLiebre >= META) {
            cout <<endl<<"¡¡¡GANA LA TORTUGA!!!!" << endl;  // Se favorece a la tortuga
            break;
        } else if (*posTortuga >= META) {
            cout <<endl<<"¡¡¡GANA LA TORTUGA!!!!" << endl;
            break;
        } else if (*posLiebre >= META) {
            cout <<endl<<"¡¡¡GANA LA LIEBRE!!!" << endl;
            break;
        }
    }

    // Liberar memoria
    delete posTortuga;
    delete posLiebre;

    return 0;
}
