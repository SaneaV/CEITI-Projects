//Даны три целых числа. Вывести на экран те из них, которые кратны 5.

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

    a%5==0? cout<<"Число "<<a<<" кратно пяти"<<endl:cout<<"";
    b%5==0? cout<<"Число "<<b<<" кратно пяти"<<endl:cout<<"";
    c%5==0? cout<<"Число "<<c<<" кратно пяти"<<endl:cout<<"";
}
