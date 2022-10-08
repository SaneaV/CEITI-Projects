//ќпределить, какие из трех целых различных чисел принадлежат интервалу (-10;10).

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b,c;

    cout<<"¬ведите число: ";
    cin>>a;
    cout<<"¬ведите число: ";
    cin>>b;
    cout<<"¬ведите число: ";
    cin>>c;

    a>=-10 and a<=10? cout<<"„исло "<<a<<" принадлежит отрезку."<<endl:cout<<"";
    b>=-10 and b<=10? cout<<"„исло "<<b<<" принадлежит отрезку."<<endl:cout<<"";
    c>=-10 and c<=10? cout<<"„исло "<<c<<" принадлежит отрезку."<<endl:cout<<"";
}
