//»спользу€ рекурсивную подпрограмму, вычислить функцию аккермана

#include <iostream>

using namespace std;

int a(int m, int n)
{
    if (n==0)
        return a(m-1,1);
    else if (m>0 and n>0)
    {
        return a(m-1,a(m,n-1));
    }
    if (m==0)
        return n+1;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int x;
    int y;

    cout<<"¬ведите значение \"m\": ";
    cin>>x;
    cout<<"¬ведите значение \"n\": ";
    cin>>y;

    cout<<a(x,y);
}
