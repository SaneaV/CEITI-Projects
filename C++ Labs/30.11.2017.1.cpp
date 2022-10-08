//Даны две строки, выяснить совпадают ли их длины

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
    int n=0,n1=0;
    n = strlen(s1);
    n1 = strlen(s2);
    if (n==n1) cout<<"Строки равной длины";
    else cout<<"Строки разной длины";

}
