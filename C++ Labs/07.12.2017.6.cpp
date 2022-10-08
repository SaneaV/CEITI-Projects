//Дан текст, вывести на экран слово минимальной длины

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <limits.h>


using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"Программа работает только с английскими буквами!!!"<<endl<<endl;
    cout<<"Введите предложение: ";

    char s[10000];
    char s2[20]=" !@#$%^&*()_+=-";

    gets(s);

    int min=INT_MAX;

    char *pch=strtok(s,s2);
    char *minslov=pch;

    while (pch!=NULL)
    {
        if (min>strlen(pch)) {min=strlen(pch);minslov=pch;}
        pch=strtok(NULL,s2);
    }

    cout<<"\nВаше минимальное слово: "<<minslov;
}


