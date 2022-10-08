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
    gets(str);

    char c;
    int n=0;
    int m=strlen(str)-1;
    char str2[255];
    strcpy(str2,str);

    while (n<m)
    {
        c=str[n];
        str[n]=str[m];
        str[m]=c;
        n++;
        m--;
    }

    cout<<endl;

    if (strcmp(str,str2)==0) cout<<"—лово €вл€етс€ палиндромом!";
    else cout<<"—лово не €вл€етс€ палиндромом!";

    cout<<endl<<endl;
}
