#include "time5.cpp"
#include "time5.h"
int main()
{
    //1 objeto de tipo Time
    Time wakeUp(6,45,0);    //objeto no-const
    //2 objeto de tipo Time
    Time noon(12,0,0); //declarando e invocando a su constructor

    wakeUp.setHour(18);
    noon.setHour(12);

    wakeUp.printStandard();

    noon.printMilitary();
    noon.printStandard();
    return 0;
}
