//»спользу€ тип данных запись с именем WORKER, содержащую следующие пол€:
//Х NAME Ц фамили€ и инициалы работника;
//Х POST Ц название занимаемой должности;
//Х YEAR Ц год поступлени€ на работу.
//Ќаписать программу, выполн€ющую следующие действи€:
//Х ввод с клавиатуры данных в массив TABL, состо€щий из 10 записей типа WORKER,
//Х вывод на экран †фамилий работников, чей стаж работы превышает значение, введенное с клавиатуры;
//если таких работников нет, вывести соответствующее сообщение.
//Х вывод на экран †данные о работнике, фамили€ и инициалы которого введены с клавиатуры;
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
        cout<<"¬ведите фамилию и инициалы работника(слитно): ";
        cin>>TABL[i].NAME;

        cout<<"¬ведите название занимаемой должности: ";
        cin>>TABL[i].POST;

        cout<<"¬ведите год поступлени€ на работу: ";
        cin>>TABL[i].YEAR;


            system("cls");
    }

    int Select;
    int RepeatSelect;
    bool Menu = true;

    while(Menu)
    {
        cout<<"1.”знать, кто работает больше чем..."<<endl;
        cout<<"2.”знать о работнике по его фамилии и инициалам."<<endl;
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
            int year;
            int ThisYear;
            int k=0;
            cout<<"¬ведите стаж работы: ";
            cin>>year;
            cout<<"¬ведите текущий год: ";
            cin>>ThisYear;

            for(int i=0; i<10 ; i++)
            {
                if((ThisYear-TABL[i].YEAR)>=year)
                {
                    cout<<"—таж работы "<<TABL[i].NAME<<" составл€ет: "<<ThisYear-TABL[i].YEAR<<endl;
                    k++;
                }


            }
            if (k==0)
                cout<<"  сожалению, никто ещЄ не отработал столько лет."<<endl;

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
            char Name[30];
            int k = 0;

            cout<<"¬ведите фамилию и инициалы человека: ";
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
                cout<<"  сожалению, такой человек у нас не работает."<<endl;

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
