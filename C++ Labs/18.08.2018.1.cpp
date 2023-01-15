//Используя тип данных запись с именем TRAIN, содержащую следующие поля:
//• NAZN – название пункта назначения;
//• NUMR – номер поезда;
//• TIME – время отправления.
//Написать программу, выполняющую следующие действия:
//• ввод с клавиатуры данных в массив RASP, состоящий из 8 записей типа TRAIN;
//• вывод на экран  информации о поездах, отправляющихся после введенного с клавиатуры времени;
//если таких поездов нет, вывести соответствующее сообщение.
//• вывод на экран информации о поездах, направляющихся в пункт, название которого введено с клавиатуры;
//если таких поездов нет, вывести соответствующее сообщение.


#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    struct TRAIN
    {
        char NAZN[30];
        int NUMR;
        int Minute;
        int Hour;
    } TRAIN[7];

    char l;

    for(int i=0; i<8; i++)
    {
        cout<<"Введите название пункта назначения: ";
        cin.ignore();
        gets(TRAIN[i].NAZN);

        cout<<"Введите номер поезда: ";
        cin>>TRAIN[i].NUMR;

        cout<<"Введите время отправления поезда(чч:мм): ";
        cin>>TRAIN[i].Hour>>l>>TRAIN[i].Minute;

        system("cls");
    }

    int Select;
    int RepeatSelect;
    bool Menu = true;

    while(Menu)
    {
        cout<<"1.Узнать поезда отправляющиеся после введёного времени."<<endl;
        cout<<"2.Узнать о поездах, направляющихся в..."<<endl;
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
            int H,M;
            int k = 0;
            cout<<"Введите время(чч:мм): ";
            cin>>H>>l>>M;

            for(int i=0; i<8; i++)
            {
                if(H<TRAIN[i].Hour and H>=0 and H<=12)
                {
                    k++;
                    cout<<"Поезд № "<<TRAIN[i].NUMR<<" отправляется в "<<TRAIN[i].NAZN<<" в "<<TRAIN[i].Hour<<":"<<TRAIN[i].Minute<<endl;

                }
                if(H<TRAIN[i].Hour and H>=12 and H<=23)
                {
                    k++;
                    cout<<"Поезд № "<<TRAIN[i].NUMR<<" отправляется в "<<TRAIN[i].NAZN<<" в "<<TRAIN[i].Hour<<":"<<TRAIN[i].Minute<<endl;

                }
                if(H==TRAIN[i].Hour)
                {
                    if(M>=TRAIN[i].Minute)
                    {
                        k++;
                        cout<<"Поезд № "<<TRAIN[i].NUMR<<" отправляется в "<<TRAIN[i].NAZN<<" в "<<TRAIN[i].Hour<<":"<<TRAIN[i].Minute<<endl;
                    }
                }
            }
            if (k==0)
                cout<<"К сожалению, рейсов на данное время нет"<<endl;

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
            cin.ignore();
            gets(Nazn);

            for(int i=0; i<8; i++)
            {
                if(strcmp(Nazn,TRAIN[i].NAZN)==0)
                {
                    k++;
                    cout<<"Поезд № "<<TRAIN[i].NUMR<<" отправляется в "<<TRAIN[i].NAZN<<" в "<<TRAIN[i].Hour<<":"<<TRAIN[i].Minute<<endl;
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
