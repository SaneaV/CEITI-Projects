#include <iostream>

using namespace std;

template <typename TYPE> TYPE swaps(TYPE &n, TYPE &m)
{
    TYPE u;

    u=n;
    n=m;
    m=u;

}

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b;
    float y,z;
    char p,q;

    cout<<"Введите значения для int: "<<endl;
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;


    cout<<endl<<endl<<"Введите значения для float: "<<endl;
    cout<<"y = ";
    cin>>y;
    cout<<"z = ";
    cin>>z;


    cout<<endl<<endl<<"Введите значения для char: "<<endl;
    cout<<"p = ";
    cin>>p;
    cout<<"q = ";
    cin>>q;

    swaps(a,b);
    swaps(y,z);
    swaps(p,q);

    cout<<endl<<endl;
    cout<<"Значения int: ";
    cout<<endl<<"a = "<<a<<"; b = "<<b<<endl;
    cout<<"Значения float: ";
    cout<<endl<<"y = "<<y<<"; z = "<<z<<endl;
    cout<<"Значения char: ";
    cout<<endl<<"p = "<<p<<"; q = "<<q<<endl;

    return 0;
}
