//Найти радиус описанной окружности, если известны стороны треугольника.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    int a,b,c;

    cout<<"\t\t\tПрямоугольник произвольный"<<endl;

    cout<<"Введите длину катета \"а\": ";
    cin>>a;
    cout<<"Введите длину катета \"b\": ";
    cin>>b;
    cout<<"Введите длину гипотенузы \"c\": ";
    cin>>c;

    float R=0,p=0;

    p = 0.5 * (a+b+c);

    R = (a*b*c)/(4.0*sqrt(p*(p-a)*(p-b)*(p-c)));

    cout<<"Радиус описанной окружности: "<<R;


}
