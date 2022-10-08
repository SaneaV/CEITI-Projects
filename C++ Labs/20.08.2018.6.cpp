/*"Используя тип данных запись с именем ZNAK, содержащую следующие поля:
• NAME – фамилия, имя;
• ZODIAC – знак Зодиака;
• BDAY – день рождения (массив из трех чисел).
Написать программу, выполняющую следующие действия:
• ввод с клавиатуры данных в массив BOOK, состоящий из 8 записей типа ZNAK;
• вывод на экран  информации о человеке, чья фамилия введена с клавиатуры;
если такого нет, вывести соответствующее сообщение.
• вывод на экран  информации о людях, родившихся под знаком, название которого введено с клавиатуры;
если такого нет, вывести соответствующее сообщение.
• вывод на экран  информации о людях, чьи дни рождения приходятся на месяц, значение которого введено с клавиатуры;
если такого нет, вывести соответствующее сообщение.
*/

#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    struct BIRTHDAY
    {
        int Bday;
        int Bmonth;
        int Byear;
    };

    struct ZNAK
    {
        char Name[20];
        char Surname[20];
        int Zodiak;
        struct BIRTHDAY BDAY[10];
    } BOOK[8];

    char l;
    bool CheckTheDate = false;

    for(int i=0; i<8; i++)
    {
        cout<<"Введите фамилию человека: ";
        cin>>BOOK[i].Surname;
        cout<<"Введите имя человека: ";
        cin>>BOOK[i].Name;

        cout<<"Знаки зодиака: "<<endl;
        cout<<"1.Овен(21.03 - 19.04)\t         2.Телец(20.04 - 20.05)\t         3.Близнецы(21.05 - 20.06)\n4.Рак(21.06 - 22.07)\t         5.Лев(23.07 - 22.08)\t         6.Дева(23.08 - 22.09)\n";
        cout<<"7.Весы(23.09 - 22.10)\t         8.Скорпион(23.10 - 21.11)\t 9.Стрелец(22.11 - 21.12)\n10.Козерог(22.12 - 19.01)\t 11.Водолей(20.01 - 18.02)\t 12.Рыбы(19.02 - 20.03)"<<endl;
        cout<<"Выберите номер знака зодиака: ";
        do
        {
            cin>>BOOK[i].Zodiak;
        }
        while(BOOK[i].Zodiak>12 or BOOK[i].Zodiak<1);

        do
        {
            CheckTheDate = false;
            cout<<"Введите дату рождения(дд.мм.гггг): ";
            cin>>BOOK[i].BDAY[i].Bday>>l>>BOOK[i].BDAY[i].Bmonth>>l>>BOOK[i].BDAY[i].Byear;

//================================================================================================
//=========================================ОВЕН===================================================
            if (BOOK[i].Zodiak==1)
            {
                if(BOOK[i].BDAY[i].Bmonth!=3 and BOOK[i].BDAY[i].Bmonth!=4)
                {
                    CheckTheDate = true;
                    cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                }
                if(BOOK[i].BDAY[i].Bmonth==3)
                    if(BOOK[i].BDAY[i].Bday<21 or BOOK[i].BDAY[i].Bday>31)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
                if(BOOK[i].BDAY[i].Bmonth==4)
                    if(BOOK[i].BDAY[i].Bday<1 or BOOK[i].BDAY[i].Bday>19)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
            }
//================================================================================================
//=========================================ТЕЛЕЦ==================================================
            if (BOOK[i].Zodiak==2)
            {
                if(BOOK[i].BDAY[i].Bmonth!=4 and BOOK[i].BDAY[i].Bmonth!=5)
                {
                    CheckTheDate = true;
                    cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                }
                if(BOOK[i].BDAY[i].Bmonth==4)
                    if(BOOK[i].BDAY[i].Bday<20 or BOOK[i].BDAY[i].Bday>30)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
                if(BOOK[i].BDAY[i].Bmonth==5)
                    if(BOOK[i].BDAY[i].Bday<1 or BOOK[i].BDAY[i].Bday>20)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }

            }
//================================================================================================
//=========================================Близнецы================================================
            if (BOOK[i].Zodiak==3)
            {
                if(BOOK[i].BDAY[i].Bmonth!=5 and BOOK[i].BDAY[i].Bmonth!=6)
                {
                    CheckTheDate = true;
                    cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                }
                if(BOOK[i].BDAY[i].Bmonth==5)
                    if(BOOK[i].BDAY[i].Bday<21 or BOOK[i].BDAY[i].Bday>31)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
                if(BOOK[i].BDAY[i].Bmonth==6)
                    if(BOOK[i].BDAY[i].Bday<1 or BOOK[i].BDAY[i].Bday>20)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
            }
//================================================================================================
//=========================================РАК====================================================
            if (BOOK[i].Zodiak==4)
            {
                if (BOOK[i].BDAY[i].Bmonth!=6 and BOOK[i].BDAY[i].Bmonth!=7)
                {
                    CheckTheDate = true;
                    cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                }
                if(BOOK[i].BDAY[i].Bmonth==6)
                    if(BOOK[i].BDAY[i].Bday<21 or BOOK[i].BDAY[i].Bday>30)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
                if(BOOK[i].BDAY[i].Bmonth==7)
                    if(BOOK[i].BDAY[i].Bday<1 or BOOK[i].BDAY[i].Bday>22)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
            }
//================================================================================================
//=========================================ЛЕВ====================================================
            if (BOOK[i].Zodiak==5)
            {
                if (BOOK[i].BDAY[i].Bmonth!=7 and BOOK[i].BDAY[i].Bmonth!=8)
                {
                    CheckTheDate = true;
                    cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                }
                if(BOOK[i].BDAY[i].Bmonth==7)
                    if(BOOK[i].BDAY[i].Bday<23 or BOOK[i].BDAY[i].Bday>31)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
                if(BOOK[i].BDAY[i].Bmonth==8)
                    if(BOOK[i].BDAY[i].Bday<1 or BOOK[i].BDAY[i].Bday>22)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
            }
//================================================================================================
//=========================================ДЕВА====================================================
            if (BOOK[i].Zodiak==6)
            {
                if(BOOK[i].BDAY[i].Bmonth!=8 and BOOK[i].BDAY[i].Bmonth!=9)
                {
                    CheckTheDate = true;
                    cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                }
                if(BOOK[i].BDAY[i].Bmonth==8)
                    if(BOOK[i].BDAY[i].Bday<23 or BOOK[i].BDAY[i].Bday>31)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
                if(BOOK[i].BDAY[i].Bmonth==9)
                    if(BOOK[i].BDAY[i].Bday<1 or BOOK[i].BDAY[i].Bday>22)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
            }
//================================================================================================
//=========================================ВЕСЫ====================================================
            if (BOOK[i].Zodiak==7)
            {
                if (BOOK[i].BDAY[i].Bmonth!=9 and BOOK[i].BDAY[i].Bmonth!=10)
                {
                    CheckTheDate = true;
                    cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                }
                if(BOOK[i].BDAY[i].Bmonth==9)
                    if(BOOK[i].BDAY[i].Bday<23 or BOOK[i].BDAY[i].Bday>30)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
                if(BOOK[i].BDAY[i].Bmonth==10)
                    if(BOOK[i].BDAY[i].Bday<1 or BOOK[i].BDAY[i].Bday>22)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
            }
//================================================================================================
//=========================================СКОРПИОН===============================================
            if (BOOK[i].Zodiak==8)
            {
                if(BOOK[i].BDAY[i].Bmonth!=10 and BOOK[i].BDAY[i].Bmonth!=11)
                {
                    CheckTheDate = true;
                    cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                }
                if(BOOK[i].BDAY[i].Bmonth==10)
                    if(BOOK[i].BDAY[i].Bday<23 or BOOK[i].BDAY[i].Bday>31)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
                if(BOOK[i].BDAY[i].Bmonth==11)
                    if(BOOK[i].BDAY[i].Bday<1 or BOOK[i].BDAY[i].Bday>21)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
            }
//================================================================================================
//=========================================СТРЕЛЕЦ================================================
            if (BOOK[i].Zodiak==9)
            {
                if(BOOK[i].BDAY[i].Bmonth!=11 and BOOK[i].BDAY[i].Bmonth!=12)
                {
                    CheckTheDate = true;
                    cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                }
                if(BOOK[i].BDAY[i].Bmonth==11)
                    if(BOOK[i].BDAY[i].Bday<22 or BOOK[i].BDAY[i].Bday>30)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
                if(BOOK[i].BDAY[i].Bmonth==12)
                    if(BOOK[i].BDAY[i].Bday<1 or BOOK[i].BDAY[i].Bday>21)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
            }
//================================================================================================
//=========================================КОЗЕРОГ================================================
            if (BOOK[i].Zodiak==10)
            {
                if(BOOK[i].BDAY[i].Bmonth!=12 and BOOK[i].BDAY[i].Bmonth!=1)
                {
                    CheckTheDate = true;
                    cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                }
                if(BOOK[i].BDAY[i].Bmonth==12)
                    if(BOOK[i].BDAY[i].Bday<22 or BOOK[i].BDAY[i].Bday>31)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
                if(BOOK[i].BDAY[i].Bmonth==1)
                    if(BOOK[i].BDAY[i].Bday<1 or BOOK[i].BDAY[i].Bday>19)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
            }
//================================================================================================
//=========================================ВОДОЛЕЙ================================================
            if (BOOK[i].Zodiak==11)
            {
                if(BOOK[i].BDAY[i].Bmonth!=1 and BOOK[i].BDAY[i].Bmonth!=2)
                {
                    CheckTheDate = true;
                    cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                }
                if(BOOK[i].BDAY[i].Bmonth==1)
                    if(BOOK[i].BDAY[i].Bday<20 or BOOK[i].BDAY[i].Bday>30)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
                if(BOOK[i].BDAY[i].Bmonth==2)
                    if(BOOK[i].BDAY[i].Bday<1 or BOOK[i].BDAY[i].Bday>18)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
            }
//================================================================================================
//=========================================РЫБЫ===================================================
            if (BOOK[i].Zodiak==12)
            {
                if(BOOK[i].BDAY[i].Bmonth!=2 and BOOK[i].BDAY[i].Bmonth!=3)
                {
                    CheckTheDate = true;
                    cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                }
                if(BOOK[i].BDAY[i].Bmonth==2)
                    if(BOOK[i].BDAY[i].Bday<19 or BOOK[i].BDAY[i].Bday>29)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
                if(BOOK[i].BDAY[i].Bmonth==3)
                    if(BOOK[i].BDAY[i].Bday<1 or BOOK[i].BDAY[i].Bday>20)
                    {
                        CheckTheDate = true;
                        cout<<"Знак зодиака не совпадает с датой! Повторите ввод"<<endl;
                    }
            }
        }
        while(CheckTheDate);
        system("cls");

    }

    int Selection;
    int Reselection;
    bool FinishProgram = false;

    while(!FinishProgram)
    {
        cout<<"1.Узнать информацию о человеке по его фамилии."<<endl;
        cout<<"1.Узнать информацию о людях родившихся под определённым знаком Зодиака."<<endl;
        cout<<"3.Кто родился в месяц №... ."<<endl;
        cout<<"Ваш выбор: ";
        do
        {
            cin>>Selection;
        }
        while(Selection>3 or Selection<1);

        system("cls");

        switch(Selection)
        {
        case 1:
        {
            char Surname[20];
            int k=0;
            cout<<"Введите фамилию человека: ";
            cin>>Surname;

            for(int i=0; i<8; i++)
            {
                if(strcmp(Surname,BOOK[i].Surname)==0)
                {
                    cout<<BOOK[i].Name<<" "<<BOOK[i].Surname<<", знак Зодиака - ";
                    if (BOOK[i].Zodiak==1)
                        cout<<" овен";
                    if (BOOK[i].Zodiak==2)
                        cout<<" телец";
                    if (BOOK[i].Zodiak==3)
                        cout<<" близнецы";
                    if (BOOK[i].Zodiak==4)
                        cout<<" рак";
                    if (BOOK[i].Zodiak==5)
                        cout<<" лев";
                    if (BOOK[i].Zodiak==6)
                        cout<<" дева";
                    if (BOOK[i].Zodiak==7)
                        cout<<" весы";
                    if (BOOK[i].Zodiak==8)
                        cout<<" скорпион";
                    if (BOOK[i].Zodiak==9)
                        cout<<" стрелец";
                    if (BOOK[i].Zodiak==10)
                        cout<<" козерог";
                    if (BOOK[i].Zodiak==11)
                        cout<<" водолей";
                    if (BOOK[i].Zodiak==12)
                        cout<<" рыбы";
                    cout<<" ,родился: "<<BOOK[i].BDAY[i].Bday<<"."<<BOOK[i].BDAY[i].Bmonth<<"."<<BOOK[i].BDAY[i].Byear<<endl;
                    k++;
                }
            }
            if(k==0)
                cout<<"К сожалению, человек не найден"<<endl;

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
            int Zodiak;
            int k=0;

            cout<<"1.Овен 2.Телец 3.Близнецы 4.Рак 5.Лев 6.Дева\n";
            cout<<"7.Весы 8.Скорпион 9.Стрелец 10.Козерог 11.Водолей 12.Рыбы"<<endl;
            cout<<"Выберите номер знака зодиака: ";
            cin>>Zodiak;

            system("cls");


            cout<<"Люди, которые родились под знаком:";
            if (Zodiak==1)
                cout<<" Овен"<<endl;
            if (Zodiak==2)
                cout<<" Телец"<<endl;
            if (Zodiak==3)
                cout<<" Близнецы";
            if (Zodiak==4)
                cout<<" Рак"<<endl;
            if (Zodiak==5)
                cout<<" Лев"<<endl;
            if (Zodiak==6)
                cout<<" Дева"<<endl;
            if (Zodiak==7)
                cout<<" Весы"<<endl;
            if (Zodiak==8)
                cout<<" Скорпион";
            if (Zodiak==9)
                cout<<" Стрелец"<<endl;
            if (Zodiak==10)
                cout<<" Козерог"<<endl;
            if (Zodiak==11)
                cout<<" Водолей"<<endl;
            if (Zodiak==12)
                cout<<" Рыбы"<<endl;

            for(int i=0; i<8; i++)
            {
                if(BOOK[i].Zodiak==Zodiak)
                {
                    cout<<BOOK[i].Name<<" "<<BOOK[i].Surname;
                    cout<<" ,родился: "<<BOOK[i].BDAY[i].Bday<<"."<<BOOK[i].BDAY[i].Bmonth<<"."<<BOOK[i].BDAY[i].Byear<<endl;
                    k++;

                }
            }
            if(k==0)
                cout<<"К сожалению, под этим знаком Зодиака никого не найдено"<<endl;

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
        case 3:
        {
            int Month;
            int k=0;

            cout<<"Введите номер месяца: ";
            do
            {
                cin>>Month;
            }
            while(Month>12 or Month<1);

            for(int i=0; i<8; i++)
                if(Month==BOOK[i].BDAY[i].Bmonth)
                {
                    cout<<BOOK[i].Name<<" "<<BOOK[i].Surname<<" - знак Зодиака - ";
                    if (BOOK[i].Zodiak==1)
                        cout<<" овен";
                    if (BOOK[i].Zodiak==2)
                        cout<<" телец";
                    if (BOOK[i].Zodiak==3)
                        cout<<" близнецы";
                    if (BOOK[i].Zodiak==4)
                        cout<<" рак";
                    if (BOOK[i].Zodiak==5)
                        cout<<" лев";
                    if (BOOK[i].Zodiak==6)
                        cout<<" дева";
                    if (BOOK[i].Zodiak==7)
                        cout<<" весы";
                    if (BOOK[i].Zodiak==8)
                        cout<<" скорпион";
                    if (BOOK[i].Zodiak==9)
                        cout<<" стрелец";
                    if (BOOK[i].Zodiak==10)
                        cout<<" козерог";
                    if (BOOK[i].Zodiak==11)
                        cout<<" водолей";
                    if (BOOK[i].Zodiak==12)
                        cout<<" рыбы";
                    cout<<" - дата рождения - "<<BOOK[i].BDAY[i].Bday<<"."<<BOOK[i].BDAY[i].Bmonth<<"."<<BOOK[i].BDAY[i].Byear<<endl;
                    k++;
                }

            if(k==0)
                cout<<"К сожалению, человек не найден"<<endl;

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

