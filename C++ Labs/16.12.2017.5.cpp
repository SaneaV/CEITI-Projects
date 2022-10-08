//Дана строка символов.
//Заменить в строке каждую группу букв child
//На children

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");

    cout<<"Введите строку: ";

    char s1[1000];
    gets(s1);

    int n=strlen(s1);

    for (int i=0; i<n; i++)
    {
        if (s1[i]=='c' and s1[i+1]=='h' and s1[i+2]=='i' and s1[i+3]=='l' and s1[i+4]=='d')
        {
            n+=3;
            for (int j=n; j>i+4; j--)
            {
                s1[j]=s1[j-3];
            }
            s1[i+5]='r';
            s1[i+6]='e';
            s1[i+7]='n';
        }
    }

    puts(s1);
}
