//Даны три целых числа. Найти произведение наибольшего и наименьшего чисел.

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

    int max;
    int min;

    a>b and a>c? max = a:0;
    b>a and b>c? max = b:0;
    c>a and c>b? max = c:0;

    a<b and a<c? min = a:0;
    b<a and b<c? min = b:0;
    c<b and c<a? min = c:0;

    cout<<"Произведение самого большого и самого маленького числа: "<<min*max<<endl;
}
