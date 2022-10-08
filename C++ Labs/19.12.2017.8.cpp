//Известна диагональ квадрата. Найти его сторону и площадь.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    cout<<"Введите диагональ квадрата: ";
    int d;
    cin>>d;
    float S=(pow(d,2))/2;
    float a=sqrt(S);
    cout<<"Сторона квадрата: "<<a<<endl;
    cout<<"Площадь квадрата: "<<S<<endl;
}
