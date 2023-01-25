#include <iostream>
#include <cmath>

using namespace std;

float func(float xi)
{
    return pow(M_E,xi)-xi+100;
}

int main()
{
    int a, b, n;
    setlocale(LC_ALL,"Rus");
    cout<<"Введите переменные (через enter a,b,n): "<<endl;
    cin>>a>>b>>n;

    float S = 0, x = 0;
    float h = abs(a-b)/n;

    for(int i=0;i<n;i++)
    {
        x = a + i*h;
        S += h * func(x);
    }

    cout<<S;
}
