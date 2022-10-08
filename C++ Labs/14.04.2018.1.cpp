//Написать функцию, которая удаляет в строке символов n символов, начиная с позиции p. Через Void;

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cstring>

using namespace std;

void Str(char *STROKA, int &x, int &y)
{
    int LenghtSTR = strlen(STROKA);

    for (int i=0; i<LenghtSTR; i++)
    {
        if (i == x)
        {
            int j = i;
            do
            {
                STROKA[j] = STROKA[j + y];
                j++;
            }
            while (STROKA[j + y]);
            STROKA[j] = '\0';
        }
    }

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char String[250];

    cout<<"Введите строку: ";
    gets(String);

    int n = strlen(String);
    int POZITION, KOLICHESTVO;

    cout<<endl<<"Введите позицию, с которой начнётся удаление символов: ";
    while (!(cin>>POZITION) or POZITION<=0 or POZITION>n)//Вводим значение и если это не цифра, начинается цикл (! - not)
    {
        cout<<"Ошибка, вы ввели что-то не то.\n ";
        cin.clear();//Очищает поток
        cin.sync();//Удаляет данные из буффера
        cout<<"\nПовторите ввод: ";
    }
    POZITION--;

    cout<<endl<<"Введите количество символов, которые необходимо удалить: ";
     while (!(cin>>KOLICHESTVO) or KOLICHESTVO<=0 or KOLICHESTVO>n)//Вводим значение и если это не цифра, начинается цикл (! - not)
    {
        cout<<"Ошибка, вы ввели что-то не то.\n ";
        cin.clear();//Очищает поток
        cin.sync();//Удаляет данные из буффера
        cout<<"\nПовторите ввод: ";
    }

    Str(String,POZITION,KOLICHESTVO);

    cout<<endl<<"Ваша строка в новом формате: ";
    for (int i=0; i<strlen(String); i++)
    {
        cout<<String[i];
    }

}
