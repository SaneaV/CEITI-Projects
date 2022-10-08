//С клавиатуры вводятся две строки. Проверить совпадают ли они.

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");
    char s1[1000],s2[1000];
    gets(s1);
    gets(s2);
    if (stricmp(s1,s2)==0) {cout<<"Строки совпадают!";}

}
