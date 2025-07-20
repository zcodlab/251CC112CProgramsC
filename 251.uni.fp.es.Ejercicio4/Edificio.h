#ifndef EDIFICIO_H
#define EDIFICIO_H
#include "HuellaDeCarbono.h"
class Edificio : public HuellaDeCarbono {
private:
    double usoElectricidadKWh;
public:
    Edificio(double usoElectricidad);
    double getHuellaDeCarbono() const override;
    void imprimirInfo() const override;
};
#endif // EDIFICIO_H
