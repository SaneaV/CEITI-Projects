//Используя тип данных запись, опишите телефонный справочник, который содержит:
//-количество абонентов;
//-фамилию и имя каждого абонента;
//-номер телефона каждого абонента;
//-адрес (улица, номер дома) каждого абонента.
//Напишите программу, которая:
//• Выводит на экран список абонентов, у которых номер телефона начинается на 47;
//• Выводит на экран информацию об абонентах, проживающих на заданной улице.

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;
    cout<<"Введите количество людей: ";
    cin>>n;

    system("cls");

    struct SPRAVOCHNIK
    {
        char Name[20];
        char Surname[20];
        char Number[10];
        char Adres[20];
        int NAdres;
    } Tel[n];


    for(int i=0; i<n; i++)
    {
        cout<<"Введите имя человека: ";
        cin>>Tel[i].Name;

        cout<<"Введите фамилию человека: ";
        cin>>Tel[i].Surname;

        do{
        cout<<"Введите номер человека(6 символов): ";
            cin>>Tel[i].Number;
        }
        while(strlen(Tel[i].Number)>6 or strlen(Tel[i].Number)<6);

        cout<<"Введите улицу: ";
        cin>>Tel[i].Adres;

        cout<<"Введите номер дома: ";
        cin>>Tel[i].NAdres;

        system("cls");
    }

    int Select;
    int RepeatSelect;
    bool Menu = true;

    while(Menu)
    {
        cout<<"1.Узнать номера абонентов, чей номер начинается на 47."<<endl;
        cout<<"2.Узнать о людях, живущих на улице..."<<endl;
        cout<<"Ваш выбор: ";
        do
        {
            cin>>Select;
        }
        while(Select<1 or Select>2);
        system("cls");

        switch(Select)
        {
        case 1:
        {
            int k = 0;
            for(int i=0; i<n; i++)
            {
                if(Tel[i].Number[0]=='4' and Tel[i].Number[1]=='7')
                {
                    cout<<Tel[i].Name<<" "<<Tel[i].Surname<<" проживает по адресу: "<<Tel[i].Adres<<" "<<Tel[i].NAdres<<" номер телефона: "<<Tel[i].Number;
                    k++;
                }

            }


            if (k==0)
                cout<<"К сожалению, таких номеров нет."<<endl;

            cout<<endl<<endl;
            cout<<"1. Вернуться в меню."<<endl;
            cout<<"2. Выйти из программы."<<endl;
            do
            {
                cin>>RepeatSelect;

            }
            while(RepeatSelect<1 or RepeatSelect>2);

            if (RepeatSelect==1)
                system("cls");
            if (RepeatSelect==2)
            {
                system("cls");
                Menu = false;
            }

            break;
        }
        case 2:
        {
            int k = 0;
            char NazvUlici[20];

            cout<<"Введите название улицы: ";
            cin>>NazvUlici;

            cout<<"На данной улице проживает: "<<endl;
            for(int i=0;i<n;i++)
            {
                if(strcmp(NazvUlici,Tel[i].Adres)==0)
                {
                    cout<<Tel[i].Name<<" "<<Tel[i].Surname<<" номер телефона: "<<Tel[i].Number<<" номер дома: "<<Tel[i].NAdres<<endl;
                    k++;
                }
            }


            if (k==0)
                cout<<"Никто"<<endl;

            cout<<endl<<endl;
            cout<<"1. Вернуться в меню."<<endl;
            cout<<"2. Выйти из программы."<<endl;
            do
            {
                cin>>RepeatSelect;

            }
            while(RepeatSelect<1 or RepeatSelect>2);

            if (RepeatSelect==1)
                system("cls");
            if (RepeatSelect==2)
            {
                system("cls");
                Menu = false;
            }

            break;
        }

        }

    }

}
