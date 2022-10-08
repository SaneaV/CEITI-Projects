//Программа выполняет переворот строки

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");

    cout<<"Ввидете строку: ";

    char s1[255];

    gets(s1);

    char c;

    int n=0;
    int m=strlen(s1)-1;

    while (n<m)
    {
        c=s1[n];
        s1[n]=s1[m];
        s1[m]=c;
        n++;
        m--;
    }

    cout<<s1;

}
