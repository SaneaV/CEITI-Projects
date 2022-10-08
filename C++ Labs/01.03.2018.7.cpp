//—оздаЄм файл с информацией о люд€х (номер, им€, фамили€, год, зарплата, пол)

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

    cout<<"¬видете количество сотрудников: ";
    int n;
    cin>>n;

    for (int i=0;i<n;i++)
    {
        cout<<"¬ведите номер: ";
        cin>>x[i].number;
        cout<<"¬ведите им€: ";
        cin>>x[i].name;
        cout<<"¬ведите фамилию: ";
        cin>>x[i].surname;
        cout<<"¬ведите год рождени€: ";
        cin>>x[i].year;
        cout<<"¬ведите зарплату: ";
        cin>>x[i].cash;
        cout<<"¬ведите пол: ";
        cin>>x[i].gender;
        f<<x[i].number<<" "<<x[i].name<<" "<<x[i].surname<<" "<<x[i].year<<" "<<x[i].cash<<" "<<x[i].gender<<endl;
        cout<<endl;
    }

    f.close();
}
