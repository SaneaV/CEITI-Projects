//Написать функцию, которая удаляет в строке символов n символов, начиная с позиции p. Через Return;

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cstring>

using namespace std;

char Str(char STROKA[])
{
    cout<<"Введите строку: ";
    gets(STROKA);

    int POZITION, KOLICHESTVO;
    int n = strlen(STROKA);

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

    for (int i=0; i<n; i++)
    {
        if (i == POZITION)
        {
            int j = i;
            do
            {
                STROKA[j] = STROKA[j + KOLICHESTVO];
                j++;
            }
            while (STROKA[j + KOLICHESTVO]);
            STROKA[j] = '\0';
        }
    }


    return STROKA[0];
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char String[250];

    Str(String);

    cout<<endl<<"Ваша строка в новом формате: ";
    for (int i=0; i<strlen(String); i++)
    {
        cout<<String[i];
    }

}
