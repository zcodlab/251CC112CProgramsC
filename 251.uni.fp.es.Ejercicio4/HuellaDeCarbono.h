#ifndef HUELLADECARBONO_H
#define HUELLADECARBONO_H
class HuellaDeCarbono {
public:
    virtual double getHuellaDeCarbono() const = 0;
    virtual void imprimirInfo() const = 0;
    virtual ~HuellaDeCarbono() = default;
};
#endif // HUELLADECARBONO_H
