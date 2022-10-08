//Даны три числа. Найти произведение тех чисел, которые являются нечетными.

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b,c;

    cout<<"Введите число: ";
    cin>>a;
    cout<<"Введите число: ";
    cin>>b;
    cout<<"Введите число: ";
    cin>>c;

    int Sum=1;

    a%2!=0? Sum*=a:0;
    b%2!=0? Sum*=b:0;
    c%2!=0? Sum*=c:0;

    cout<<"Произведение нечетных чисел: "<<Sum;
}
