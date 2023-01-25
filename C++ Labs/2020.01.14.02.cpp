#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Function(double x)
{
    return pow(x,3)-2*pow(x,2)+x-3;
}

double FunctionFirst(double x)
{
    return 3*pow(x,2)-4*x+1;
}

double FunctionSecond(double x)
{
    return 6*x-4;
}

int main()
{
    setlocale(LC_ALL,"Rus");

    double a = 2;
    double b = 15;
    double E = 0.001;

    double xn;
    double xo;

    if(Function(a)*FunctionSecond(a)>0) xn = a;
    else xn = b;

    do
    {
        xo=xn;

        xn = xo - Function(xo)/FunctionFirst(xo);

        cout<<fixed<<setw(10)<<xn<<setw(20)<<setprecision(8)<<Function(xn)<<endl;
    }while(abs(xn-xo)>E);



    return 0;
}
