//Прочитать документ со строками

#include <iostream>
#include <stdio.h>

using namespace std;

main()
{

    FILE *f;

    f=fopen("test2.txt","r");

    char str[255];

    while (!feof(f))
    {
        fgets(str,255,f);
        if (!feof(f))
        {
            cout<<str<<endl;
        }
    }

    fclose(f);

}

