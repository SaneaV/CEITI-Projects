//Даны четыре целых числа. Определить сколько из них четных.

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

    int k=0;

    a%2==0? k++:0;
    b%2==0? k++:0;
    c%2==0? k++:0;
    d%2==0? k++:0;

    cout<<"Количество чётных чисел: "<<k;

}
