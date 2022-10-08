//Напишите программу, которая на отрезке от а до b, выводит на экран все числа, оканчивающиеся на цифру три .( а и b –целые числа)

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b;

    cout<<"Введите начало отрезка: ";
    cin>>a;
    cout<<"Введите конец отрезка: ";
    cin>>b;

    if(a>b)
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

    system("cls");

    switch(Select)
    {
    case 1:
        {
            while(a<=b)
            {
                if(a%10==3) cout<<"Число "<<a<<" оканчивается на три"<<endl;
                a++;
            }
            break;
        }
    case 2:
        {
            do
            {
                if(a%10==3) cout<<"Число "<<a<<" оканчивается на три"<<endl;
                a++;
            }while(a<=b);
            break;
        }
    case 3:
        {
            for(;a<=b;a++)
            {
                if(a%10==3) cout<<"Число "<<a<<" оканчивается на три"<<endl;
            }
            break;
        }
        default:cout<<"Такого варианта нет"<<endl;
    }


}


