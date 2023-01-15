//Ввести несколько строк текста

#include <iostream>
#include <stdio.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    FILE *f;

    f=fopen("test2.txt","w");

    int n;

    cout<<"Введите количество строк: ";
    cin>>n;

    char str[256];

    cout<<endl;

    cin.ignore();

    for (int i=0;i<n;i++)
    {
        cout<<"Введите строку: ";
        gets(str);
        cout<<endl;
        fputs(str,f);
        fputs("\n",f);

    }

    fclose(f);
    cout<<"Файл успешно создан!!!";
}

