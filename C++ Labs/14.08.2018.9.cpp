//Вычислите 1!+2!+3!+…+n!, где n- натуральное число

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;

    cout<<"Введите число: ";
    cin>>n;

    system("cls");

    int Select;
    cout<<"Выберите цикл для рещения данной задачи: "<<endl;
    cout<<"1.While"<<endl;
    cout<<"2.Do...While"<<endl;
    cout<<"3.For"<<endl;
    cout<<"Ваш выбор: ";
    cin>>Select;

    system("cls");

    int c;
    int Sum = 0;
    int i = 1;
    int TheProductON = 1;

    switch(Select)
    {
    case 1:
    {
        while(i<=n)
        {
            c = 1;
            TheProductON = 1;

            while(c<=i)
            {
                TheProductON *= c;
                c++;
            }
            Sum += TheProductON;
            i++;
        }

        cout<<"n! = "<<Sum<<endl;
        break;
    }
    case 2:
    {
        do
        {
            c = 1;
            TheProductON = 1;
            do
            {
                TheProductON *= c;
                c++;

            }
            while(c<=i);
            Sum += TheProductON;
            i++;

        }
        while(i<=n);

        cout<<"n! = "<<Sum<<endl;
        break;
    }
    case 3:
    {
        for(; i<=n; i++)
        {
            c = 1;
            TheProductON = 1;
            for(; c<=i; c++)
            {
                TheProductON *= c;
            }
            Sum += TheProductON;
        }
        cout<<"n! = "<<Sum<<endl;
        break;
    }
    }
}
