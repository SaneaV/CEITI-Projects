//Даны три вещественных числа. Вывести на экран те из них, которые являются не отрицательными.

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    float a,b,c;

    cout<<"Введите число: ";
    cin>>a;
    cout<<"Введите число: ";
    cin>>b;
    cout<<"Введите число: ";
    cin>>c;

    a>=0? cout<<"Число "<<a<<" положительное"<<endl:cout<<"";
    b>=0? cout<<"Число "<<b<<" положительное"<<endl:cout<<"";
    c>=0? cout<<"Число "<<c<<" положительное"<<endl:cout<<"";

}
