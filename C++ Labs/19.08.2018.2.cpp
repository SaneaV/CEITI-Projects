//Используя тип данных запись с именем WORKER, содержащую следующие поля:
//• NAME – фамилия и инициалы работника;
//• POST – название занимаемой должности;
//• YEAR – год поступления на работу.
//Написать программу, выполняющую следующие действия:
//• ввод с клавиатуры данных в массив TABL, состоящий из 10 записей типа WORKER,
//• вывод на экран  фамилий работников, чей стаж работы превышает значение, введенное с клавиатуры;
//если таких работников нет, вывести соответствующее сообщение.
//• вывод на экран  данные о работнике, фамилия и инициалы которого введены с клавиатуры;
//если таких работников нет, вывести соответствующее сообщение.

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    struct WORKER
    {
        char NAME[30];
        char POST[20];
        int YEAR;
    } TABL[10];



    for(int i=0; i<10 ; i++)
    {
        cout<<"Введите фамилию и инициалы работника(слитно): ";
        cin>>TABL[i].NAME;

        cout<<"Введите название занимаемой должности: ";
        cin>>TABL[i].POST;

        cout<<"Введите год поступления на работу: ";
        cin>>TABL[i].YEAR;


            system("cls");
    }

    int Select;
    int RepeatSelect;
    bool Menu = true;

    while(Menu)
    {
        cout<<"1.Узнать, кто работает больше чем..."<<endl;
        cout<<"2.Узнать о работнике по его фамилии и инициалам."<<endl;
        cout<<"Ваш выбор: ";
        do
        {
            cin>>Select;
        }
        while(Select<1 or Select>2);
        system("cls");

        switch(Select)
        {
        case 1:
        {
            int year;
            int ThisYear;
            int k=0;
            cout<<"Введите стаж работы: ";
            cin>>year;
            cout<<"Введите текущий год: ";
            cin>>ThisYear;

            for(int i=0; i<10 ; i++)
            {
                if((ThisYear-TABL[i].YEAR)>=year)
                {
                    cout<<"Стаж работы "<<TABL[i].NAME<<" составляет: "<<ThisYear-TABL[i].YEAR<<endl;
                    k++;
                }


            }
            if (k==0)
                cout<<"К сожалению, никто ещё не отработал столько лет."<<endl;

            cout<<endl<<endl;
            cout<<"1. Вернуться в меню."<<endl;
            cout<<"2. Выйти из программы."<<endl;
            do
            {
                cin>>RepeatSelect;

            }
            while(RepeatSelect<1 or RepeatSelect>2);

            if (RepeatSelect==1)
                system("cls");
            if (RepeatSelect==2)
            {
                system("cls");
                Menu = false;
            }

            break;
        }
        case 2:
        {
            char Name[30];
            int k = 0;

            cout<<"Введите фамилию и инициалы человека: ";
            cin>>Name;

            for(int i=0; i<10 ; i++)
            {
                if(strcmp(Name,TABL[i].NAME)==0)
                {
                    cout<<TABL[i].NAME<<" в должности - "<<TABL[i].POST<<" работает с "<<TABL[i].YEAR<<" года."<<endl;
                    k++;
                }
            }
            if (k==0)
                cout<<"К сожалению, такой человек у нас не работает."<<endl;

            cout<<endl<<endl;
            cout<<"1. Вернуться в меню."<<endl;
            cout<<"2. Выйти из программы."<<endl;
            do
            {
                cin>>RepeatSelect;

            }
            while(RepeatSelect<1 or RepeatSelect>2);

            if (RepeatSelect==1)
                system("cls");
            if (RepeatSelect==2)
            {
                system("cls");
                Menu = false;
            }

            break;
        }

        }

    }

}
