//Выводим на экран представительниц женского пола и среднюю зарплату людей в списке.

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
    float Sum=0;
    int k=0;

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
            if (x[i].gender=='f')
            {
                cout<<"Пользователи женского пола: "<<x[i].name<<" "<<x[i].surname<<endl;
            }
            k++;
            Sum+=x[i].cash;

        }
    }
    cout<<"Средняя зарплата пользователей: "<<Sum/k<<endl;


    f.close();
}
