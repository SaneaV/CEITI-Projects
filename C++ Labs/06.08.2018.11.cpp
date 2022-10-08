//Даны четыре числа. Определить количество чисел, которые больше 10.

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

    a>10? k++:0;
    b>10? k++:0;
    c>10? k++:0;
    d>10? k++:0;

    cout<<"Количество чисел больше 10: "<<k<<endl;
}
