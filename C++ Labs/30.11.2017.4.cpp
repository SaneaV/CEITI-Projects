//Подсчитать количество запятых в заданом тексте с помощью массива символов

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");
    char s1[1000],s2[1000];
    gets(s1);

    int k=0;
    int n=strlen(s1);
    for (int i=0;i<n;i++)
    {
        if (s1[i]==',') k++;
    }
    cout<<"Количество запятых: "<<k;




}
