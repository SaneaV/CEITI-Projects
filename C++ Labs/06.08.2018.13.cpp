//Даня три целых числа. Определить сколько из них отрицательных.

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

    a<0? k++:0;
    b<0? k++:0;
    c<0? k++:0;
    d<0? k++:0;

    cout<<"Количество отрицательных чисел: "<<k;

}

