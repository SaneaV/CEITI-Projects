//Для заданного перечня продовольственных продуктов известно:
//-общее количество продуктов;
//-название каждого продукта;
//-дата производства каждого продукта;
//-дата истечения срока годности каждого продукта;
//-исходная цена каждого продукта;
//-текущая цена каждого продукта.
//Напишите программу, которая:
//• Выводит на экран информацию о продукте, название которого введено с клавиатуры.
//• Зная текущую дату, выводит на экран список продуктов с истекшим сроком годности.

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cstring>

using namespace std;

struct Products
{
    char Name[20];

    int DayP;
    int MonthP;
    int YearP;

    int DayD;
    int MonthD;
    int YearD;

    int FirstPrice;
    int SecondPrice;
} P[50];

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;
    cout<<"Введите количество продуктов: ";
    cin>>n;

    char l;


    for(int i=0; i<n; i++)
    {
        cin.ignore();
        system("cls");
        cout<<"Введите название продукта: ";
        gets(P[i].Name);

        do
        {
            cout<<"Введите день, месяц и год производства(дд.мм.гггг): ";
            cin>>P[i].DayP>>l>>P[i].MonthP>>l>>P[i].YearP;
        }
        while(P[i].DayP>31 or P[i].MonthP>12);

        do
        {
            cout<<"Введите день, месяц и год окончания срока(дд.мм.гггг): ";
            cin>>P[i].DayD>>l>>P[i].MonthD>>l>>P[i].YearD;
        }
        while(P[i].DayD>31 or P[i].MonthD>12);

        cout<<"Введите начальную цену: ";
        cin>>P[i].FirstPrice;

        cout<<"Ввелите конечную цену: ";
        cin>>P[i].SecondPrice;
    }

    system("cls");

    int Select;
    int SelectRepeat;
    bool Repeat;


    do
    {
        cout<<"1. Узнать информацию о продукте по его названию."<<endl;
        cout<<"2. Узнать о продуктах с истёкшей датой."<<endl;
        do{
        cin>>Select;
        }while(Select>2 or Select<1);
        system("cls");

        switch(Select)
        {
        case 1:
        {
            cout<<"Введите название продукта: ";
            char NameProduct[20];
            cin.ignore();
            gets (NameProduct);

            for(int i=0; i<n; i++)
            {
                if (strcmp(NameProduct,P[i].Name)==0)
                {
                    cout<<endl<<endl;
                    cout<<"Название продукта: "<<P[i].Name<<endl;
                    cout<<"Дата изготовления: "<<P[i].DayP<<"."<<P[i].MonthP<<"."<<P[i].YearP<<endl;
                    cout<<"Дата окончания срока: "<<P[i].DayD<<"."<<P[i].MonthD<<"."<<P[i].YearD<<endl;
                    cout<<"Цена поставщика: "<<P[i].FirstPrice<<endl;
                    cout<<"Цена в магазине: "<<P[i].SecondPrice<<endl;
                }
            }
            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>SelectRepeat;
            }
            while(SelectRepeat>2 or SelectRepeat<1);

            if(SelectRepeat==2)
                Repeat=false;
            if (SelectRepeat==1)
                system("cls");
            break;
        }
        case 2:
        {
            int TDay,TMonth,TYear;

            do
            {
                cout<<endl<<"Введите сегодняшнюю дату(дд.мм.гггг): ";
                cin>>TDay>>l>>TMonth>>l>>TYear;
            }
            while(TDay>31 or TMonth>12);

            for(int i=0;i<n;i++)
            {
                if(P[i].YearD<TYear)
                {
                    cout<<P[i].Name<<" с истёкщим сроком годности."<<endl;
                }
                if(P[i].MonthD==TMonth)
                {
                    if(P[i].DayD<TDay)
                        cout<<P[i].Name<<" с истёкщим сроком годности."<<endl;
                }

            }
            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>SelectRepeat;
            }
            while(SelectRepeat>2 or SelectRepeat<1);

            if(SelectRepeat==2)
                Repeat=false;
            if (SelectRepeat==1)
                system("cls");
            break;

            }
        }

    }
    while(Repeat);
}
