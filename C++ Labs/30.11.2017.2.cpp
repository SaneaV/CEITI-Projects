//Дана строка. Заменить все символы "а"на "*"

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
    for (int i=0;i<n;i++)
        {if (s1[i]=='a') {s1[i]='*';}}

    puts(s1);

}
