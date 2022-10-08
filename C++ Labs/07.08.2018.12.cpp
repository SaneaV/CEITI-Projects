//Напишите программу, которая на отрезке от а до b, находит сумму и произведение чисел, кратных 9.( а и b –целые числа)

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b;

    cout<<"Введите число: ";
    cin>>a;

    cout<<"Введите число: ";
    cin>>b;

    if (a>b)
    {
        int c = b;
        b = a;
        a = c;
    }

    system("cls");

    cout<<"Выберите способ решания для данной задачи: "<<endl;
    cout<<"1. While"<<endl;
    cout<<"2. Do...While"<<endl;
    cout<<"3. For"<<endl;
    cout<<"Ваш выбор: ";
    int Select;
    cin>>Select;

    int ProductOfNumbers=1;
    int Amount = 0;

    switch(Select)
    {
    case 1:
        {
            while (a<=b)
            {
                if (a%9==0)
                {
                    ProductOfNumbers*=a;
                    Amount+=a;
                }
                a++;
            }

            cout<<"Произведение чисел кратных 9 на этом отрезке: "<<ProductOfNumbers<<endl;
            cout<<"Сумма чисел кратных 9 на этом отрезке: "<<Amount<<endl;
            break;
        }
    case 2:
        {
            do
            {
                if (a%9==0)
                {
                    ProductOfNumbers*=a;
                    Amount+=a;
                }
                a++;

            }while(a<=b);
            cout<<"Произведение чисел кратных 9 на этом отрезке: "<<ProductOfNumbers<<endl;
            cout<<"Сумма чисел кратных 9 на этом отрезке: "<<Amount<<endl;
            break;
        }
    case 3:
        {
            for (;a<=b;a++)
            {
                if (a%9==0)
                {
                    ProductOfNumbers*=a;
                    Amount+=a;
                }

            }
            cout<<"Произведение чисел кратных 9 на этом отрезке: "<<ProductOfNumbers<<endl;
            cout<<"Сумма чисел кратных 9 на этом отрезке: "<<Amount<<endl;
            break;
        }
    default: cout<<"Такого варианта нет"<<endl;
    }
}
