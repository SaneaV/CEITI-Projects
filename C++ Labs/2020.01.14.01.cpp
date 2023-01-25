#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

double _function(double x)
{
    return pow(x,3)+3*pow(x,2)-3;
}

double functionFirst(double x)
{
    return 3*pow(x,2)+6*x;
}

double functionSecond(double x)
{
    return 6*x+6;
}

void methodPartDivision(double a, double b, double const E)
{
    double c;

    cout<<"||======================================||"<<endl;
    while (abs(b - a) > E)
    {
        c = (a + b) / 2;

        cout<<"||";
        cout<<fixed<<setw(13)<<c;
        cout<<setw(7)<<"||";
        cout<<setw(13)<<setprecision(8)<<_function(c);
        cout<<setw(7)<<"||"<<endl;

        if(_function(b) * _function(c) < 0)
            a = c;
        else
            b = c;

    }

    cout<<"||======================================||"<<endl;
}

void methodChord(double a, double b, double const E)
{
    double x;
    double xnou;
    double e;
    double xvechi;

    x = a - (_function(a))/(_function(b)-_function(a))*(b-a);

    if(_function(x)*_function(a)>0)
    {
        e = b;
        xnou = a;
    }
    else
    {
        e = a;
        xnou = b;
    }

    cout<<"||======================================||"<<endl;
    do
    {
        xvechi = xnou;
        xnou = xvechi - (_function(xvechi))/(_function(e)-_function(xvechi))*(e-xvechi);

        cout<<"||";
        cout<<fixed<<setw(13)<<xnou;
        cout<<setw(7)<<"||";
        cout<<setw(13)<<setprecision(8)<<_function(x);
        cout<<setw(7)<<"||"<<endl;
    }
    while(abs(abs(xnou - xvechi) > E));
    cout<<"||======================================||"<<endl;
}

void methodTangent(double a, double b, double const E)
{
    double c;

    if(_function(a)*functionSecond(a)>0)
        c=a;
    else
        c=b;

    cout<<"||======================================||"<<endl;
    do
    {
        c=c-_function(c)/functionFirst(c);

        cout<<"||";
        cout<<fixed<<setw(13)<<c;
        cout<<setw(7)<<"||";
        cout<<setw(13)<<setprecision(8)<<_function(c);
        cout<<setw(7)<<"||"<<endl;
    }
    while (fabs(_function(c))>=E);
    cout<<"||======================================||"<<endl;
}

void methodCombo(double a, double b, double const E)
{
    double co, cn;
    double to, tn;

    if(_function(a)*functionFirst(a)>0)
    {
        co=b;
        to=a;
    }
    else
    {
        co=a;
        to=b;
    }

    cout<<"||======================================||"<<endl;
    do
    {
        cn = co;
        tn = to;
        co = (cn * _function(tn)-tn*_function(cn))/(_function(tn)-_function(cn));
        to =  tn - _function(tn) / functionFirst(tn);

        cout<<fixed<<"||"<<setw(13)<<co;
        cout<<setw(7)<<"||";
        cout<<setw(13)<<to;
        cout<<setw(7)<<"||"<<endl;
    }
    while(abs(to-co)>E);
    cout<<"||======================================||"<<endl;

}

int main()
{
    setlocale(LC_ALL,"RUS");

    double a=0;
    double b=3;
    double E=0.001;

    int selection;
    bool exit = false;

    while(!exit)
    {
        system("cls");
        cout<<setw(30)<<"Добро пожаловать!"<<endl;
        cout<<"||======================================||"<<endl;
        cout<<"||1. Использовать метод биссекции.      ||"<<endl;
        cout<<"||======================================||"<<endl;
        cout<<"||2. Использовать метод хорд.           ||"<<endl;
        cout<<"||======================================||"<<endl;
        cout<<"||3. Использовать метод касательных.    ||"<<endl;
        cout<<"||======================================||"<<endl;
        cout<<"||4. Использовать комбинированный метод.||"<<endl;
        cout<<"||======================================||"<<endl;
        cout<<"||5. Выход из программы.                ||"<<endl;
        cout<<"||======================================||"<<endl;
        cout<<setw(25)<<"Ваш выбор: ";
        cin>>selection;
        system("cls");

        switch(selection)
        {
        case 1:
        {
            methodPartDivision(a,b,E);
            system("PAUSE");
            break;
        }
        case 2:
        {
            methodChord(a,b,E);
            system("PAUSE");
            break;
        }
        case 3:
        {
            methodTangent(a,b,E);
            system("PAUSE");
            break;
        }
        case 4:
        {
            methodCombo(a,b,E);
            system("PAUSE");
            break;
        }
        case 5:
        {
            exit = true;
            cout<<"До скорой встречи!"<<endl;
            break;
        }
        }
    }

}
