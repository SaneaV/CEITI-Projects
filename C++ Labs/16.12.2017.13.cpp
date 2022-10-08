//Дан текст, напишите программу, котроая заменяет в нём букву
//"a" на букву "о", если буква "а" находится на нечётной позиции
//и букву "е", если буква "а" находится на чётной позиции.

#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");

    cout<<"Введите строку: ";

    char str[1000];
    gets(str);

    for (int i=0;i<strlen(str); i++)
    {
        if (str[i]=='a' and i%2==0) str[i]='e';
        if (str[i]=='a' and i%2!=0) str[i]='o';
    }

    puts(str);
}
