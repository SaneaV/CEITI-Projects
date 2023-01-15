//Используя тип данных запись с именем AEROFLOT, содержащую следующие поля:
//• NAZN – название пункта назначения рейса;
//• NUMR – номер рейса;
//• TIP – тип самолета.
//Написать программу, выполняющую следующие действия:
//• ввод с клавиатуры данных в массив AIRPORT, состоящий из 7 записей типа AEROFLOT;
//• вывод на экран  пунктов назначения и номеров рейсов, обслуживаемых самолетом, типов которого введен с клавиатуры;
//если таких рейсов нет, вывести соответствующее сообщение.
//• вывод на экран  номеров рейсов и типов самолетов, вылетающих в пункт назначения, название которого введено с клавиатуры;
//если таких рейсов нет, вывести соответствующее сообщение.

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    struct AEROFLOT
    {
        char NAZN[30];
        int NUMR;
        int TIP;
    } AIRPORT[7];


    for(int i=0; i<8; i++)
    {
        cout<<"Введите название пункта назначения: ";
        cin>>(AIRPORT[i].NAZN);

        cout<<"Введите номер рейса: ";
        cin>>AIRPORT[i].NUMR;

        cout<<"Введите тип самолёта(1 - грузовой; 2 - пассажирский): ";
        do
        {
            cin>>AIRPORT[i].TIP;
        }
        while(AIRPORT[i].TIP>2 or AIRPORT[i].TIP<1);

            system("cls");
    }

    int Select;
    int RepeatSelect;
    bool Menu = true;

    while(Menu)
    {
        cout<<"1.Узнать о типах самолётов."<<endl;
        cout<<"2.Узнать о самолётах, направляющихся в..."<<endl;
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
            int Tip;
            int k=0;
            cout<<"Введите тип самолёта(1 - грузовой; 2 - пассажирский): ";
            do
            {
                cin>>Tip;
            }
            while(Tip>2 or Tip<1);

            for(int i=0; i<8; i++)
            {
                if(AIRPORT[i].TIP==Tip)
                {
                    cout<<"Самолёт №"<<AIRPORT[i].NUMR<<" типа - ";
                    if (Tip==1)
                        cout<<"грузовой";
                    else
                        cout<<"пассажирский";
                    cout<<", отправляется в: "<<AIRPORT[i].NAZN<<endl;
                    k++;
                }


            }
            if (k==0)
                cout<<"К сожалению, данных типов самолётов на данный момент нет."<<endl;

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
            char Nazn[30];
            int k = 0;

            cout<<"Введите название пункта назначения: ";
            cin>>Nazn;

            for(int i=0; i<8; i++)
            {
                if(strcmp(Nazn,AIRPORT[i].NAZN)==0)
                {
                    k++;
                    cout<<"Самолёт №"<<AIRPORT[i].NUMR<<" типа - ";
                    if (AIRPORT[i].TIP==1)
                        cout<<"грузовой";
                    else
                        cout<<"пассажирский";
                    cout<<", отправляется в: "<<AIRPORT[i].NAZN<<endl;
                    k++;
                }
            }
            if (k==0)
                cout<<"К сожалению, рейсов в "<<Nazn<<" нет."<<endl;

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
