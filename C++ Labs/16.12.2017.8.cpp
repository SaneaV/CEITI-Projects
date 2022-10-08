//Заменить в данной строке все слова "sau" на "ori"

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");

    cout<<"Введите предложение: ";

    char s1[1000];
    gets(s1);

    int n=strlen(s1);

    for (int i=0;i<n;i++)
    {
        if (s1[i]=='s' and s1[i+1]=='a' and s1[i+2]=='u')
        {
                s1[i]='o';
                s1[i+1]='r';
                s1[i+2]='i';
        }

    }

    puts (s1);
}
