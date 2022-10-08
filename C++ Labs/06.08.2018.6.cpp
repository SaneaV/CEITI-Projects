//Даны четыре вещественных числа. Найти произведение положительных и отрицательных чисел.

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    float a,b,c,d;

    cout<<"Введите число: ";
    cin>>a;
    cout<<"Введите число: ";
    cin>>b;
    cout<<"Введите число: ";
    cin>>c;
    cout<<"Введите число: ";
    cin>>d;

    float PozitiveSum=0;
    float NegativeSum=0;

    a>=0? PozitiveSum+=a:NegativeSum+=a;
    b>=0? PozitiveSum+=b:NegativeSum+=b;
    c>=0? PozitiveSum+=c:NegativeSum+=c;
    d>=0? PozitiveSum+=d:NegativeSum+=d;

    cout<<"Сумма положительных чисел: "<<PozitiveSum<<endl;
    cout<<"Сумма отрицательных чисел: "<<NegativeSum<<endl;


}
