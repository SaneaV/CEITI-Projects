//Напишите программу, которая выводит все делители чисел от а до b. ( а и b –целые числа).

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b;

    cout<<"Введите первое число: ";
    cin>>a;

    cout<<"Введите второе число: ";
    cin>>b;

    if(b<a)
    {
        int c = a;
        a = b;
        b = c;
    }

    system("cls");

    int Select;
    cout<<"Выберите цикл для рещения данной задачи: "<<endl;
    cout<<"1.While"<<endl;
    cout<<"2.Do...While"<<endl;
    cout<<"3.For"<<endl;
    cout<<"Ваш выбор: ";
    cin>>Select;

    int i = a;

    system("cls");

    switch(Select)
    {
    case 1:
        {
            while(i<=b)
            {
                if (i%a==0) cout<<"Делитель числа "<<a<<": "<<i<<endl;
                if (i%b==0) cout<<"Делитель числа "<<b<<": "<<i<<endl;
                i++;

            }
            break;
        }
    case 2:
        {
            do
            {
                if (i%a==0) cout<<"Делитель числа "<<a<<": "<<i<<endl;
                if (i%b==0) cout<<"Делитель числа "<<b<<": "<<i<<endl;
                i++;

            }while(i<=b);
            break;
        }
    case 3:
        {
            for(;i<=b;i++)
            {
                if (i%a==0) cout<<"Делитель числа "<<a<<": "<<i<<endl;
                if (i%b==0) cout<<"Делитель числа "<<b<<": "<<i<<endl;
            }
            break;
        }
    default:cout<<"Такого варианта нет"<<endl;
    }
}
