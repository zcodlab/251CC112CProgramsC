#ifndef CARBONFOOTPRINT_H
#define CARBONFOOTPRINT_H

class CarbonFootprint {
public:
    virtual double getCarbonFootprint() const = 0;
    virtual void printInfo() const = 0;
    virtual ~CarbonFootprint() = default;
};

#endif // CARBONFOOTPRINT_H
