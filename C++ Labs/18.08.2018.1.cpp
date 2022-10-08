//»спользу€ тип данных запись с именем TRAIN, содержащую следующие пол€:
//Х NAZN Ц название пункта назначени€;
//Х NUMR Ц номер поезда;
//Х TIME Ц врем€ отправлени€.
//Ќаписать программу, выполн€ющую следующие действи€:
//Х ввод с клавиатуры данных в массив RASP, состо€щий из 8 записей типа TRAIN;
//Х вывод на экран †информации о поездах, отправл€ющихс€ после введенного с клавиатуры времени;
//если таких поездов нет, вывести соответствующее сообщение.
//Х вывод на экран информации о поездах, направл€ющихс€ в пункт, название которого введено с клавиатуры;
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
        cout<<"¬ведите название пункта назначени€: ";
        cin.ignore();
        gets(TRAIN[i].NAZN);

        cout<<"¬ведите номер поезда: ";
        cin>>TRAIN[i].NUMR;

        cout<<"¬ведите врем€ отправлени€ поезда(чч:мм): ";
        cin>>TRAIN[i].Hour>>l>>TRAIN[i].Minute;

        system("cls");
    }

    int Select;
    int RepeatSelect;
    bool Menu = true;

    while(Menu)
    {
        cout<<"1.”знать поезда отправл€ющиес€ после введЄного времени."<<endl;
        cout<<"2.”знать о поездах, направл€ющихс€ в..."<<endl;
        cout<<"¬аш выбор: ";
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
            cout<<"¬ведите врем€(чч:мм): ";
            cin>>H>>l>>M;

            for(int i=0; i<8; i++)
            {
                if(H<TRAIN[i].Hour and H>=0 and H<=12)
                {
                    k++;
                    cout<<"ѕоезд є "<<TRAIN[i].NUMR<<" отправл€етс€ в "<<TRAIN[i].NAZN<<" в "<<TRAIN[i].Hour<<":"<<TRAIN[i].Minute<<endl;

                }
                if(H<TRAIN[i].Hour and H>=12 and H<=23)
                {
                    k++;
                    cout<<"ѕоезд є "<<TRAIN[i].NUMR<<" отправл€етс€ в "<<TRAIN[i].NAZN<<" в "<<TRAIN[i].Hour<<":"<<TRAIN[i].Minute<<endl;

                }
                if(H==TRAIN[i].Hour)
                {
                    if(M>=TRAIN[i].Minute)
                    {
                        k++;
                        cout<<"ѕоезд є "<<TRAIN[i].NUMR<<" отправл€етс€ в "<<TRAIN[i].NAZN<<" в "<<TRAIN[i].Hour<<":"<<TRAIN[i].Minute<<endl;
                    }
                }
            }
            if (k==0)
                cout<<"  сожалению, рейсов на данное врем€ нет"<<endl;

            cout<<endl<<endl;
            cout<<"1. ¬ернутьс€ в меню."<<endl;
            cout<<"2. ¬ыйти из программы."<<endl;
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

            cout<<"¬ведите название пункта назначени€: ";
            cin.ignore();
            gets(Nazn);

            for(int i=0; i<8; i++)
            {
                if(strcmp(Nazn,TRAIN[i].NAZN)==0)
                {
                    k++;
                    cout<<"ѕоезд є "<<TRAIN[i].NUMR<<" отправл€етс€ в "<<TRAIN[i].NAZN<<" в "<<TRAIN[i].Hour<<":"<<TRAIN[i].Minute<<endl;
                }
            }
            if (k==0)
                cout<<"  сожалению, рейсов в "<<Nazn<<" нет."<<endl;

                cout<<endl<<endl;
                cout<<"1. ¬ернутьс€ в меню."<<endl;
                cout<<"2. ¬ыйти из программы."<<endl;
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
