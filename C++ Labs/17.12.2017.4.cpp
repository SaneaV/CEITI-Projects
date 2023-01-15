//Дана строка символов S, состоящая максимум из 250 символов.
//Напишите программу, которая проверит является ли строка  S палиндромом.
//Примеры палиндромов: ‘COJOC’, ‘CAZAC’, ‘POTOP’, ‘ROTOR’.

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<"Введите слово: ";

    char str[255];
    char str2[255];
    gets(str);

    strcpy(str2,str);

    char x;

    for (int i=0; i<(strlen(str)/2); i++)
    {
        x = str[i];
        str[i]=str[(strlen(str)-1)-i];
        str[(strlen(str)-1)-i]=x;
    }


    cout<<endl;

    if (strcmp(str,str2)==0) cout<<"Слово является палиндромом!";
    else cout<<"Слово не является палиндромом!";

    cout<<endl<<endl;
}
