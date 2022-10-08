//Даны три целых числа. Вывести на экран те из них, которые являются четными.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    int a,b,c;
    cout<<"Введите число a: ";
    cin>>a;
    cout<<"Введите число b: ";
    cin>>b;
    cout<<"Введите число c: ";
    cin>>c;

    a%2==0? cout<<"Число "<<a<<" чётное."<<endl:cout<<"Число "<<a<<" нечётное."<<endl;
    b%2==0? cout<<"Число "<<b<<" чётное."<<endl:cout<<"Число "<<b<<" нечётное."<<endl;
    c%2==0? cout<<"Число "<<c<<" чётное."<<endl:cout<<"Число "<<c<<" нечётное."<<endl;
}
