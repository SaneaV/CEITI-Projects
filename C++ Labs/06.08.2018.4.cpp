//Даны четыре целых числа. Найти сумму четных и нечетных чисел.

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

    int Del2=0;
    int NoDel2=0;

    a%2==0? Del2+=a:NoDel2+=a;
    b%2==0? Del2+=b:NoDel2+=b;
    c%2==0? Del2+=c:NoDel2+=c;
    d%2==0? Del2+=d:NoDel2+=d;

    cout<<"Сумма четных чисел: "<<Del2<<endl;
    cout<<"Сумма нечетных чисел: "<<NoDel2<<endl;
}
