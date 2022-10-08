//Даны текст и буква.
//Напищите программу, которая определяет содержиться ли данная букву в тексте
//При положительном ответе на экран выводится номер первой позиции буквы в тексте,
//В противном случае соотвественное сообщение

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");

    cout<<"Введите строку: ";

    char s1[1000];
    gets(s1);
    char ch;

    cout<<"Введите букву: ";

    cin>>ch;

    int n=strlen(s1);
    int k=0;
    int p=0;

    for (int i=0;i<n;i++)
    {
        if (s1[i]==ch) {p=i;k++;break;}
    }
    if (k==0) cout<<"Вашей буквы в тексте нет.";
    else cout<<"Позиция вашей буквы: "<<p+1;
}
