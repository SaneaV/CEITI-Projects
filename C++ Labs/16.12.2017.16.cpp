//Дана строка символов
//Удалить из данной строки все группы букв вида asdf

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");

    cout<<"Введите строку: ";

    char s[1000];
    gets(s);

    int n=strlen(s);
    int j=0;

    for (int i=0; i<n; i++)
    {
        if (s[i]!='a' and s[i+1]!='s' and s[i+2]!='d' and s[i+3]!='f')
        {
            s[j++]=s[i];
        }
        else i+=3;

    }
    s[j]=NULL;
    puts(s);
}
