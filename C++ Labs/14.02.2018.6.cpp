//Чтение бинарного файла со структурами

#include <iostream>
#include <stdio.h>

using namespace std;

main()
{
    FILE *f;
    f=fopen("test3.txt","r");

    int i=0,n;
    cout<<"fail: "<<endl;


        struct student
    {
        char name[30];
        int year;
        float mark;
    }x[30];

    while (!feof(f))
    {
        fread(&x[i],sizeof(student),1,f);

        if (!feof(f))
        {
            cout<<x[i].name<<"\t"<<x[i].year<<"\t"<<x[i].mark<<endl;
        }
    }
    n=i;

    fclose(f);
    cout<<"Fail sozdan";
}
