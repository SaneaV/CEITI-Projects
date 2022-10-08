//Вывести на экран слова, с чётным количеством букв

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <windows.h>

using namespace std;

main()
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"Russian");

    cout<<"Введите строку: ";
    char s[200];
    gets(s);

    char s1[20]=" !-?,._";

    char *uc=strtok(s,s1);

    int n=0;
    int k=0;

    while (uc!=NULL)
    {
        n=strlen(uc);
        if (n%2==0) {cout<<uc<<endl;k++;}
        uc=strtok(NULL,s1);
    }

    if (k==0) cout<<"Слов с чётным количество букв нет";
}
