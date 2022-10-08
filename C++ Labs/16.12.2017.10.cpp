//Дано слово.
//Наишите программу, которая заменяет каждую букву пробелом
//Которому предшествует порядковый номер этой буквы в алфавите
//Например слову "мир" соответствует "13 10 17"

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"Введите слово: ";

    char str[255];
    gets(str);

    int n=strlen(str);

    char str2[1000];
    int j=0;

    for (int i=0;i<n;i++)
    {
        if (str[i]=='a' or str[i]=='A') {str2[j]='0'; str2[j+1]='1';}
        if (str[i]=='b' or str[i]=='B') {str2[j]='0'; str2[j+1]='2';}
        if (str[i]=='c' or str[i]=='C') {str2[j]='0'; str2[j+1]='3';}
        if (str[i]=='d' or str[i]=='D') {str2[j]='0'; str2[j+1]='4';}
        if (str[i]=='e' or str[i]=='E') {str2[j]='0'; str2[j+1]='5';}
        if (str[i]=='f' or str[i]=='F') {str2[j]='0'; str2[j+1]='6';}
        if (str[i]=='g' or str[i]=='G') {str2[j]='0'; str2[j+1]='7';}
        if (str[i]=='h' or str[i]=='H') {str2[j]='0'; str2[j+1]='8';}
        if (str[i]=='i' or str[i]=='I') {str2[j]='0'; str2[j+1]='9';}
        if (str[i]=='j' or str[i]=='J') {str2[j]='1'; str2[j+1]='0';}
        if (str[i]=='k' or str[i]=='K') {str2[j]='1'; str2[j+1]='1';}
        if (str[i]=='l' or str[i]=='L') {str2[j]='1'; str2[j+1]='2';}
        if (str[i]=='m' or str[i]=='M') {str2[j]='1'; str2[j+1]='3';}
        if (str[i]=='n' or str[i]=='N') {str2[j]='1'; str2[j+1]='4';}
        if (str[i]=='o' or str[i]=='O') {str2[j]='1'; str2[j+1]='5';}
        if (str[i]=='p' or str[i]=='P') {str2[j]='1'; str2[j+1]='6';}
        if (str[i]=='q' or str[i]=='Q') {str2[j]='1'; str2[j+1]='7';}
        if (str[i]=='r' or str[i]=='R') {str2[j]='1'; str2[j+1]='8';}
        if (str[i]=='s' or str[i]=='S') {str2[j]='1'; str2[j+1]='9';}
        if (str[i]=='t' or str[i]=='T') {str2[j]='2'; str2[j+1]='0';}
        if (str[i]=='u' or str[i]=='U') {str2[j]='2'; str2[j+1]='1';}
        if (str[i]=='v' or str[i]=='V') {str2[j]='2'; str2[j+1]='2';}
        if (str[i]=='w' or str[i]=='W') {str2[j]='2'; str2[j+1]='3';}
        if (str[i]=='x' or str[i]=='X') {str2[j]='2'; str2[j+1]='4';}
        if (str[i]=='y' or str[i]=='Y') {str2[j]='2'; str2[j+1]='5';}
        if (str[i]=='z' or str[i]=='Z') {str2[j]='2'; str2[j+1]='6';}
        str2[j+2]=' ';
        j+=3;
        str2[j+3]=NULL;

    }

    puts(str2);
}
