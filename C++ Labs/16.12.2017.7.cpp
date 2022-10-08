//Дан текст, вывести все слова нечётной длины

#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout<<"Введите предложение: ";

    char s1[1000];
    char s2[20]=" !?,.";

    gets(s1);

    char *pch=strtok(s1,s2);
    int n=0;

    while (pch!=NULL)
    {
        n=strlen(pch);
        if (n%2!=0) cout<<pch<<endl;
        pch=strtok(NULL,s2);
    }
}
