#include <iostream>

using std::cout;
using std::endl;
using std::cin;

template <typename t>
void Swap (t &a, t&b)
{
    t c = a;
    a = b;
    b = c;
}

int main()
{
    int a,b;

    cout<<"Input a: ";
    cin>>a;
    cout<<"Input b: ";
    cin>>b;

    Swap(a,b);

    cout<<endl<<endl;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    return 0;
}
