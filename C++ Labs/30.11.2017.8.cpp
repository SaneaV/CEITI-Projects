//С клавиатуры вводится целое число. Записать число без пятёрок и двоек.

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");
    char s1[1000],s2[1000];
    gets(s1);

    int n=strlen(s1);

    int i=0;
    while (i<n)
    {
        if (s1[i]=='5' or s1[i]=='2')
        {
            for (int j=i; j<n; j++)
            {
                s1[j]=s1[j+1];
            }
            n--;
        }
        else i++;
    }
    puts(s1);
}
