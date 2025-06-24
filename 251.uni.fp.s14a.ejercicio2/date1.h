#ifndef DATE1_H
#define DATE1_H
class Date{
private:
    int month;    //1-12
    int day;        //1-31 segun el mes
    int year;       //cualquier año
    //funcion de utilidad para testear(probar) dia para un mes y año correcto
    int checkDay(int);
public:
    //constructor de la clase
    Date(int=1,int=1,int=1900);
    void print() const;
    //destructor de la clase
    ~Date();    //para observar el orden de destruccion de los objetos creados
};


#endif // DATE1_H
