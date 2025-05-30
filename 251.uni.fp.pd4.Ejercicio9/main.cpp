#include <iostream>
using namespace std;

struct Libro{
    string titulo;
    string autor;
    int anioPublicacion;
    int numPaginas;
};

void ingresarLibros(Libro* &biblioteca,int &numLibros){
        cout<<"Ingrese el numero de libros a registrar:";
        cin>>numLibros;
        //aplicando asignacion dinamica
        biblioteca=new Libro[numLibros];//biblioteca es una rreglo de elementos de tipo Libro
        for(int i=0;i<numLibros; i++)
        {
            cout<<"Ingrese los detalles del libro #"<<i+1<<":"<<endl;
            cout<<"Titulo: ";
            cin.ignore();
            getline(cin,biblioteca[i].titulo);
            cout<<"Autor: ";
            getline(cin,biblioteca[i].autor);
            cout<<"Año de Publicacion: ";
            cin>>biblioteca[i].anioPublicacion;
            cout<<"Numero de Paginas: ";
            cin>>biblioteca[i].numPaginas;
        }
}
void mostrarLibros(Libro* biblioteca,int numLibros){
     cout<<"-------------------Lista de Libros:--------------------------------------  "<<endl;
     for(int i=0;i<numLibros; i++){
         cout<<"Titulo: "<<biblioteca[i].titulo<<endl;
         cout<<"Autor: "<<biblioteca[i].autor<<endl;
         cout<<"Año de Publicacion: "<<biblioteca[i].anioPublicacion<<endl;
         cout<<"Numero de Paginas: "<<biblioteca[i].numPaginas<<endl;
         cout<<"------------------------------------------------------------------------"<<endl;
     }
}

void buscarLibrosPorAutor(Libro* biblioteca,int numLibros,const string &autorBuscado){
    cout<<"Libros del autor "<<autorBuscado<<": "<<endl;
     for(int i=0;i<numLibros; i++)
        if(biblioteca[i].autor.compare(autorBuscado)==0)
            cout<<"Titulo: "<<biblioteca[i].titulo<<endl;
}

int main()
{
    Libro* biblioteca=NULL;
    int numLibros=0;
    ingresarLibros(biblioteca,numLibros);
    mostrarLibros(biblioteca,numLibros);

    string autorBuscado;
    cout << "Ingrese el autor a buscar: ";
    cin.ignore();
    getline(cin,autorBuscado);
    buscarLibrosPorAutor(biblioteca,numLibros,autorBuscado);

    delete[] biblioteca;//liberando el espacio de memoria utilizado
    return 0;
}
