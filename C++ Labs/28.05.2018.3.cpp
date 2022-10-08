//Использование прототипной функции

#include <iostream>

using namespace std;

int Sum (int &x, int &y);

int main()
{
    int a,b;
    cout<<"A: ";
    cin>>a;
    cout<<"B: ";
    cin>>b;

    cout<<Sum(a,b);
}

int Sum (int &x, int &y)
{
    return x+y;
}
