//С клавиатуры вводится строка. Вывести её наоборот.

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <Windows.h>

using namespace std;

main()
{

    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    char s1[1000],s2[1000],l;
    cout<<"Введите ваши мысли: ";
    gets(s1);

    int n=strlen(s1);
    int p=n/2;

    for (int i=0;i<p;i++)
        {l=s1[i];
        s1[i]=s1[n-1];
        s1[n-1]=l;
        n--;
        }
        //s1[i]=s1[n--];
    cout<<"Ваши мысли наоборот: ";
    puts(s1);
}
