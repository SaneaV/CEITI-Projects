//Найти радиус вписанной окружности, если известны стороны треугольника.

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

    float S,p,r;

    p = (a+b+c)/2.0;

    S = sqrt(((a + b + c)/2.0) * ((a + b + c)/2.0 - a) * ((a + b + c)/2.0 - b) * ((a + b + c)/2.0 - c));

    r = S/p;

    cout<<"Радиус вписанной окружности: "<<r;

}
