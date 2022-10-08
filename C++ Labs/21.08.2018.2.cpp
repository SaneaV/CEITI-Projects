/*Для заданного списка телевизионных программ известно:
-общее количество передач;
-название каждой передачи;
-телевизионный канал, на котором запрограммирована передача;
-вид каждой передачи (художественный фильм, новости, документальный фильм, развлекательная передача, мультфильм и т.д.);
-начало каждой передачи;
-конец каждой передачи.
Напишите программу, которая выводит на экран:
• Список мультфильмов передаваемых с 15:00 до 19:00;
• Список художественных фильмов продолжительностью свыше 1 часа 45 минут;
*/


#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;
    cout<<"Введите количество передач: ";
    cin>>n;

    system("cls");

    struct TELE
    {
        char Name[20];
        char ChanelName[10];
        char Type[20];

        int HoursB;
        int MinutesB;

        int HoursE;
        int MinutesE;
    } T[n];

    char l;

    for(int i=0; i<n; i++)
    {
        cout<<"Название передачи: ";
        cin>>T[i].Name;

        cout<<"Название канала: ";
        cin>>T[i].ChanelName;

        cout<<"Жанр передачи: ";
        cin>>T[i].Type;

        cout<<"Введите время начала передачи(чч:мм): ";
        cin>>T[i].HoursB>>l>>T[i].MinutesB;

        cout<<"Время окончания передачи(чч:мм): ";
        cin>>T[i].HoursE>>l>>T[i].MinutesB;
    }

    int Selection;
    int Reselection;
    bool FinishProgram = false;

    while(!FinishProgram)
    {
        cout<<"1. Список мультфильмов передаваемых с 15:00 до 19:00."<<endl;
        cout<<"2. Список художественных фильмов продолжительностью свыше 1 часа 45 минут."<<endl;
        cout<<"Ваш выбор: ";
        do
        {
            cin>>Selection;
        }
        while(Selection>2 or Selection<1);

        system("cls");

        switch(Selection)
        {
        case 1:
        {
            for(int i=0; i<n; i++)
            {
                if(strcmp(T[i].Type,"Mult")==0)
                    if(T[i].HoursB>15 and T[i].HoursB<19 or (T[i].HoursB==15 and T[i].MinutesB==0) or (T[i].HoursB==19 and T[i].MinutesB==0))
                    {
                        cout<<"На телеканале - "<<T[i].ChanelName<<" с "<<T[i].HoursB<<":"<<T[i].MinutesB;
                        cout<<" по "<<T[i].HoursE<<":"<<T[i].MinutesE<<" будет идти мультфильм под названием - "<<T[i].Name<<endl;
                    }
            }
            cout<<endl<<endl;
            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>Reselection;
            }
            while(Reselection>2 or Reselection<1);

            if (Reselection==1)
                system("cls");
            if(Reselection==2)
                FinishProgram=true;
            break;
        }
        case 2:
        {
            int Minutes = 0;
            int Hours = 0;

            for(int i=0; i<n; i++)
            {
                Minutes = 0;
                Hours = 0;

                if(strcmp(T[i].Type,"Hudoj")==0)
                {
                    Hours = T[i].HoursE - T[i].HoursB;
                    Minutes = abs(T[i].MinutesE - T[i].MinutesB);
                }
                if ((Hours==1 and Minutes>=45) or Hours>1)
                {
                    cout<<"На телеканале - "<<T[i].ChanelName<<" с "<<T[i].HoursB<<":"<<T[i].MinutesB;
                    cout<<" по "<<T[i].HoursE<<":"<<T[i].MinutesE<<" будет идти художественный фильм под названием - "<<T[i].Name<<endl;

                }
            }
            cout<<endl<<endl;
            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>Reselection;
            }
            while(Reselection>2 or Reselection<1);

            if (Reselection==1)
                system("cls");
            if(Reselection==2)
                FinishProgram=true;
            break;

        }
        }
    }
}
