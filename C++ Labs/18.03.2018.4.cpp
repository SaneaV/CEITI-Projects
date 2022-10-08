//Даны три вещественных числа. Вывести их в порядке возрастания.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    float a,b,c;
    cout<<"Введите число a: ";
    cin>>a;
    cout<<"Введите число b: ";
    cin>>b;
    cout<<"Введите число c: ";
    cin>>c;

    float min,med,max;
    a*=1.0;
    b*=1.0;
    c*=1.0;

    a>b and a>c? max=a:0;
    b>a and b>c? max=b:0;
    c>a and c>b? max=c:0;

    a<b and a<c? min=a:0;
    b<a and b<c? min=b:0;
    c<a and c<b? min=c:0;

    a>b and a<c or a<b and a>c? med=a:0;
    b>a and b<c or b<a and b>c? med=b:0;
    c>a and c<b or c<a and c>b? med=a:0;

    cout<<"Максимальное число: "<<max<<endl;
    cout<<"Среднее число: "<<med<<endl;
    cout<<"Минимальное число: "<<min<<endl;
}


