//Создание бинарного файла со структурами

#include <iostream>
#include <stdio.h>

using namespace std;

main()
{
    FILE *f;
    f=fopen("test4.txt","w");

    int n,i;

    struct student
    {
        char name[30];
        int year;
        float mark;
    }x;

    cout<<"Vvedite kolichesvo uchenikov: ";
    cin>>n;


    for (int i=0;i<n;i++)
    {
        cin>>x.name>>x.year>>x.mark;
        fwrite(&x,sizeof(x),1,f);
    }

    fclose(f);
    cout<<"Fail sozdan";
}

