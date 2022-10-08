#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include "BAC.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);

    HELLO();
    bool Main = false;

    while (!Main)
    {
        system("cls");
        bool SmallMain = false;
        cout<<"||=================================================||"<<endl<<"||";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
        cout<<setw(33)<<"Добро пожаловать!";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<setw(18)<<"||"<<endl;
        cout<<"||"<<setw(51)<<"||"<<endl;

        cout<<"||=================================================||"<<endl;
        cout<<"||=================================================||"<<endl;
        cout<<"||1. Информация о учениках."<<setw(26)<<"||"<<endl;
        cout<<"||=================================================||"<<endl;
        cout<<"||2. Добавить ученика в списки."<<setw(22)<<"||"<<endl;
        cout<<"||=================================================||"<<endl;
        cout<<"||3. Удалить ученика из списков."<<setw(21)<<"||"<<endl;
        cout<<"||=================================================||"<<endl;
        cout<<"||4. Сортировка учеников."<<setw(28)<<"||"<<endl;
        cout<<"||=================================================||"<<endl;
        cout<<"||5. Исправление оценок за БАК."<<setw(22)<<"||"<<endl;
        cout<<"||=================================================||"<<endl;
        cout<<"||6. Ученики из одного школьного учереждения."<<setw(8)<<"||"<<endl;
        cout<<"||=================================================||"<<endl;
        cout<<"||7. Ученики с отрицательным баллом."<<setw(17)<<"||"<<endl;
        cout<<"||=================================================||"<<endl;
        cout<<"||8. Средний балл по учебному учереждению."<<setw(11)<<"||"<<endl;
        cout<<"||=================================================||"<<endl;
        cout<<"||9. Ученики, подавшие на аппеляцию."<<setw(17)<<"||"<<endl;
        cout<<"||=================================================||"<<endl<<"||";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
        cout<<"0. Выход из программы.";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<setw(29)<<"||"<<endl<<"||=================================================||"<<endl;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<"||Над программой работал: ";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
        cout<<"Вичев Александр";
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
        cout<<setw(12)<<"||"<<endl;
        cout<<"||=================================================||"<<endl;
        cout<<"   Дата и время открытия: "<<asctime(timeinfo);


        if (_kbhit)
        {
            switch(getch())
            {
            case '1':
            {
                while (!SmallMain)
                {
                    system("cls");
                    cout<<"||=================================================||"<<endl<<"||";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
                    cout<<setw(35)<<"Информация о учениках.";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                    cout<<setw(16)<<"||"<<endl<<"||=================================================||"<<endl<<"||";
                    cout<<"1. Посмотреть общий список."<<setw(24)<<"||"<<endl;
                    cout<<"||=================================================||"<<endl<<"||";
                    cout<<"2. Посмотреть список подавших на аппеляцию."<<setw(8)<<"||"<<endl;
                    cout<<"||=================================================||"<<endl<<"||";
                    cout<<"3. Вернуться в меню."<<setw(31)<<"||"<<endl;
                    cout<<"||=================================================||"<<endl;

                    if(_kbhit)
                    {
                        switch (getch())
                        {
                        case '1':
                        {
                            system("cls");
                            READTXT1();
                            ShowInfoStudent();
                            system("PAUSE");
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        case '2':
                        {
                            system("cls");
                            READTXT2();
                            ShowInfoAppeal();
                            system("PAUSE");
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        case '3':
                        {
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        default:
                        {
                            system("cls");
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                            cout<<"||=================================================||"<<endl<<"||";
                            cout<<setw(40)<<"ВЫБЕРИТЕ СУЩЕСТВУЮЩИЙ ВАРИАНТ!"<<setw(11)<<"||"<<endl;
                            cout<<"||=================================================||"<<endl;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            Sleep(500);
                        }
                        }

                    }
                }
                break;
            }
            case '2':
            {
                while (!SmallMain)
                {
                    system("cls");
                    cout<<"||====================================================||"<<endl<<"||";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
                    cout<<setw(30)<<"Добавить ученика.";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                    cout<<setw(24)<<"||"<<endl<<"||====================================================||"<<endl<<"||";
                    cout<<"1. Добавить ученика в общий список."<<setw(19)<<"||"<<endl;
                    cout<<"||====================================================||"<<endl<<"||";
                    cout<<"2. Добавить ученика в список подавших на аппеляцию."<<" ||"<<endl;
                    cout<<"||====================================================||"<<endl<<"||";
                    cout<<"3. Вернуться в меню."<<setw(34)<<"||"<<endl;
                    cout<<"||====================================================||"<<endl;

                    if (_kbhit)
                    {
                        switch (getch())
                        {
                        case '1':
                        {
                            system("cls");
                            READTXT1();
                            AddStudent();
                            cout<<"||====================================================||"<<endl<<"||";
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
                            cout<<setw(35)<<"Студент добавлен!";
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            cout<<setw(19)<<"||"<<endl<<"||====================================================||"<<endl<<endl;
                            system("PAUSE");
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        case '2':
                        {
                            system("cls");
                            READTXT2();
                            AddAppel();
                            cout<<"||====================================================||"<<endl<<"||";
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
                            cout<<setw(35)<<"Студент добавлен!";
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            cout<<setw(19)<<"||"<<endl<<"||====================================================||"<<endl<<endl;
                            system("PAUSE");
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        case '3':
                        {
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        default:
                        {
                            system("cls");
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                            cout<<"||=================================================||"<<endl<<"||";
                            cout<<setw(40)<<"ВЫБЕРИТЕ СУЩЕСТВУЮЩИЙ ВАРИАНТ!"<<setw(11)<<"||"<<endl;
                            cout<<"||=================================================||"<<endl;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            Sleep(500);
                        }
                        }
                    }
                }
                break;
            }


            case '3':
            {
                while (!SmallMain)
                {
                    system("cls");
                    cout<<"||====================================================||"<<endl<<"||";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
                    cout<<setw(34)<<"Удалить ученика.";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                    cout<<setw(20)<<"||"<<endl<<"||====================================================||"<<endl<<"||";
                    cout<<"1. Удалить ученика из общего списка."<<setw(18)<<"||"<<endl;
                    cout<<"||====================================================||"<<endl<<"||";
                    cout<<"2. Удалить ученика из списка подавших на аппеляцию."<<" ||"<<endl;
                    cout<<"||====================================================||"<<endl<<"||";
                    cout<<"3. Вернуться в меню."<<setw(34)<<"||"<<endl;
                    cout<<"||====================================================||"<<endl;

                    if (_kbhit)
                    {
                        switch (getch())
                        {
                        case '1':
                        {
                            system("cls");
                            READTXT1();
                            READTXT2();
                            DelStudent();
                            system("PAUSE");
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        case '2':
                        {
                            system("cls");
                            READTXT2();
                            DelAppel();
                            system("PAUSE");
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        case '3':
                        {
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        default:
                        {
                            system("cls");
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                            cout<<"||=================================================||"<<endl<<"||";
                            cout<<setw(40)<<"ВЫБЕРИТЕ СУЩЕСТВУЮЩИЙ ВАРИАНТ!"<<setw(11)<<"||"<<endl;
                            cout<<"||=================================================||"<<endl;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            Sleep(500);
                        }
                        }
                    }
                }
                break;
            }

            case '4':
            {
                while (!SmallMain)
                {
                    system("cls");
                    cout<<"||====================================================||"<<endl<<"||";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
                    cout<<setw(35)<<"Сортировка учеников.";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                    cout<<setw(19)<<"||"<<endl<<"||====================================================||"<<endl<<"||";
                    cout<<"1. Сортировать гуманитариев."<<setw(26)<<"||"<<endl;
                    cout<<"||====================================================||"<<endl<<"||";
                    cout<<"2. Сортировать реальников."<<setw(28)<<"||"<<endl;
                    cout<<"||====================================================||"<<endl<<"||";
                    cout<<"3. Вернуться в меню."<<setw(34)<<"||"<<endl;
                    cout<<"||====================================================||";

                    if (_kbhit)
                    {
                        switch (getch())
                        {
                        case '1':
                        {
                            system("cls");
                            READTXT1();
                            SortStudent();
                            OutputG();
                            system("PAUSE");
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        case '2':
                        {
                            system("cls");
                            READTXT1();
                            SortStudent();
                            OutputR();
                            system("PAUSE");
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        case '3':
                        {
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        default:
                        {
                            system("cls");
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                            cout<<"||=================================================||"<<endl<<"||";
                            cout<<setw(40)<<"ВЫБЕРИТЕ СУЩЕСТВУЮЩИЙ ВАРИАНТ!"<<setw(11)<<"||"<<endl;
                            cout<<"||=================================================||"<<endl;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            Sleep(500);
                        }
                        }
                    }
                }
                break;
            }

            case '5':
            {

                while (!SmallMain)
                {
                    READTXT1();
                    READTXT2();
                    CorrectionNotes();

                    system("cls");
                    cout<<"||====================================================||"<<endl<<"||";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
                    cout<<setw(43)<<"Исправление оценок прошло удачно!";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                    cout<<setw(11)<<"||"<<endl<<"||====================================================||"<<endl<<"||";
                    cout<<"1. Показать новый список."<<setw(29)<<"||"<<endl;
                    cout<<"||====================================================||"<<endl<<"||";
                    cout<<"2. Вернуться в меню."<<setw(34)<<"||"<<endl;
                    cout<<"||====================================================||";

                    if (_kbhit)
                    {
                        switch (getch())
                        {
                        case '1':
                        {
                            system("cls");
                            ShowInfoStudent();
                            system("PAUSE");
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        case '2':
                        {
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        default:
                        {
                            system("cls");
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                            cout<<"||=================================================||"<<endl<<"||";
                            cout<<setw(40)<<"ВЫБЕРИТЕ СУЩЕСТВУЮЩИЙ ВАРИАНТ!"<<setw(11)<<"||"<<endl;
                            cout<<"||=================================================||"<<endl;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            Sleep(500);
                        }
                        }
                    }
                }
                break;
            }

            case '6':
            {

                while (!SmallMain)
                {
                    system("cls");
                    cout<<"||====================================================||"<<endl<<"||";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
                    cout<<setw(47)<<"Ученики из одного учебного учереждения!";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                    cout<<setw(7)<<"||"<<endl<<"||====================================================||"<<endl<<"||";
                    cout<<"1. Записать данные в файл."<<setw(28)<<"||"<<endl;
                    cout<<"||====================================================||"<<endl<<"||";
                    cout<<"2. Показать данные в файле."<<setw(27)<<"||"<<endl;
                    cout<<"||====================================================||"<<endl<<"||";
                    cout<<"3. Вернуться в меню."<<setw(34)<<"||"<<endl;
                    cout<<"||====================================================||";

                    if (_kbhit)
                    {
                        switch (getch())
                        {
                        case '1':
                        {
                            system("cls");
                            READTXT1();
                            SchoolFile();
                            system("PAUSE");
                            SmallMain = true;
                            system("cls");
                            break;
                        }
                        case '2':
                        {
                            system("cls");
                            READTXT3();
                            ShowInfoSchool();
                            system("PAUSE");
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        case '3':
                        {
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        default:
                        {
                            system("cls");
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                            cout<<"||=================================================||"<<endl<<"||";
                            cout<<setw(40)<<"ВЫБЕРИТЕ СУЩЕСТВУЮЩИЙ ВАРИАНТ!"<<setw(11)<<"||"<<endl;
                            cout<<"||=================================================||"<<endl;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            Sleep(500);
                        }
                        }
                    }
                }
                break;
            }

            case '7':
            {

                while (!SmallMain)
                {
                    system("cls");
                    cout<<"||====================================================||"<<endl<<"||";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
                    cout<<setw(40)<<"Ученики с отрицательным баллом.";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                    cout<<setw(14)<<"||"<<endl<<"||====================================================||"<<endl<<"||";
                    cout<<"1. Из общего списка."<<setw(34)<<"||"<<endl;
                    cout<<"||====================================================||"<<endl<<"||";
                    cout<<"2. Из списка подавших на аппеляцию."<<setw(19)<<"||"<<endl;
                    cout<<"||====================================================||"<<endl<<"||";
                    cout<<"3. Вернуться в меню."<<setw(34)<<"||"<<endl;
                    cout<<"||====================================================||";

                    if (_kbhit)
                    {
                        switch (getch())
                        {
                        case '1':
                        {
                            system("cls");
                            READTXT1();
                            BadNote1();
                            system("PAUSE");
                            SmallMain = true;
                            system("cls");
                            break;
                        }
                        case '2':
                        {
                            system("cls");
                            READTXT2();
                            BadNote2();
                            system("PAUSE");
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        case '3':
                        {
                            system("cls");
                            SmallMain = true;
                            break;
                        }
                        default:
                        {
                            system("cls");
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                            cout<<"||=================================================||"<<endl<<"||";
                            cout<<setw(40)<<"ВЫБЕРИТЕ СУЩЕСТВУЮЩИЙ ВАРИАНТ!"<<setw(11)<<"||"<<endl;
                            cout<<"||=================================================||"<<endl;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            Sleep(500);
                        }
                        }
                    }
                }
                break;
            }



            case '8':
            {
                system("cls");
                READTXT1();
                MediumNote1();
                system("PAUSE");
                SmallMain = true;
                system("cls");
                break;
            }

            case '9':
            {
                system("cls");
                READTXT1();
                READTXT2();
                StupAppeal();
                system("PAUSE");
                break;
            }

            case '0':
            {
                while (!SmallMain)
                {
                    system("cls");
                    cout<<"||=================================================||"<<endl<<"||";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
                    cout<<setw(46)<<"Вы уверены, что хотите выйти из программы?";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                    cout<<setw(5)<<"||"<<endl<<"||"<<setw(51)<<"||"<<endl;
                    cout<<"||=================================================||"<<endl<<"||";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                    cout<<"\t1. Нет.";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
                    cout<<"\t\t\t\t2. Да.";
                    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                    cout<<setw(7)<<"||"<<endl<<"||=================================================||"<<endl;
                    if (_kbhit)
                    {
                        switch (getch())
                        {
                        case '1':
                        {
                            SmallMain = true;
                            break;
                        }
                        case '2':
                        {
                            SmallMain = true;
                            Main=true;
                            system("cls");
                            break;
                        }
                        default:
                        {
                            system("cls");
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                            cout<<"||=================================================||"<<endl<<"||";
                            cout<<setw(40)<<"ВЫБЕРИТЕ СУЩЕСТВУЮЩИЙ ВАРИАНТ!"<<setw(11)<<"||"<<endl;
                            cout<<"||=================================================||"<<endl;
                            SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                            Sleep(500);
                        }
                        }
                    }
                }
                break;

            }

            default:
            {
                system("cls");
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightRed));
                cout<<"||=================================================||"<<endl<<"||";
                cout<<setw(40)<<"ВЫБЕРИТЕ СУЩЕСТВУЮЩИЙ ВАРИАНТ!"<<setw(11)<<"||"<<endl;
                cout<<"||=================================================||"<<endl;
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
                Sleep(500);
                break;
            }
            }
        }
    }
    NICEWORK();
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
    cout<<"||=================================================||"<<endl<<"||";
    cout<<setw(45)<<"Программа успешно закончила выполнение."<<setw(6)<<"||"<<endl;
    cout<<"||=================================================||"<<endl;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));

    return 0;
}
