#include <iostream>
#include <cmath>

using namespace std;

double Function(double x)
{
    return pow(x,3)+3*pow(x,2)-3;
}

double FunctionFirst(double x)
{
    return 3*pow(x,2)+6*x;
}

int main()
{
    setlocale(LC_ALL,"RUS");

    double a=0;
    double b=2;

    double co, cn;
    double to, tn;

    double E=0.001;

    if(Function(a)*FunctionFirst(a)>0)
    {
        co=b;
        to=a;
    }
    else
    {
        co=a;
        to=b;
    }

    do
    {
        cn = co;
        tn = to;

        co = (cn * Function(tn)-tn*Function(cn))/(Function(tn)-Function(cn));

        to =  tn - Function(tn) / FunctionFirst(tn);

        cout<<co<<" "<<to<<endl;
    }
    while(abs(to-co)>E);

    return 0;
}
