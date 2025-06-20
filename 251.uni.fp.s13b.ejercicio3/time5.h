#ifndef TIME5_H
#define TIME5_H
class Time{
    private:
        int hour;//0-23
        int minute; //0-59
        int second; //0-59
    public:
        Time(int=0,int=0,int=0);//constructor predeterminado
         //funciones set, aquellas que permiten asigna valores a las variables de la clase
         void setTime(int,int,int);
         void setHour(int);
         void setMinute(int);
         void setSecond(int);
         //funciones get, aquella que permiten recuperar los valores de las variables de la clase
         int getHour() const;       //retorna hora
         int getMinute() const;     //retorna minuto
         int getSecond() const;     //retorna segundo
         //funciones print
         void printMilitary() const; //imprime el tiempo en formato militar
         void printStandard();
};
#endif // TIME5_H
