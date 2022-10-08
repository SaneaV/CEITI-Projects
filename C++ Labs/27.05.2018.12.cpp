//Работа с файлами на с++. Сортировка пузырьком. Функции.

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <windows.h>

using namespace std;

struct student
{
    char Name[20];
    char Surname[20];
    float Medium;
} Stud[20];

void Sort (int &n)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1-i; j++)
        {
            if (Stud[j].Medium>Stud[j+1].Medium)
            {
                char temp2[20];
                char temp3[20];
                int temp = Stud[j].Medium;

                strcpy (temp2,Stud[j].Name);
                strcpy (temp3,Stud[j].Surname);

                strcpy (Stud[j].Name,Stud[j+1].Name);
                strcpy (Stud[j].Surname,Stud[j+1].Surname);
                Stud[j].Medium = Stud[j+1].Medium;

                strcpy (Stud[j+1].Name, temp2);
                strcpy (Stud[j+1].Surname, temp3);
                Stud[j+1].Medium = temp;
            }
        }
    }
}


int main()
{
    setlocale(LC_ALL,"RUS");

    ifstream g("Student.txt");

    int n=0;

    g>>n;

    for (int i=0; i<n; i++)
    {
        g>>Stud[i].Name>>Stud[i].Surname>>Stud[i].Medium;
        cout<<Stud[i].Name<<" "<<Stud[i].Surname<<" "<<Stud[i].Medium<<endl;

    }

    cout<<endl;

    g.close();

    Sort (n);

    for (int j=0; j<n; j++)
    {
        cout<<Stud[j].Name<<" "<<Stud[j].Surname<<" "<<Stud[j].Medium<<endl;
    }

}

