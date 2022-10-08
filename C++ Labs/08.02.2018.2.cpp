//Прочитать текст из документа

#include <iostream>
#include <stdio.h>

using namespace std;

main()
{

    FILE *f;

    f=fopen("test1.txt","r");

    char ch;

    cout<<"Файл содержит: ";

    cout<<endl<<endl;


    while (!feof(f))
    {
       ch=fgetc(f);
       cout<<ch;
    }

    fclose(f);

}

