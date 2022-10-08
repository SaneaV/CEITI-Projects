//Заменить несколько пробелов на один

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout<<"Введите строку: ";

    char s[1000];

    gets(s);

    int n=strlen(s);

    int i=0,j=0;

    do
    {
        if (s[i]==' ' and s[i+1]==' ')
        {
            for (int j=i; j<n; j++)
            {
                s[j]=s[j+1];
            }
            i--;
            n--;
        }
        i++;
    }
    while (i<n);

    cout<<endl<<s<<endl;

}

