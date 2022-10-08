//Дана строка символов, подсчитать, сколько раз встречается буква x(икс)

#include <iostream>
#include <stdio.h>
#include <cstring>


using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"Программа работает только с английскими буквами!!!"<<endl<<endl;
    cout<<"Введите предложение: ";

    char s[10000];

    gets(s);

    int k=0;

    for (int i=0;i<strlen(s);i++)
    {
        if (s[i]=='x') k++;
    }

    if (k>0) cout<<"В вашем предложении: "<<k<<" букв \"х\""<<endl;
    else cout<<"Букв \"х\" в вашем предложении нет."<<endl;
}
