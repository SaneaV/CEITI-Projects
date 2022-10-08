//»спользу€ тип данных запись с именем AEROFLOT, содержащую следующие пол€:
//Х NAZN Ц название пункта назначени€ рейса;
//Х NUMR Ц номер рейса;
//Х TIP Ц тип самолета.
//Ќаписать программу, выполн€ющую следующие действи€:
//Х ввод с клавиатуры данных в массив AIRPORT, состо€щий из 7 записей типа AEROFLOT;
//Х вывод на экран †пунктов назначени€ и номеров рейсов, обслуживаемых самолетом, типов которого введен с клавиатуры;
//если таких рейсов нет, вывести соответствующее сообщение.
//Х вывод на экран †номеров рейсов и типов самолетов, вылетающих в пункт назначени€, название которого введено с клавиатуры;
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
        cout<<"¬ведите название пункта назначени€: ";
        cin>>(AIRPORT[i].NAZN);

        cout<<"¬ведите номер рейса: ";
        cin>>AIRPORT[i].NUMR;

        cout<<"¬ведите тип самолЄта(1 - грузовой; 2 - пассажирский): ";
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
        cout<<"1.”знать о типах самолЄтов."<<endl;
        cout<<"2.”знать о самолЄтах, направл€ющихс€ в..."<<endl;
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
            int Tip;
            int k=0;
            cout<<"¬ведите тип самолЄта(1 - грузовой; 2 - пассажирский): ";
            do
            {
                cin>>Tip;
            }
            while(Tip>2 or Tip<1);

            for(int i=0; i<8; i++)
            {
                if(AIRPORT[i].TIP==Tip)
                {
                    cout<<"—амолЄт є"<<AIRPORT[i].NUMR<<" типа - ";
                    if (Tip==1)
                        cout<<"грузовой";
                    else
                        cout<<"пассажирский";
                    cout<<", отправл€етс€ в: "<<AIRPORT[i].NAZN<<endl;
                    k++;
                }


            }
            if (k==0)
                cout<<"  сожалению, данных типов самолЄтов на данный момент нет."<<endl;

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
            cin>>Nazn;

            for(int i=0; i<8; i++)
            {
                if(strcmp(Nazn,AIRPORT[i].NAZN)==0)
                {
                    k++;
                    cout<<"—амолЄт є"<<AIRPORT[i].NUMR<<" типа - ";
                    if (AIRPORT[i].TIP==1)
                        cout<<"грузовой";
                    else
                        cout<<"пассажирский";
                    cout<<", отправл€етс€ в: "<<AIRPORT[i].NAZN<<endl;
                    k++;
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
