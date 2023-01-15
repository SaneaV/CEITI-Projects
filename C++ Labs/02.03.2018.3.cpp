//Вводите номер пользователя. Если такой есть в файле, то заменяется информация о пользователе, иначе информация добавляется в конец файла.

#include <iostream>
#include <fstream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    ifstream f("file4.txt");
    ofstream g("file5.txt");

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

    int n;
    cout<<"Введите номер пользователя: ";
    cin>>n;

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
            if (x[i].number==n)
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
                g<<x[i].number<<" "<<x[i].name<<" "<<x[i].surname<<" "<<x[i].year<<" "<<x[i].cash<<" "<<x[i].gender<<endl;
                cout<<endl;
                k++;
            }

            else
            {
                g<<x[i].number<<" ";
                g<<x[i].name<<" ";
                g<<x[i].surname<<" ";
                g<<x[i].year<<" ";
                g<<x[i].cash<<" ";
                g<<x[i].gender<<endl;
            }
        }

    }

    if (k==0)
    {
        ofstream("file5.txt", ios::app);
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
        g<<x[i].number<<" "<<x[i].name<<" "<<x[i].surname<<" "<<x[i].year<<" "<<x[i].cash<<" "<<x[i].gender<<endl;
        cout<<endl;
    }

    f.close();
    g.close();
}

