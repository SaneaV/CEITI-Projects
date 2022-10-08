//Напишите программу, которая дописывает букву "о" перед каждой буквой "а", которая идёт за буквой "н" заданного текста.

#include <iostream>
#include <stdio.h>
#include <cstring>


using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"Программа работает только с английскими буквами!!!"<<endl<<endl;
    cout<<"Введите предложение: ";

    char s[255];
    char s2[255];

    gets(s);

    int i=0,j=0;

    int n=strlen(s);

    for (int i=0; i<n; i++)
    {
        if (s[i-1]=='n' and s[i]=='a')
        {
            strncpy(s2,s,i);
            s2[i] = NULL;
            strcat(s2,"o");
            strcat(s2,s+i);
        }
    }
    cout<<"\nКак выглядит ваше слово по новому: "<<s2<<"\n";
}

