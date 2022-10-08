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

    if (strchr(s1,ch)==0) cout<<"Такой буквы в тексте нет";
    else cout<<strchr(s1,ch)-s1+1;

}
