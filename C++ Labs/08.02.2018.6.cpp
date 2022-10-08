//Чтение бинарного файла

#include <iostream>
#include <stdio.h>

using namespace std;

main()
{

    FILE *f;

    f=fopen("test3.txt","r");

    int x;

    while (!feof(f))
    {
        fread(&x,sizeof(int),1,f);
        cout<<x<<" ";
    }

    fclose(f);
    cout<<"File sozdan!!!";
}


