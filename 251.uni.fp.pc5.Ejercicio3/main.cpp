#include <iostream>
#include <iomanip>
#include <cmath>
enum TIPO_FIG { TRIANGULO=3, RECTANGULO=4};
bool existe_triangulo(float a, float b, float c){
	if ((a<b+c)&&(b<a+c)&&(c<a+b))
		return true;
	else
		return false;
}
class Figura {
private:
	TIPO_FIG tipo;
	float* medidas;
public:
	// Constructor
	Figura(TIPO_FIG t) : tipo(t) {
		switch (t) {
			case TRIANGULO:{
				medidas=new float[3];
				std::cout << "Ingrese lados a, b, c del triangulo ";
				std::cin >> medidas[0] >> medidas[1] >> medidas[2];
				if (!existe_triangulo(medidas[0], medidas[1], medidas[2])) {
					std::cerr << "Los lados no forman un triangulo válido."<<std::endl;
					delete[] medidas;
					medidas = nullptr;
				}
				break;
			}
			case RECTANGULO:{
				medidas=new float[2];
				std::cout << "Ingrese lados a, b del rectangulo ";
				std::cin >> medidas[0] >> medidas[1];

			}
		}

	}
	// Destructor
	~Figura() {
		delete[] medidas;
	}

	// Metodo para calcular el area usando la formula de Heron
	double calcula_area() const {
		float area=0;
		switch (tipo) {
			case TRIANGULO:{
				if (medidas != nullptr){// el triangulo existe
					float s = ( medidas[0] + medidas[1] + medidas[2])/2.0;
					area = sqrt(s*(s-medidas[0])*(s-medidas[1])*(s-medidas[2]));
				}
				break;
			}
			case RECTANGULO:{
				area =  medidas[0] * medidas[1];
				break;
			}
		}
		return area;
	}
};

int main() {
	int numFigs;
	std::cout << "Ingrese el numero de rectangulos o triangulos: ";
	std::cin >> numFigs;
	Figura* listaFigs[numFigs];
	for(int i=0;i<numFigs;i++){
		int n=0;
		while ((n!=TRIANGULO)&&(n!=RECTANGULO)){
			std::cout << "Ingrese el numero de lados (3 o 4) de la figura: ";
			std::cin >> n;
		}
		switch (n) {
		case 3:
			listaFigs[i] = new Figura(TRIANGULO);
			break;
		case 4:
			listaFigs[i] = new Figura(RECTANGULO);
			break;
		}
	}

	std::cout << std::fixed << std::setprecision(2);
		for (int i = 0; i < numFigs; ++i) {
			std::cout << "Area de la figura " << i + 1 << ": "
			<< listaFigs[i]->calcula_area() << std::endl;
		}

	for (int i = 0; i < numFigs; i++) {
		delete listaFigs[i];
	}
}
