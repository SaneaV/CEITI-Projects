//Заменить в строке, вводимой с клавиатуры, все вхождения «ku» на «za».

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
        if (s1[i]=='k' and s1[i+1]=='u') {s1[i]='z';s1[i+1]='a';}
            puts(s1);






}
