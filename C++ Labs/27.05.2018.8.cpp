//Структуры. Ввод. Вывод.

#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

struct student
{
    char name[20];
    char surname[20];
    int note;
}Stud[20];

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

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
        cout<<"Оценка ученика: ";
        cin>>Stud[i].note;

        Sleep(200);
        system("cls");
    }

    for (int i=0;i<n;i++)
    {
        cout<<Stud[i].name<<" "<<Stud[i].surname<<" "<<Stud[i].note<<endl;
    }


}
