//Задана строка символов, каждое слово – последовательность, состоящая из одних цифр.
//Рассматривая каждое слово как число, определить сумму четных и нечетных значений элементов массива.

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<"Введите строку: ";

    char s1[1000];
    gets(s1);
    char s2[20]=" !.,-?";

    int m[1000];

    char *pch=strtok(s1,s2);
    int i=0;
    int k=0;

    while (pch!=NULL)
    {
        cout<<pch<<endl;
        m[i]=k;
        pch=strtok(NULL,s2);
        i++;
        k++;
    }
    int S=0,S2=0;

    for (int j=0;j<k;j++)
    {
        if (m[j]%2==0) S+=m[j];
        else S2+=m[j];
    }

    cout<<endl<<endl<<"Сумма чётных: "<<S<<endl;
    cout<<"Сумма нечётных: "<<S2<<endl;


}
