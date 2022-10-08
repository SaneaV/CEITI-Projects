//Тест на знание урбанистики. Эксперементальная программа, работа с цветами.

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | Yellow));
    cout<<setw(40)<<"Добро пожаловать!"<<endl;
    char Name[20];
    cout<<"Введите ваше имя: ";
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 13));
    gets(Name);

    Sleep(1000);
    system("cls");

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 9));
    cout<<"Первый вопрос: "<<endl<<"\nУрбанистика это наука о: "<<endl<<"1. О животных."<<endl<<"2. О человеке."<<endl<<"3. О городах.";
    int x;
    int Score=0;
    cout<<endl<<endl<<"Ваш ответ: ";
    cin>>x;
    cout<<endl;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 12));
    if (x==3)
    {
        Score+=1;
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 2));
        cout<<"Вы угадали."<<endl<<"Ваш счёт: "<<Score;
    }
    else
        cout<<"Вы не угадали."<<endl<<"Ваш счёт: "<<Score;

    Sleep(1000);
    system("cls");

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 9));
    cout<<"Второй вопрос: "<<endl<<"\nВ приоритете всегда: "<<endl<<"1. Машина."<<endl<<"2. Пешеход."<<endl<<"3. Велосипедисты.";
    cout<<endl<<endl<<"Ваш ответ: ";
    cin>>x;
    cout<<endl;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 12));
    if (x==2)
    {
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 2));
        Score+=1;
        cout<<"Вы угадали."<<endl<<"Ваш счёт: "<<Score;
    }
    else
        cout<<"Вы не угадали."<<endl<<"Ваш счёт: "<<Score;

    Sleep(1000);
    system("cls");

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 9));
    cout<<"Третий вопрос: "<<endl<<"\nЧтобы избавиться от пробок, необходимо: "<<endl<<"1. Увеличить количество дорог."<<endl<<"2. Уменьшить количество дорог."<<endl<<"3. Ничего не делать.";
    cout<<endl<<endl<<"Ваш ответ: ";
    cin>>x;
    cout<<endl;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 12));
    if (x==2)
    {
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 2));
        Score+=1;
        cout<<"Вы угадали."<<endl<<"Ваш счёт: "<<Score;
    }
    else
        cout<<"Вы не угадали."<<endl<<"Ваш счёт: "<<Score;

    Sleep(1000);
    system("cls");

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 9));
    cout<<"Четверый вопрос: "<<endl<<"\nМодернизировать город выгодно? "<<endl<<"1. Да"<<endl<<"2. Нет."<<endl<<"3. Я из села.";
    cout<<endl<<endl<<"Ваш ответ: ";
    cin>>x;
    cout<<endl;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 12));
    if (x==1)
    {
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 2));
        Score+=1;
        cout<<"Вы угадали."<<endl<<"Ваш счёт: "<<Score;
    }
    else
        cout<<"Вы не угадали."<<endl<<"Ваш счёт: "<<Score;

    Sleep(1000);
    system("cls");

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 9));
    cout<<"Пятый вопрос: "<<endl<<"\nУрбанистический закон гласит: "<<endl<<"1. Чем больше этажей - тем лучше."<<endl<<"2. Дом должен быть на земле."<<endl<<"3. Дом должен быть не выше 6 этажей.";
    cout<<endl<<endl<<"Ваш ответ: ";
    cin>>x;
    cout<<endl;
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 12));
    if (x==3)
    {
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 2));
        Score+=1;
        cout<<"Вы угадали."<<endl<<"Ваш счёт: "<<Score;
    }
    else
        cout<<"Вы не угадали."<<endl<<"Ваш счёт: "<<Score;

    Sleep(1000);
    system("cls");

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 14));
    cout<<"Поздравляем "<<Name<<", вы прошли тест!"<<endl;
    cout<<"Ваш результат: "<<Score<<endl;
    if (Score==0)
    {
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 7));
        cout<<"Вы очень плохо знаете урбанистику.";
    }
    if (Score==1)
    {
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 4));
        cout<<"Вы плохо знаете урбанистику.";
    }
    if (Score==2)
    {
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 2));
        cout<<"Ваши знания в урбанистике могли бы быть и лучше.";
    }
    if (Score==3)
    {
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 3));
        cout<<"Вам стоит немного потрудится и вы поймёте урбанистику.";
    }
    if (Score==4)
    {
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 14));
        cout<<"Вы хорошо знаете урбанистику.";
    }
    if (Score==5)
    {
        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 10));
        cout<<"Вы отлично знаете урбанистику.";
    }

    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | 15));
        cout<<endl<<endl;
        system("pause");


}
