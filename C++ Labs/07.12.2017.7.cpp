//Дана строка символов, исключить из строки группы символов, расположенных между парами скобок. Сами скобки тоже должны быть исключены

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <windows.h>


using namespace std;

main()
{
    //setlocale (LC_ALL,"Rus");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<"Программа работает на русском"<<endl<<endl;
    cout<<"Введите предложение: ";

    char s[10000];
    char s2[10000];

    gets(s);

    int i=0,j=0;
    int n=strlen(s);

    while (i<n)
        {if (s[i]=='(' or s[i]=='{')
             {
                 for (;i<n;i++)
                 {
                     if (s[i]==')' or s[i]=='}')
                        {
                            i++;
                            break;
                        }
                 }
             }
                else {
                    s2[j]=s[i];
                    j++;
                    i++;
                }
    }

    puts(s2);
}
