#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstddef>

using namespace std;
struct Usuario {
	int id;
	char nombre[80];
	double saldo;
};
// Crea archivo binario con usuarios
void creaArchivoUsuarios(const char* nombreArchivo, int n) {
	ofstream archivo(nombreArchivo, ios::binary);
	if (!archivo) {
		cerr << "Error al crear archivo."<<endl;
		return;
	}
	Usuario usuario;
	for (int i=0;i<n;i++){
		cout<<"Nuevo Usuario"<<endl;
		cout<<"\tCodigo: "; cin>>usuario.id;
		cin.get();
		cout<<"\tNombre: "; cin.getline(usuario.nombre,80);
		cout<<"\tSaldo: "; cin>>usuario.saldo;
		archivo.write(reinterpret_cast<const char*>(&usuario), sizeof(Usuario));
	}
	archivo.close();
	cout << "Archivo creado."<<endl;
}
// Lista de usuarios en el archivo
void listaUsuarios(const char* nombreArchivo) {
	ifstream archivo(nombreArchivo, ios::binary);
	if (!archivo) {
		cerr << "Error al abrir archivo para lectura."<<endl;
		return;
	}
	Usuario usuario;
	cout << fixed << setprecision(2);
	cout << "Contenido del archivo:"<<endl;
	while (archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuario))) {
		cout << "Codigo: " <<setw(5)<< usuario.id
		<< " | Nombre: " <<setw(10)<< usuario.nombre
		<< " | Saldo: " <<setw(5)<< usuario.saldo <<endl;
	}
	archivo.close();
}
// busca usuario y actualiza el saldo
void incrementarSaldoUsuario(const char* nombreArchivo) {
	fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);

	if (!archivo) {
		cerr << "Error al abrir el archivo."<<endl;
		return;
	}
	int codigo;
	double incremento;
	cout<<"Modificacion de saldo"<<endl;
	cout<<"\tCodigo de usuario: ";
	cin>>codigo;
	cout<<"\tIncremento de saldo: ";
	cin>>incremento;
	Usuario usuario;
	while (archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuario))) {
		if (usuario.id == codigo) {
			// posicion actual
			streampos posRegistro = archivo.tellg() - streamoff(sizeof(Usuario));
			// posicion del campo saldo
			streampos posSaldo = posRegistro + offsetof(Usuario,saldo);

			double nuevoSaldo = usuario.saldo + incremento;

			archivo.seekp(posSaldo);
			archivo.write(reinterpret_cast<char*>(&nuevoSaldo), sizeof(double));

			cout << "Saldo actualizado correctamente."<<endl;
			archivo.close();
			return;
		}
	}
	cout << "Usuario con codigo " << codigo << " no existe."<<endl;
	archivo.close();
}
int main() {
	const char* nombreArchivo = "usuarios.dat";
	int numUsuarios;
	cout<<"Numero de usuarios: "; cin>>numUsuarios;
	creaArchivoUsuarios(nombreArchivo,numUsuarios);
	listaUsuarios(nombreArchivo);
	incrementarSaldoUsuario(nombreArchivo);
	cout <<endl<< "Despues de modificar el saldo:"<<endl;
	listaUsuarios(nombreArchivo);
}
