//Дан текст.
//Напишите программу, которая заменятет в заданном тексте все буквы "o" (прописные или строчные)
//На букву "y" (прописные или строчные соответсвенно)

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");

    cout<<"Ввидет строку: ";

    char s1[1000];
    gets(s1);

    for (int i=0;i<strlen(s1);i++)
    {
        if (s1[i]=='o') s1[i]='y';
        if (s1[i]=='O') s1[i]='Y';
    }

    puts(s1);
}

