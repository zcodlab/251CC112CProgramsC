#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int EsNombreValido(char *p) {
    int len = strlen(p);
    if (len == 0)
        return 1; // Cadena vacía es inválida (posición 1)
    // Regla b: debe comenzar con letra o guion bajo
    if (!isalpha(p[0]) && p[0] != '_')
        return 1;
    for (int i = 0; i < len; ++i) {
        char c = p[i];
        // Regla a: solo letras, dígitos o guion bajo
        if (!isalnum(c) && c != '_')
            return i + 1;
        // Regla c: no puede contener espacios
        if (isspace(c))
            return i + 1;
        // Regla d: no puede tener '__'
        if (c == '_' && p[i + 1] == '_')
            return i + 1;
    }
    return 0; // Todo está correcto
}

int main()
{
   char nombre[100];
    cout << "Ingrese un nombre de variable: ";
    cin.getline(nombre, 100);
    int resultado = EsNombreValido(nombre);
    if (resultado == 0)
        cout << "El nombre de variable es válido.\n";
    else
        cout << "Error en la posición " << resultado << ": '" << nombre[resultado - 1] << "'\n";
    return 0;
}
