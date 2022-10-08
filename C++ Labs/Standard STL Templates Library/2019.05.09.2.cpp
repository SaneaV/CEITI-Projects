#include <iostream>

using namespace std;

union myUnion
{
    short int a;
    int b;
    float c;
};

int main()
{

    myUnion U;

    U.a = 5;
    cout<<U.a<<endl;
    U.b = 2;
    cout<<U.b<<endl;
    U.c = 3.1;
    cout<<U.c<<endl;

    cout<<endl;
    cout<<U.a<<endl;
    cout<<U.b<<endl;
    cout<<U.c<<endl;

    return 0;
}
