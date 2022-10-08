//Известна диагональ квадрата. Найти его периметр.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");
    cout<<"Дан треугольник ABCD"<<endl;
    cout<<"Введите диагональ квадрата (AC): ";
    int d;
    cin>>d;
    float a=d/sqrt(2);
    float p=4.0*a;
    cout<<"Периметр квадрата ABCD: "<<p<<endl;

}
