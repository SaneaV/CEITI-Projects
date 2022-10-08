//Дан текст, подсчитать количество слов.

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cstring>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<"Введите строку: ";

    char s1[1000];
    char s2[20]=" ,.?!;";
    gets(s1);
    int k=0;

    char *pch=strtok(s1,s2);

    while (pch!=NULL)
    {
        k++;
        pch=strtok(NULL,s2);
    }

    cout<<"Количество слов в предложении: "<<k;
}
