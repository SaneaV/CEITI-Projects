//¬водите номер пользовател€. ≈сли такой есть в файле, то замен€етс€ информаци€ о пользователе, иначе информаци€ добавл€етс€ в конец файла.

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
    cout<<"¬ведите номер пользовател€: ";
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
        g<<x[i].number<<" "<<x[i].name<<" "<<x[i].surname<<" "<<x[i].year<<" "<<x[i].cash<<" "<<x[i].gender<<endl;
        cout<<endl;
    }

    f.close();
    g.close();
}

