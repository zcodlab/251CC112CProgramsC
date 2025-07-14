#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// -------------------- CLASE BASE --------------------
class Sensor {
protected:
    string id;
    string tipo;
    float frecuencia;
public:
    Sensor(string _id, string _tipo, float _frecuencia)
        : id(_id), tipo(_tipo), frecuencia(_frecuencia) {}

    virtual void simularLectura() = 0;
    virtual void mostrarDatos() = 0;

    string getID() const {
        return id;
    }

    virtual ~Sensor() {
        cout << "Destruyendo sensor de tipo: " << tipo << endl;
    }
};

// -------------------- SENSOR TEMPERATURA --------------------
class SensorTemperatura : public Sensor {
    float lectura;
public:
    SensorTemperatura(string _id, float _frecuencia)
        : Sensor(_id, "Temperatura", _frecuencia), lectura(0.0f) {}

    void simularLectura() override {
        lectura = 22.0 + static_cast<float>(rand() % 100) / 100.0;  // [22.0 - 23.0]
    }

    void mostrarDatos() override {
        cout << "[Sensor Temperatura] ID: " << id
             << " | Frecuencia: " << frecuencia << " Hz"
             << " | Lectura: " << lectura << " °C" << endl;
    }

    ~SensorTemperatura() override {}
};

// -------------------- SENSOR DISTANCIA --------------------
class SensorDistancia : public Sensor {
    float distancia;
    float ruido;
public:
    SensorDistancia(string _id, float _frecuencia)
        : Sensor(_id, "Distancia", _frecuencia), distancia(5.0), ruido(0.0) {}

    void simularLectura() override {
        ruido = (rand() % 50) / 100.0;  // ruido  hasta 0.5
        distancia = 5.0 + ruido;
    }

    void mostrarDatos() override {
        cout << "[Sensor Distancia] ID: " << id
             << " | Frecuencia: " << frecuencia << " Hz"
             << " | Lectura: " << distancia << " m"
             << " (ruido: ±" << ruido << " m)" << endl;
    }

    ~SensorDistancia() override {}
};

// -------------------- SENSOR MOVIMIENTO --------------------
class SensorMovimiento : public Sensor {
    float ax, ay, az;
public:
    SensorMovimiento(string _id, float _frecuencia)
        : Sensor(_id, "Movimiento", _frecuencia), ax(0), ay(0), az(0) {}

    void simularLectura() override {
        ax = ((rand() % 400) / 1000.0) - 0.2;  // [-0.2, 0.2]
        ay = ((rand() % 400) / 1000.0) - 0.2;
        az = ((rand() % 400) / 1000.0) - 0.2;
    }

    void mostrarDatos() override {
        cout << "[Sensor Movimiento] ID: " << id
             << " | Frecuencia: " << frecuencia << " Hz"
             << " | Aceleración: ax=" << ax << " ay=" << ay << " az=" << az << " m/s²" << endl;
    }

    ~SensorMovimiento() override {}
};

// Parte 2
// -------------------- CLASE DRON --------------------
const int MAX_SENSORES = 3;

class Dron {
private:
    float x, y, z;
    Sensor* sensores[MAX_SENSORES];
    int numSensores;
public:
    Dron() : x(0), y(0), z(0), numSensores(0) {}

    bool agregarSensor(Sensor* s) {
        if (numSensores < MAX_SENSORES) {
            sensores[numSensores++] = s;
            return true;
        }
        cout << "Error: no se puede agregar más sensores (maximo alcanzado)." << endl;
        return false;
    }

    bool eliminarSensorPorID(const string& id) {
        for (int i = 0; i < numSensores; ++i) {
            if (sensores[i]->getID() == id) {
                delete sensores[i];
                // mover los restantes
                for (int j = i; j < numSensores - 1; ++j) {
                    sensores[j] = sensores[j + 1];
                }
                numSensores--;
                return true;
            }
        }
        return false;
    }

    void mover(float nuevoX, float nuevoY, float nuevoZ) {
        x = nuevoX;
        y = nuevoY;
        z = nuevoZ;
    }

    void mostrarPosicion() const {
        cout<<endl<<"Posicion actual del dron: (" << x << ", " << y << ", " << z << ")"<<endl;
    }

    void simularSensores() {
        cout <<endl<<"Simulando sensores..." << endl;
        for (int i = 0; i < numSensores; ++i) {
            sensores[i]->simularLectura();
            sensores[i]->mostrarDatos();
        }
    }

    ~Dron() {
        cout <<endl<<"Destruyendo dron y liberando sensores..." << endl;
        for (int i = 0; i < numSensores; ++i) {
            delete sensores[i];
        }
    }
};

// -------------------- FUNCION PRINCIPAL --------------------
int main() {
    srand((time(0)));

    Dron miDron;

    // Agregar sensores
    miDron.agregarSensor(new SensorTemperatura("T-001", 1.0));
    miDron.agregarSensor(new SensorDistancia("D-101", 0.5));
    miDron.agregarSensor(new SensorMovimiento("M-500", 2.0));

    // Estado inicial
    miDron.mostrarPosicion();
    miDron.simularSensores();

    // Mover el dron
    miDron.mover(15.0, 5.0, 3.0);
    miDron.mostrarPosicion();

    // Eliminar sensor
    if (miDron.eliminarSensorPorID("D-101")) {
        cout <<endl<<"Sensor D-101 eliminado correctamente." << endl;
    } else {
        cout <<endl<< "Sensor no encontrado." << endl;
    }

    // Simular nuevamente
    miDron.simularSensores();

    return 0;
}
