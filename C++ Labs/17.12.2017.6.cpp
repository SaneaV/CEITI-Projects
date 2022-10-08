//Подсчитать кол-во вхождений последовательности "сert"

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");
    char s[1000];

    int k=0;

    cout <<"Введите предложение: ";

    gets(s);

    for (int i=0;i<strlen(s);i++)
    {
        if (s[i]=='c' and s[i+1]=='e' and s[i+2]=='r' and s[i+3]=='t')
            k++;
    }


    cout << "Количество вхождений: " << k;
}
