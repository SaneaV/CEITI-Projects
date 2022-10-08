//Известны ширина и длина прямоугольника. Сторона квадрата в два раза меньше длины прямоугольника. Найти периметры квадрата и прямоугольника.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    int shirina=0,dlina=0;

    cout<<"Введите длину прямоугольника: ";
    cin>>dlina;
    cout<<"Введите ширину прямоугольника: ";
    cin>>shirina;

    float a;

    a=shirina/(2*1.0);

    float Pk;
    int Pp;

    Pk=a*4.0;
    Pp=2*(dlina+shirina);

    cout<<"Периметр квадрата: "<<Pk<<endl;
    cout<<"Периметр прямоугольника: "<<Pp;

}

