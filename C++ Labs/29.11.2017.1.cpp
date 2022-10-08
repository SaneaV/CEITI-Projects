//Объединение строк

#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");

    char s1[1000],s2[1000];
    gets(s1);
    gets(s2);
    int n=5;
    strcat(s1,s2);
        cout<<s1;
}
