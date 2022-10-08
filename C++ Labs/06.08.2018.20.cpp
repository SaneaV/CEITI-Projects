//Даны четыре целых числа. Найти сумму тех из них, которые кратны трем. Оператор цикла не использовать.

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b,c,d;

    cout<<"Введите число: ";
    cin>>a;
    cout<<"Введите число: ";
    cin>>b;
    cout<<"Введите число: ";
    cin>>c;
    cout<<"Введите число: ";
    cin>>d;

    int Sum=0;

    a%3==0? Sum+=a:0;
    b%3==0? Sum+=b:0;
    c%3==0? Sum+=c:0;
    d%3==0? Sum+=d:0;

    cout<<"Сумма чисел кратных трём: "<<Sum<<endl;
}
