//Известен периметр квадрата. Найти его диагональ и площадь.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    int P,a,Diagonali,Ploshadi;

    cout<<"Введите периметр квадрата: ";
    cin>>P;

    a=P/4;
    Diagonali=sqrt(2)*a;
    Ploshadi=a*a;

    cout<<"Площадь квадрата: "<<Ploshadi<<endl;
    cout<<"Диагональ квадрата: "<<Diagonali;

}
