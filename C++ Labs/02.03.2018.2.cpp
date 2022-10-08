//Выводим на экран людей, чьё имя совпадает с введённым

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    ifstream f("file4.txt");

    struct elev
    {
        int number;
        char name[20];
        char surname[30];
        int year;
        int cash;
        char gender;
    } x[30];

    int i=0;

    cout<<"Введите имя человека: ";
    char str[50];
    gets(str);
    cout<<"\n\n";

    while (!f.eof())
    {
        f>>x[i].number;
        f>>x[i].name;
        f>>x[i].surname;
        f>>x[i].year;
        f>>x[i].cash;
        f>>x[i].gender;

        if (!f.eof())
        {
         if (strcmp(x[i].name,str)==0)
                cout<<x[i].number<<" "<<x[i].name<<" "<<x[i].surname<<" "<<x[i].year<<" "<<x[i].cash<<" "<<x[i].gender<<endl;

        }
    }

        f.close();
}
