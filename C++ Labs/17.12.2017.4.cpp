//ƒана строка символов†S,†состо€ща€ максимум из 250 символов.
//Ќапишите программу, котора€ проверит €вл€етс€ ли строка †S†палиндромом.
//ѕримеры палиндромов: СCOJOCТ, СCAZACТ, СPOTOPТ, СROTORТ.

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<"¬ведите слово: ";

    char str[255];
    char str2[255];
    gets(str);

    strcpy(str2,str);

    char x;

    for (int i=0; i<(strlen(str)/2); i++)
    {
        x = str[i];
        str[i]=str[(strlen(str)-1)-i];
        str[(strlen(str)-1)-i]=x;
    }


    cout<<endl;

    if (strcmp(str,str2)==0) cout<<"—лово €вл€етс€ палиндромом!";
    else cout<<"—лово не €вл€етс€ палиндромом!";

    cout<<endl<<endl;
}
