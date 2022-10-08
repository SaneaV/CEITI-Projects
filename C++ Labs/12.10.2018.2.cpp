//Даны два числа a, б
//Поменять их значение
//1. Используя дополнительную пременную
//2. Не создавая новую переменную

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int a,b;
    int Selection;

    cout<<"Введите \"a\": ";
    cin>>a;
    cout<<"Введите \"b\": ";
    cin>>b;

    system("cls");

    cout<<"Выберите способ решения данной задачи: "<<endl;
    cout<<"1. Создания новой переменной."<<endl;
    cout<<"2. Без создания новой переменной."<<endl;
    cin>>Selection;
    system("cls");

    switch(Selection)
    {
    case 1:
    {
        cout<<"Выбран первый метод."<<endl<<endl;

        int *c=new int;

        *c=a;
        a=b;
        b=*c;

        delete(c);

        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
        break;
    }
    case 2:
    {
        cout<<"Выбран второй метод."<<endl<<endl;

        a=a+b;
        b=a-b;
        a-=b;

        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
        break;
    }
    default:
    {
        cout<<"Такого варианта нет"<<endl;
    }
    }
}
