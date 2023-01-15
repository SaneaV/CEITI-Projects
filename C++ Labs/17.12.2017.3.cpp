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
    gets(str);

    char c;
    int n=0;
    int m=strlen(str)-1;
    char str2[255];
    strcpy(str2,str);

    while (n<m)
    {
        c=str[n];
        str[n]=str[m];
        str[m]=c;
        n++;
        m--;
    }

    cout<<endl;

    if (strcmp(str,str2)==0) cout<<"Слово является палиндромом!";
    else cout<<"Слово не является палиндромом!";

    cout<<endl<<endl;
}
