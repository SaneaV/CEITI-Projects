#include <iostream>
#include <stdio.h>
#include <cstring>
#include <windows.h>
#include <ctime>

using namespace std;

main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<"\t\t\tДобро пожаловать!"<<endl;

    cout<<"Введите количество человек: ";
    int n;
    cin>>n;

    Sleep(500);
    system("cls");


    struct Persona
    {
        char Name[50];
        char Surname[50];
        int DayBD;
        int MonthBD;
        int YearBD;
    } p[50];

    for (int i=0; i<n; i++)
    {
        cin.ignore();
        cout<<"Введите фамилию человека: ";
        gets(p[i].Surname);

        cout<<"Введите имя человека: ";
        gets(p[i].Name);

        cout<<"Введите день рождения: ";
        cin>>p[i].DayBD;

        cout<<"Введите месяц рождения: ";
        cin>>p[i].MonthBD;

        cout<<"Введите год рождения: ";
        cin>>p[i].YearBD;

        cout<<endl<<endl;
        system("cls");


    }


    char y;
    bool yy;

    do
    {
        system("cls");
        int vib=0;

        cout<<"Выберите, что вы хотите узнать о этих людях:"<<endl<<endl;
        cout<<"1.Люди, чьи имена начинаются на букву \"А\"."<<endl;
        cout<<"2.Люди, чей год рожденя будет равен вашему значению."<<endl;
        cout<<"3.Самый старший человек в списке. "<<endl;
        cout<<"4.Возраст всех людей. "<<endl;
        cout<<"5.Список лиц старше вашего значения. "<<endl;
        cout<<"6.Вывести весь список людей. "<<endl;
        cout<<endl<<"Вы выбираете: ";
        cin>>vib;

        Sleep(500);
        system("cls");

        switch(vib)
        {
        case (1):
        {
            cout<<"Люди, чьи имена начинаются на букву \"А\""<<endl<<endl;
            int k=0;

            for (int i=0; i<n; i++)
            {
                if (p[i].Name[0]=='А')
                {
                    cout<<p[i].Name<<" "<<p[i].Surname<<endl;
                    k++;
                }
            }

            if (k==0)
                cout<<"Людей, с именем на букву \"А\" в данном списке нет.";

            cout<<endl<<endl<<endl<<"Вы хотите вернуться в меню (y/n): ";
            cin>>y;
            if (y=='y')
                yy=true;
            else
                yy=false;
            break;
        }

        case (2):
        {
            cout<<"Введите любой год рождения: ";
            int a, k1=0;
            cin>>a;
            cout<<endl<<endl<<"Люди, чей год рожденя "<<a<<endl<<endl;

            for (int i=0; i<n; i++)
            {
                if (p[i].YearBD==a)
                {
                    cout<<p[i].Name<<" "<<p[i].Surname<<endl;
                    k1++;
                }
            }
            if (k1==0)
                cout<<"Людей, с именем на букву \"А\" в данном списке нет.";

            cout<<endl<<endl<<endl<<"Вы хотите вернуться в меню (y/n): ";
            cin>>y;
            if (y=='y')
                yy=true;
            else
                yy=false;
            break;

        }

        case (3):
        {


            cout<<"Самый старший человек в списке: "<<endl;
            int pmax=0;

            for (int j=1; j<n; j++)
            {
                if (p[j].YearBD < p[pmax].YearBD)
                    pmax=j;
                else if (p[j].YearBD==p[pmax].YearBD and p[j].MonthBD < p[pmax].MonthBD)
                    pmax=j;
                else if (p[j].YearBD==p[pmax].YearBD and p[j].MonthBD==p[pmax].MonthBD and p[j].DayBD<p[pmax].DayBD)
                    pmax=j;

            }

            cout<<p[pmax].Name<<" "<<p[pmax].Surname<<endl;

            cout<<endl<<endl<<endl<<"Вы хотите вернуться в меню (y/n): ";
            cin>>y;
            if (y=='y')
                yy=true;
            else
                yy=false;
            break;

        }

        case (4):
        {


            cout<<"Возраст всех людей: "<<endl<<endl;
            int god=0,mes=0,deni=0;
            int godN=0, mesN=0,deniN=0;

            cout<<"Введите сегодняшний год: ";
            cin>>god;
            cout<<"Ввидете номер сегодняшнего месяца: ";
            cin>>mes;
            cout<<"Введите сегодняшнюю дату: ";
            cin>>deni;

            cout<<endl<<endl;

            for (int i=0; i<n; i++)
            {
                godN=god-p[i].YearBD;//Количество лет

                if (mes<p[i].MonthBD)//Если день рождения ещё не наступил
                {
                    godN--;
                    if (deni==p[i].DayBD)
                    {
                        mesN=12-p[i].MonthBD+mes;
                        deniN=0;
                    }
                    if (deni>p[i].DayBD)
                    {
                        mesN=12-p[i].MonthBD+mes;
                        deniN=deni-p[i].DayBD;
                    }
                    if (deni<p[i].DayBD)
                    {
                        mesN=12-p[i].MonthBD+mes-1;

                        if ((god % 4 == 0) && ((god % 100 != 0) || (god % 400 == 0)))
                        {
                            switch(mes)
                            {
                            case 1:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 2:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 3:
                            {
                                deniN=29-(p[i].DayBD-deni);
                                break;
                            }
                            case 4:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 5:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 6:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 7:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 8:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 9:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 10:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 11:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 12:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            }
                        }
                        else
                        {
                            switch(mes)
                            {
                            case 1:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 2:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 3:
                            {
                                deniN=28-(p[i].DayBD-deni);
                                break;
                            }
                            case 4:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 5:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 6:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 7:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 8:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 9:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 10:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 11:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 12:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }

                            }

                        }


                    }

                }

                if (mes>p[i].MonthBD) //Если день рождения уже прошёл
                {
                    deniN=p[i].DayBD-deni;
                    if (deniN<0)
                        deniN*=-1;
                }


                if (mes==p[i].MonthBD) //Если данный месяц и есть месяц дня
                {
                    if (deni==p[i].DayBD)
                    {
                        deniN=0;
                        mesN=0;
                    }

                    else if (deni>p[i].DayBD)
                    {
                        deniN=deni-p[i].DayBD;
                    }

                    else if (deni<p[i].DayBD)
                    {
                        godN--;


                        if ((god % 4 == 0) && ((god % 100 != 0) || (god % 400 == 0)))
                        {
                            switch(mes)
                            {
                            case 1:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 2:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 3:
                            {
                                deniN=29-(p[i].DayBD-deni);
                                break;
                            }
                            case 4:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 5:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 6:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 7:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 8:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 9:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 10:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 11:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 12:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            }
                        }
                        else
                        {
                            switch(mes)
                            {
                            case 1:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 2:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 3:
                            {
                                deniN=28-(p[i].DayBD-deni);
                                break;
                            }
                            case 4:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 5:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 6:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 7:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 8:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 9:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 10:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }
                            case 11:
                            {
                                deniN=31-(p[i].DayBD-deni);
                                break;
                            }
                            case 12:
                            {
                                deniN=30-(p[i].DayBD-deni);
                                break;
                            }

                            }

                        }

                    }

                }

                cout<<p[i].Name<<" "<<p[i].Surname<<"  "<<endl<<godN<<" лет, "<<mesN<<" месяцев, "<<deniN<<" дней."<<endl;


            }

            cout<<endl<<endl<<endl<<"Вы хотите вернуться в меню (y/n): ";
            cin>>y;
            if (y=='y')
                yy=true;
            else
                yy=false;
            break;
        }


        case (5):
        {
            cout<<"Список лиц, старше вашего значения."<<endl<<endl;

            cout<<"Введите ваше значение (К примеру, люди старше 20 лет): ";
            int znachenie;
            int pznachenie;
            cin>>znachenie;
            int schet=0;

            znachenie=2018-znachenie;

            cout<<endl<<endl<<endl<<"Люди старше вашего значение: "<<endl<<endl;

            for (int j=0; j<n; j++)
            {
                if (p[j].YearBD < znachenie)
                {
                    cout<<p[j].Name<<" "<<p[j].Surname<<endl;
                    schet++;
                }

            }

            if (schet==0)
                cout<<"Людей старше вашего значения нет.";


            cout<<endl<<endl<<endl<<"Вы хотите вернуться в меню (y/n): ";
            cin>>y;
            if (y=='y')
                yy=true;
            else
                yy=false;
            break;

        }


        case (6):
        {
            cout<<"Весь список людей: "<<endl<<endl;

            for (int i=0; i<n; i++)
            {
                cout<<p[i].Name<<"\t"<<p[i].DayBD<<"\t"<<p[i].MonthBD<<"\t"<<p[i].YearBD<<endl;
            }

            cout<<endl<<endl<<endl<<"Вы хотите вернуться в меню (y/n): ";
            cin>>y;
            if (y=='y')
                yy=true;
            else
                yy=false;
            break;
        }
        }

    }
    while (yy);



}

