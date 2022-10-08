//Даны три числа. Проверить, можно ли построить треугольник с такими сторонами.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    cout<<"Введите первый катет: ";
    int a,b,c;
    cin>>a;
    cout<<"Введите второй катет: ";
    cin>>b;
    cout<<"Ввидите гипотенузу: ";
    cin>>c;

    cout<<"Такой треугольник существует: "<<boolalpha<<((a+b>c) and (a+c>b) and (b+c>a));
}
