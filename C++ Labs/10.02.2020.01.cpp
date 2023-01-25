#include <iostream>
#include <cmath>
#include <windows.h>

const double Pi = 3.14;

using namespace std;

double function(double x)
{
    return (sin(cos(x*x)))/2;
}

int main()
{
    setlocale(LC_ALL,"RUS");
    short int selection;
    bool work = true;
    double a = -Pi/2;
    double b = Pi/2;

    while(work)
    {
        system("cls");

        cout<<"1. Левые прямоугольники"<<endl;
        cout<<"2. Правые прямоугольники"<<endl;
        cout<<"3. Серединные прямоугольники"<<endl;
        cout<<"4. Трапеции"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 1:
        {
            int n;
            cout<<"Введите количестов отрезков: ";
            cin>>n;
            double h = (abs(b-a))/n;
            double Sum = 0;

            for(int i=0; i<=n-1; i++)
                Sum+=function(a+i*h)*h;


            cout<<Sum<<endl;
            system("PAUSE");
            break;
        }

        case 2:
        {

            int n;
            cout<<"Введите количестов отрезков: ";
            cin>>n;
            double h = (abs(b-a))/n;
            double Sum = 0;

            for(int i=1; i<=n; i++)
                Sum+=function(a+i*h);


            cout<<h*Sum<<endl;
            system("PAUSE");
            break;
        }

        case 3:
        {

            int n;
            cout<<"Введите количестов отрезков: ";
            cin>>n;
            double h = (abs(b-a))/n;
            double Sum = 0;

            for(int i=1; i<=n-1; i++)
                Sum+=function(a+i*h+(h/2));


            cout<<Sum*h<<endl;
            system("PAUSE");
            break;
        }

        case 4:
        {

            int n;
            cout<<"Введите количестов отрезков: ";
            cin>>n;
            double h = (abs(b-a))/n;
            double Sum = 0;

            for(int i=1; i<=n-1; i++)
                Sum+=function(a+i*h);



            cout<<(Sum +function(a)+function(b)/2)*h<<endl;
            system("PAUSE");
            break;
        }

        }
    }
}
