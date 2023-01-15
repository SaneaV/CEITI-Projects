//Создаём файл с информацией о людях (номер, имя, фамилия, год, зарплата, пол)

#include <iostream>
#include <fstream>

using namespace std;

main()
{
    setlocale (LC_ALL,"rus");
    ofstream f("file4.txt");
    struct elev
    {
        int number;
        char name[20];
        char surname[30];
        int year;
        int cash;
        char gender; //f или m
    }x[30];

    cout<<"Ввидете количество сотрудников: ";
    int n;
    cin>>n;

    for (int i=0;i<n;i++)
    {
        cout<<"Введите номер: ";
        cin>>x[i].number;
        cout<<"Введите имя: ";
        cin>>x[i].name;
        cout<<"Введите фамилию: ";
        cin>>x[i].surname;
        cout<<"Введите год рождения: ";
        cin>>x[i].year;
        cout<<"Введите зарплату: ";
        cin>>x[i].cash;
        cout<<"Введите пол: ";
        cin>>x[i].gender;
        f<<x[i].number<<" "<<x[i].name<<" "<<x[i].surname<<" "<<x[i].year<<" "<<x[i].cash<<" "<<x[i].gender<<endl;
        cout<<endl;
    }

    f.close();
}
