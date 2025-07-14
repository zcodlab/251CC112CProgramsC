#include <iostream>
#include <cstring>
using namespace std;

struct Pagina {
    char* url;
    int tiempoVisita;
    Pagina* siguiente;
};


Pagina* historial = nullptr;

void visitarPagina(const char* url, int tiempo) {
    Pagina* nueva = new Pagina;
    nueva->tiempoVisita = tiempo;

    nueva->url = new char[strlen(url) + 1];
    strcpy(nueva->url, url);

    nueva->siguiente = historial;
    historial = nueva;

    cout << "Visita registrada: " << url << " (" << tiempo << " segundos)" << endl;
}

void mostrarHistorial() {
    cout <<endl<<"Historial de navegacion" << endl;
    Pagina* actual = historial;
    int contador = 1;

    if (!actual) {
        cout << "(Historial vacio)" << endl;
        return;
    }

    while (actual) {
        cout << contador << ". URL: " << actual->url
             << " | Tiempo de visita: " << actual->tiempoVisita << " s" << endl;
        actual = actual->siguiente;
        contador++;
    }
}

bool eliminarPagina(const char* url) {
    Pagina* actual = historial;
    Pagina* anterior = nullptr;

    while (actual) {
        if (strcmp(actual->url, url) == 0) {
            if (anterior == nullptr) {
                historial = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }

            delete[] actual->url;
            delete actual;

            cout <<endl<<"Eliminando pagina: " << url << endl;
            cout << "Pagina eliminada con exito." << endl;
            return true;
        }

        anterior = actual;
        actual = actual->siguiente;
    }

    cout <<endl<<"Pagina no encontrada: " << url << endl;
    return false;
}

void liberarHistorial() {
    Pagina* actual = historial;

    while (actual) {
        Pagina* siguiente = actual->siguiente;
        delete[] actual->url;
        delete actual;
        actual = siguiente;
    }

    historial = nullptr;
    cout <<endl<<"Liberando historial..." << endl;
}

int main() {
    visitarPagina("https://www.uni.edu.pe", 120);
    visitarPagina("https://www.wikipedia.org", 300);
    visitarPagina("https://www.stackoverflow.com", 450);

    mostrarHistorial();

    eliminarPagina("https://www.wikipedia.org");
    mostrarHistorial();

    liberarHistorial();
    mostrarHistorial();

    return 0;
}
