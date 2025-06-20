#include <iostream>
#include "time5.h"
using std::cout;
using std::endl;

//constructor para inicializar los datos privados
Time::Time(int hr,int min,int sec){
    setTime(hr,min,sec);
}
//
void Time::setTime(int h,int m,int s){
    setHour(h);
    setMinute(m);
    setSecond(s);
}
void Time::setHour(int h){
    //seteamos la hora ingresada por parametro previa validacion,
    //si la hora se encuentra fuera del intervalo [0,24> setea cero como hora
    hour=(h>=0 && h<24)?h:0;
}
void Time::setMinute(int m){
    minute=(m>=0 && m<60)?m:0;
}
void Time::setSecond(int s){
    second=(s>=0 && s<60)?s:0;
}
//funciones get para recuperar los valores de las variables de la clase
int Time::getHour() const{
    return hour;
}

int Time::getMinute() const{
    return minute;
}
int Time::getSecond() const{
    return second;
}
//visualizando el tiempo en formato militar HH:MM
void Time::printMilitary() const{
    cout<<(hour<10 ? "0":"")<<hour<<":"
    <<(minute<10 ? "0":"")<<minute<<endl;
}
//visualizando el tiempo en formato estandar HH:MM:SS AM(O PM))
void Time::printStandard() {
    cout<<((hour==12) ? 12: hour%12)<<":"
    <<(minute<10 ? "0":"")<<minute<<":"
    <<(second<10 ? "0":"")<<second
    <<(hour<12 ? " AM":" PM")<<endl;
}
