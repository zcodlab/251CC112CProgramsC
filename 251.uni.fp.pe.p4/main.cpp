#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double discriminante (float x, float y, float z);

int main()
{
    float a,b,c,disc,x1,x2;
    cout<<"ingrese el coeficiente a: ";
    cin>> a;
    if (a==0) cout<<"no es posible determinar las raices"<<endl;
    else
       {
       cout<<"ingrese el coeficiente b: ";
	   cin>> b;
       cout<<"ingrese el coeficiente c: ";
       cin>> c;
       disc = discriminante(a,b,c);
       if (disc<0) cout<<"discriminante negativo"<<endl;
       else
       {
       	 x1 = (-b+sqrt(disc))/(2*a);
         x2 = (-b-sqrt(disc))/(2*a);
         cout<<"Las soluciones reales son: "<<endl;
         cout<<"x1 = "<<setprecision(3)<<x1<<endl;
         cout<<"x2 = "<<setprecision(3)<<x2<<endl;
       }
    }
    return 0;
}

double discriminante (float x, float y, float z)
{
    double w;
    w = pow(y,2)-4*x*z;
    return w;
}
