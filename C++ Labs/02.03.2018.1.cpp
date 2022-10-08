//Выводим на экран людей, чья зарплата меньше средней

#include <iostream>
#include <fstream>

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

    cout<<"Введите среднюю зарплату: ";
    int sred;
    cin>>sred;
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
         if (x[i].cash<sred)
                cout<<"Зарплата "<<x[i].name<<" "<<x[i].surname<<" меньше средней"<<endl;

        }
    }

        f.close();
}
