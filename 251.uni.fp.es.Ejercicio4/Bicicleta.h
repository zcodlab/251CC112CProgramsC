#ifndef BICICLETA_H
#define BICICLETA_H
#include "HuellaDeCarbono.h"
class Bicicleta : public HuellaDeCarbono {
private:
    double horasMantenimiento;
public:
    Bicicleta(double horasMnto);
    double getHuellaDeCarbono() const override;
    void imprimirInfo() const override;
};
#endif // BICICLETA_H
