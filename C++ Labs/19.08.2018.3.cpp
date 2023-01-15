//Используя тип данных запись с именем PRICE, содержащую следующие поля:
//• TOVAR – название товара;
//• KOL – количество товара;
//• TSENA –цена товара;
//• STOIM – стоимость товара.
//Написать программу, выполняющую следующие действия:
//• ввод с клавиатуры данных в массив SPISOK, состоящий из 8 записей типа PRICE;
//• вывод на экран  информации о товаре, название которого введено с клавиатуры; если таких товаров нет, вывести соответствующее сообщение.
//• Вывод на экран информации об общей стоимости товара в магазине;
//• Вывод на экран информации о самом дорогом товаре в магазине.


#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    struct PRICE
    {
        char TOVAR[30];
        int KOL;
        int TSENA;
        int STOIM;
    } SPISOK[10];



    for(int i=0; i<8 ; i++)
    {
        cout<<"Введите название товара: ";
        cin>>SPISOK[i].TOVAR;

        cout<<"Введите количество товара: ";
        cin>>SPISOK[i].KOL;

        cout<<"Введите цену товара: ";
        cin>>SPISOK[i].TSENA;

        cout<<"Введите стоимость товара: ";
        cin>>SPISOK[i].STOIM;


        system("cls");
    }

    int Select;
    int RepeatSelect;
    bool Menu = true;

    while(Menu)
    {
        cout<<"1.Узнать, информацию о товаре."<<endl;
        cout<<"2.Узнать общую стоимость товаров в магазине."<<endl;
        cout<<"3.Информация о самом дорогом товаре."<<endl;
        cout<<"Ваш выбор: ";
        do
        {
            cin>>Select;
        }
        while(Select<1 or Select>3);
        system("cls");

        switch(Select)
        {
        case 1:
        {
            char Tovar[30];
            int k = 0;

            cout<<"Введите название товара: ";
            cin>>Tovar;

            for(int i=0; i<8; i++)
            {
                if(strcmp(Tovar,SPISOK[i].TOVAR)==0)
                {
                    cout<<"В нашем магазине есть "<<Tovar<<" начальная цена - "<<SPISOK[i].TSENA<<" стоимость товара - "<<SPISOK[i].STOIM<<" в количестве: "<<SPISOK[i].KOL<<endl;
                    k++;
                }
            }
            if (k==0)
                cout<<"К сожалению, в нашем магазине нет такого товара."<<endl;

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
            int Sum = 0;

            for(int i=0; i<8; i++)
            {
                Sum += SPISOK[i].STOIM;
            }

            cout<<"Общая стоимость всех товаров в магазине: "<<Sum<<endl;


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

        case 3:
        {
            int max = 0;
            int pmax = 0;

            for(int i=0; i<8; i++)
            {
                if(max<SPISOK[i].STOIM)
                {
                    pmax = i;
                    max=SPISOK[i].STOIM;
                }
            }

            cout<<"Самый дорогой товар: "<<endl;
            cout<<SPISOK[pmax].TOVAR<<" начальная цена - "<<SPISOK[pmax].TSENA<<" стоимость товара - "<<SPISOK[pmax].STOIM<<" в количестве: "<<SPISOK[pmax].KOL<<endl;


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
