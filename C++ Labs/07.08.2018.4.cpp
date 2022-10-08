//Определить, какие из трех целых различных чисел принадлежат полуинтервалу (-5;5].

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

    a>-5 and a<=5? cout<<"Число "<<a<<" принадлежит интервалу."<<endl:cout<<"";
    b>-5 and b<=5? cout<<"Число "<<b<<" принадлежит интервалу."<<endl:cout<<"";
    c>-5 and c<=5? cout<<"Число "<<c<<" принадлежит интервалу."<<endl:cout<<"";
}
