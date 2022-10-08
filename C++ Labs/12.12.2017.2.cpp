//Дана строка. Через каждые n символов добавить "!"

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    char s1[255];
    char s2[255];

    cout<<"Ваше предложение: ";
    gets(s1);

    int n;
    cout<<"Количество позиций: ";
    cin>>n;

    int i=0,j=0;

    while (i<strlen(s1))
    {
        if (i==n){s2[j]='!';i++;j++;n=n+n;}
        else {s2[j]=s1[i];i++;j++;}
    }

    puts(s2);
}
