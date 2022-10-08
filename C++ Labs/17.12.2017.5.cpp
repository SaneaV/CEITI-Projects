//Подсчитать кол-во вхождений последовательности "сert"

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");
    char s1[1000];
    char s2[20]=" !?-.,";
    char s3[20]="cert";

    int k=0;

    cout <<"Введите предложение: ";

    gets(s1);

    char *pch=strtok(s1,s2);

    while (pch!=NULL)
    {
        if (strcmp(pch,s3)==0) k++ ;
        pch=strtok(NULL,s2);
    }

    cout << "Количество вхождений: " << k;
}
