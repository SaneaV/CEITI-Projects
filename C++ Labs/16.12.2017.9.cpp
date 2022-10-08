//Дано слово.
//Напишите программу, которая отделяет в нём букву "а" пробелами.
//Например из слова "шахта" получим "ш а хт а".

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");

    cout<<"Введите строку: ";

    char s1[1000];
    gets(s1);

    int n=strlen(s1);

    for (int i=0; i<n; i++)
    {
        if (s1[i]=='a')
        {
            n+=2;
            for (int j=n;j>i;j--)
            {
                s1[j]=s1[j-2];
            }
            s1[i]=' ';
            s1[i+1]='a';
            s1[i+2]=' ';
            i+=2;
        }
    }
    puts(s1);
}

