//Напишите программу, которая на отрезке от а до b, выводит на экран все нечетные числа, оканчивающиеся цифрой 7 .
//( а и b –целые числа)

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b;

    cout<<"Введите число \"а\": ";
    cin>>a;
    cout<<"Введите число \"b\": ";
    cin>>b;

    if (a>b)
    {
        int c = a;
        a = b;
        c = a;
    }

    system("cls");

    int Select;

    cout<<"Выберите цикл для решения данной задачи: "<<endl;
    cout<<"1. While"<<endl;
    cout<<"2. Do..While"<<endl;
    cout<<"3. For"<<endl;
    cout<<"Ваш выбор: ";
    cin>>Select;

    system("cls");

    switch(Select)
    {
    case 1:
    {
        while (a<=b)
        {
            //Проверять на нечётность нет смысла. 7 всегда будет нечётной.
            if (a%10==7)
                cout<<a<<endl;
            a++;
        }
        break;
    }
    case 2:
    {
        do
        {
            if (a%10==7)
                cout<<a<<endl;
            a++;
        }
        while(a<=b);
        break;
    }
    case 3:
    {
        for(; a<=b; a++)
        {
            if(a%10==7)
                cout<<a<<endl;
        }
        break;
    }
    default:
        cout<<"Такого варианта не существует."<<endl;
    }

}
