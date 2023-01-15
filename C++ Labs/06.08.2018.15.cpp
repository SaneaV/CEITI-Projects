//Определить, какие из трех целых различных чисел принадлежат интервалу (-10;10).

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

    a>=-10 and a<=10? cout<<"Число "<<a<<" принадлежит отрезку."<<endl:cout<<"";
    b>=-10 and b<=10? cout<<"Число "<<b<<" принадлежит отрезку."<<endl:cout<<"";
    c>=-10 and c<=10? cout<<"Число "<<c<<" принадлежит отрезку."<<endl:cout<<"";
}
