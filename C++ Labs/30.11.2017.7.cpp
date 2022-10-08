//С клавиатуры вводится строка, подсчитать сколько раз встречается слово «kot» в данной строке.

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
    int k=0;
    for (int i=0;i<n;i++)
    if (s1[i]=='k' and s1[i+1]=='o' and s1[i+2]=='t') k++;
    cout<<k;

}

