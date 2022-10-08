//Дана текст, напишите программу, которая заменяет буквы "а" на "о" и наоборот

#include <iostream>
#include <stdio.h>
#include <cstring>


using namespace std;

main()
{
    setlocale(LC_ALL,"Rus");

    cout<<"Программа работает только с английскими буквами!!!"<<endl<<endl;
    cout<<"Введите предложение: ";

    char s[10000];

    gets(s);

    for (int i=0;i<strlen(s);i++)
    {
        if (s[i]=='o') s[i]='a';
        else if (s[i]=='a') s[i]='o';
    }

    cout<<"Ваше новое предложение: "<<s<<endl;

}
