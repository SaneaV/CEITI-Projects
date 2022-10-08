//Дана строка символов.
//Преобразовать данную строку,
//Заменив в ней каждую точку многоточием

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<"Введите строку: ";

    char s[1000];
    gets (s);
    int n=strlen(s);

    for (int i=0;i<n;i++)
    {
        if (s[i]=='.')
        {
            n+=2;
            for (int j=n;j>i;j--)
            {
                s[j]=s[j-2];
            }
            s[i+1]='.';
            s[i+2]='.';
            i+=2;
        }
    }

    puts (s);
}
