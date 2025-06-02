#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

// Función para eliminar espacios y signos de puntuación
void limpiarCadena(char* cadena) {
    char* destino = cadena;
    while (*cadena != '\0') {
        if (isalpha(*cadena)) {
            *destino = *cadena;
            destino++;
        }
        cadena++;
    }
    *destino = '\0';
}

// Función para invertir la cadena completa
void invertirCadena(char* cadena) {
    int len = strlen(cadena);
    for (int i = 0; i < len / 2; i++) {
        char temp = cadena[i];
        cadena[i] = cadena[len - 1 - i];
        cadena[len - 1 - i] = temp;
    }
}

// Función para imprimir substrings de longitud creciente
void imprimirSubstrings(char* cadena) {
    int len = strlen(cadena);
    int inicio = 0;
    int longitud = 1;

    while (inicio + longitud <= len) {
        cout << "Substring de longitud " << longitud << ": ";
        for (int i = 0; i < longitud; i++) {
            cout << *(cadena + inicio + i);
        }
        cout << endl;

        inicio += longitud;
        longitud++;
    }
}

int main() {
    char entrada[256];

    cout << "Ingrese una cadena: ";
    cin.getline(entrada, 256);

    // Paso 1: limpiar la cadena
    limpiarCadena(entrada);

    // Paso 2: invertir la cadena
    invertirCadena(entrada);

    // Paso 3: imprimir substrings de longitud creciente
    imprimirSubstrings(entrada);

    return 0;
}

