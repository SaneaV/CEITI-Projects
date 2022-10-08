#include <iostream>

using namespace std;

void Foo(int &a, int &b, int &c)
{
    a = 10;
    b *=2;
    c -=100;
}

int main()
{
    int a = 0;
    int b = 100;
    int c = 34;

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;

    cout<<endl<<"Foo"<<endl<<endl;
    Foo(a,b,c);

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;

    return 0;
}
