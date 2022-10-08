//Дан текст, напишите программу, которая дублирует каждую его букву


#include <iostream>
#include <cstring>
#include <windows.h>
#include <stdio.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<"Введите предложение: ";

    char s[1000];
    gets(s);
    int n=strlen(s);


    for (int i=0;i<n;i++)
    {
        if (s[i])
        {
        n+=1;
        for (int j=n;j>i;j--)
        {
            s[j]=s[j-1];
        }
        s[i+1]=s[i];
        i++;
        }
    }

    puts(s);
}
