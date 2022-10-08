//С клавиатуры вводится дата. Напишите программу, которая вычисляет сколько дней прошло с начала года.

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int Day, Month;
    int Select;
    int AllDays=0;

    cout<<"Введите день: ";
    cin>>Day;
    cout<<"Введите месяц: ";
    cin>>Month;

    system("cls");

    cout<<"Выберите цикл для решения данной задачи: "<<endl;
    cout<<"1. While"<<endl;
    cout<<"2. Do..While"<<endl;
    cout<<"3. For"<<endl;
    cout<<"Ваш выбор: ";
    cin>>Select;

    int i=0;

    system("cls");

    switch(Select)
    {
    case 1:
        {
            while(Month>i)
            {

                if(i==3 or i==5 or i==7 or i==8 or i==9 or i==11 ) AllDays+=31;
                if(i==1 or i==4 or i==6 or i==9 or i==11) AllDays+=30;
                if(i==2) AllDays+=28;
                i++;
            }

            AllDays+=Day;

            cout<<"Количество дней прошедших с начала года: "<<AllDays<<endl;
            cout<<"Количество дней прошедших с начала високосного года: "<<AllDays<<endl;
            break;
        }
    case 2:
        {
            do
            {
               if(i==3 or i==5 or i==7 or i==8 or i==9 or i==11 ) AllDays+=31;
                if(i==1 or i==4 or i==6 or i==9 or i==11) AllDays+=30;
                if(i==2) AllDays+=28;
                i++;
            }while(Month>i);
            AllDays+=Day;

            cout<<"Количество дней прошедших с начала года: "<<AllDays<<endl;
            cout<<"Количество дней прошедших с начала високосного года: "<<AllDays<<endl;
            break;
        }
    case 3:
        {
            for(;Month>i;i++)
            {
                if(i==3 or i==5 or i==7 or i==8 or i==9 or i==11 ) AllDays+=31;
                if(i==1 or i==4 or i==6 or i==9 or i==11) AllDays+=30;
                if(i==2) AllDays+=28;
            }


            AllDays+=Day;

            cout<<"Количество дней прошедших с начала года: "<<AllDays<<endl;
            cout<<"Количество дней прошедших с начала високосного года: "<<AllDays<<endl;
            break;
        }
    default: cout<<"Такого варианта нет"<<endl;
    }
}
