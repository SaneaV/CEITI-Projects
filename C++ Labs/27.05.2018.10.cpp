//Работа с файлами на C. Запись и чтение структуры из файла. В обычном виде.

#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    struct student
    {
        char name[20];
        char surname[20];
    } Stud[20];

    FILE *f;
    f=fopen("Student.txt","w");

    cout<<"Количество учеников: ";
    int n;
    cin>>n;

    Sleep(200);
    system("cls");

    for (int i=0;i<n;i++)
    {
        cin.ignore();
        cout<<"Имя ученика: ";
        gets(Stud[i].name);
        cout<<"Фамилия ученика: ";
        gets(Stud[i].surname);


        fputs(Stud[i].name,f);
        fputs(" ",f);
        fputs(Stud[i].surname,f);
        fputs("\n",f);

        Sleep(200);
        system("cls");
    }
    fclose(f);

    f=fopen("Student.txt","r");

    int q = 0;
    while (!feof(f))
    {
        fgets(Stud[q].name,255,f);
        fgets(Stud[q].surname,255,f);

        if (!feof(f))
        {
            cout<<Stud[q].name<<"\t"<<Stud[q].surname<<endl;
        }
    }
    n=q;
    fclose(f);
}
