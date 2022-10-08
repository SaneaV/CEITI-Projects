/* Используя функцию, создать меню
<<"0-Выйти"<<;
<<"1-Показать"<<;
<<"2-Добавить"<<;
<<"3-Удалить"<<;
<<"4-Минимальная зарплата"<<;
<<"5-Максимальная зарплата"<<;
<<"6-Зарплата работников"<<;
<<"7-Сумма зарплаты"<<;
<<"8-Количество дней меньше или равно 10"<<;
*/

#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

struct Worker
{
    char Name[200];
    int Days;
    float Tarif;

} t[50];

int n;

void ReadInfo()
{
    int i=0;

    ifstream f("Worker.txt");

    while(!f.eof())
    {
        f>>t[i].Name>>t[i].Days>>t[i].Tarif;
        if (!f.eof())
            i++;

    }
    n=i;
    f.close();
}
void ShowInfo()
{

    for(int i=0; i<n; i++)
        cout<<t[i].Name<<"\t"<<t[i].Days<<"\t"<<t[i].Tarif<<endl;
}
void rewrite()
{
    ofstream f("Worker.txt");
    for(int i=0; i<n; i++)
        f<<t[i].Name<<" "<<t[i].Days<<" "<<t[i].Tarif<<endl;
    f.close();
}
void AddInfo()
{
    Worker x;
    int poz;
    cout<<"Ввод информации о новом работнике:"<<endl;
    cout<<"Имя: ";
    cin>>x.Name;
    cout<<"Количество дней: ";
    cin>>x.Days;
    cout<<"Тариф: ";
    cin>>x.Tarif;
    cout<<"Введите позицию: ";
    cin>>poz;
    poz--;

    if(poz>=0 and poz<=n)
    {
        n++;
        for(int i=n-1; i>=poz; i--)
            t[i]=t[i-1];
        t[poz]=x;

        rewrite();
    }
    else
        cout<<"Здесь находятся " <<n<<" работников"<<endl;
}
void DelInfo()
{
    Worker x;
    int poz;

    cout<<"Введите позицию для удаления: ";
    cin>>poz;
    poz--;
    if(poz>-1 and poz<=n)
    {
        n--;
        for(int i=poz; i<n; i++)
            t[i]=t[i+1];

        rewrite();
    }
    else
        cout<<"Здесь находятся " <<n<<" работников"<<endl;
}
void MinTarif()
{
    int poz=0;
    int min=t[0].Tarif;

    for(int i=1; i<n; i++)
    {
        if(min>t[i].Tarif)
        {
            poz=i;
            min=t[i].Tarif;
        }

    }
    cout<<"Минимальный тариф: "<<endl;
    cout<<t[poz].Name<<"\t"<<t[poz].Days<<"\t"<<t[poz].Tarif<<endl;
}
void MaxTarif()
{
    int poz=0;

    for(int i=1; i<n; i++)
    {
        if(t[i].Tarif>t[i+1].Tarif)
            poz=i;
    }
    cout<<"Максимальная зарплата: "<<endl;
    cout<<t[poz].Name<<"\t"<<t[poz].Days<<"\t"<<t[poz].Tarif<<endl;
}
void AllSallary()
{
    for (int i=0; i<n; i++)
        cout<<t[i].Name<<"\t"<<t[i].Tarif<<endl;
}


void SumTarif()
{
    float ST=0;

    for(int i=0; i<n; i++)
    {
        ST+=t[i].Tarif;
    }
    cout<<"Общая зарплата: "<<ST<<endl;
}
void ShowDays()
{
    cout<<"Работники, чьё количество отработанных дней меньше или равно 10: "<<endl;
    for(int i=0; i<n; i++)
    {
        if (t[i].Days<=10)
            cout<<t[i].Name<<"\t"<<t[i].Days<<"\t"<<t[i].Tarif<<endl;
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");
    int ch;
    do
    {
        cout<<"0-Выйти"<<endl;
        cout<<"1-Показать"<<endl;
        cout<<"2-Добавить"<<endl;
        cout<<"3-Удалить"<<endl;
        cout<<"4-Минимальная зарплата"<<endl;
        cout<<"5-Максимальная зарплата"<<endl;
        cout<<"6-Зарплата работников"<<endl;
        cout<<"7-Сумма зарплаты"<<endl;
        cout<<"8-Количество дней меньше или равно 10"<<endl;
        cout<<"Ваш выбор: "<<endl;
        cin>>ch;

        switch(ch)
        {
        case 1:
        {
            system("cls");
            ReadInfo();
            ShowInfo();
            break;
        }
        case 2:
        {
            system("cls");
            ReadInfo();
            AddInfo();
            break;
        }
        case 3:
        {
            system("cls");
            ReadInfo();
            DelInfo();
            break;
        }
        case 4:
        {
            system("cls");
            ReadInfo();
            MinTarif();
            break;
        }
        case 5:
        {
            system("cls");
            ReadInfo();
            MaxTarif();
            break;
        }
        case 6:
        {
            system("cls");
            ReadInfo();
            AllSallary();
            break;

        }
        case 7:
        {
            system("cls");
            ReadInfo();
            SumTarif();
            break;
        }
        case 8:
        {
            system("cls");
            ReadInfo();
            ShowDays();
            break;
        }
        case 0:
        {
            return 0;
        }

        }
    }
    while(ch!=9);

    return 1;
}
