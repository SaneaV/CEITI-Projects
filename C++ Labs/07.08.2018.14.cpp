//Дано натуральное число n. Найдите n-ый член последовательности 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5 ,5 ,5 ,5,

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

    cout<<"Выберите способ решания для данной задачи: "<<endl;
    cout<<"1. While"<<endl;
    cout<<"2. Do...While"<<endl;
    cout<<"3. For"<<endl;
    cout<<"Ваш выбор: ";
    int Select;
    cin>>Select;

    int i=0;
    int x=0;
    int n1=0;
    int shw=0;
    bool y = true;

    switch(Select)
    {
    case 1:
    {
        while (x<n and y)
        {
            x++;
            i=0;
            while (i<x and y)
            {
                shw++;
                i++;
                if (shw==n)
                {
                    n1 = x;
                    y=false;
                }
            }

        }
        cout<<n1;
        break;
    }
    case 2:
    {
        do
        {
            x++;
            i=0;
            do
            {
                shw++;
                i++;
                if (shw==n)
                {
                    n1 = x;
                    y=false;
                }
            }
            while (i<x and y);

        }
        while(x<n and y);

        cout<<n1;
        break;

    }
    case 3:
    {
        shw=1;

        for (x=1; x<=n and y; x++)
        {
            for(i=1; i<=x and y; i++,shw++)
            {
                if (shw==n)
                {
                    n1 = x;
                    y=false;
                }
            }
        }
        cout<<n1;
        break;
    }
    }



}
