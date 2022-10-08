//Найти максимальное и минимальное значения из трех различных вещественных чисел.

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    float a,b,c;
    float min, max;

    cout<<"Введите число: ";
    cin>>a;
    cout<<"Введите число: ";
    cin>>b;
    cout<<"Введите число: ";
    cin>>c;

    a>b and a>c? max=a:0;
    b>c and b>a? max=b:0;
    c>a and c>b? max=c:0;
    a<b and a<c? min=a:0;
    b<c and b<a? min=b:0;
    c<a and c<b? min=c:0;

    cout<<"Максимальное число: "<<max<<endl;
    cout<<"Минимальное число: "<<min<<endl;

}
