//Даны два целых числа. Если квадратный корень из второго числа меньше первого числа, то увеличить второе число в 10 раз.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b;

    cout<<"Введите число: ";
    cin>>a;
    cout<<"Введите число: ";
    cin>>b;

    sqrt(b)<a? b*=10:0;

    cout<<"Первое число: "<<a<<endl;
    cout<<"Второе число: "<<b<<endl;
}
