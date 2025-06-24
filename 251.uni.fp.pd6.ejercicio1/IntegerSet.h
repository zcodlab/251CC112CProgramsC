#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
class IntegerSet{
    private:
        std::vector<bool> elementos;  //miembro dato es un vector de booleanos
    public:
        //1° constructor por defecto, sin parametros, conjunto vacio
        //crea un vector de 101 elemento y lo inicializa en false
        IntegerSet(): elementos(101,false){}
        //2° constructor con arreglo de enteros
        IntegerSet(const std::vector<int>& vals): elementos(101,false){
            for(int val:vals){
                if(val>=0 && val<=100)
                    elementos[val]=true;
            }
        }
        //Union de conjuntos
        static IntegerSet unionOfSets(const IntegerSet& a,const IntegerSet& b){
            IntegerSet result;
            for(int i=0;i<=100;i++)
                //consignar en result el resultado de realizar un OR entre los objetos a y b
                result.elementos[i]=a.elementos[i] || b.elementos[i];
            return result;
        }
        //Interseccion de conjuntos
        static IntegerSet intersectionOfSets(const IntegerSet& a,const IntegerSet& b){
            IntegerSet result;
            for(int i=0;i<=100;i++)
                //consignar en result el resultado de realizar un AND entre los objetos a y b
                result.elementos[i]=a.elementos[i] && b.elementos[i];
            return result;
        }
        //insertar un elemento
        void insertElement(int k){
            if(k>=0 && k<=100)
                elementos[k]=true;
        }
        //eliminar un elemento
        void deleteElement(int m){
            if(m>=0 && m<=100)
                elementos[m]=false;
        }
        //implementacion de la funcion miembro toString()
        std::string toString() const{
            //parte de la libreria sstream(flujo de texto) que permite construir texto
            std::ostringstream oss;
            bool empty=true;
            //itera buscando los elementos que estan en true y los concatena en un flujo de texto
            for(int i=0;i<=100;i++){
                    if(elementos[i]){
                            oss<<i<<" ";
                            empty=false;
                    }
            }
            return empty ? "--":oss.str(); //retorna segun el flag empty, la cadena formada
        }
        //comparar si dos objetos son iguales
        bool isEqualTo(const IntegerSet& other) const{
            return elementos==other.elementos;
        }
};


#endif // INTEGERSET_H
