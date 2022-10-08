//Определить, какие из трех целых различных чисел принадлежат полуинтервалу [-9;15).

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

    a>=-9 and a<15? cout<<"Число "<<a<<" принадлежит интервалу."<<endl:cout<<"";
    b>=-9 and b<15? cout<<"Число "<<b<<" принадлежит интервалу."<<endl:cout<<"";
    c>=-9 and c<15? cout<<"Число "<<c<<" принадлежит интервалу."<<endl:cout<<"";
}
