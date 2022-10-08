//Вычислить периметр прямоугольного треугольника, если известны его катеты.

#include <cmath>
#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"Rus");

    cout<<"Введите сторону первого катета: ";
    int a,b,c;
    cin>>a;
    cout<<"Введите сторону второго катета: ";
    cin>>b;

    c=sqrt(pow(a,2)+pow(b,2));

    cout<<"Гипотенуза треугольника: "<<c<<endl;

    int P=a+b+c;

    cout<<"Периметр треугольника: "<<P;
}
