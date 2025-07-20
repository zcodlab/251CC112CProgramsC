#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H
#include "HuellaDeCarbono.h"
class Automovil : public HuellaDeCarbono {
private:
    double gasoLitrosPorAnio;
public:
    Automovil(double gasoLitros);
    double getHuellaDeCarbono() const override;
    void imprimirInfo() const override;
};
#endif // AUTOMOVIL_H
