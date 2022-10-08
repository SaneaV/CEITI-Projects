//Даны 3 числа. Рекурсивно узнать сумму цифр одного из них.

#include <iostream>

using namespace std;

int Sum(int n)
{
    if (n != 0)
        return n % 10 + Sum(n / 10);
    return 0;

}

int main()
{
    setlocale(0,"");

    int a,b,c;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"c=";
    cin>>c;

    cout<<endl<<"Сумму цифр какого числа узнать:";
    int v;
    cin>>v;

    switch(v)
    {
        case 1: {cout<<Sum(a);break;}
        case 2: {cout<<Sum(b);break;}
        case 3: {cout<<Sum(c);break;}
    }
}
