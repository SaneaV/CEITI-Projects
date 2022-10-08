//»спользу€ тип данных запись с именем PRICE, содержащую следующие пол€:
//Х TOVAR Ц название товара;
//Х KOL Ц количество товара;
//Х TSENA Ццена товара;
//Х STOIM Ц стоимость товара.
//Ќаписать программу, выполн€ющую следующие действи€:
//Х ввод с клавиатуры данных в массив SPISOK, состо€щий из 8 записей типа PRICE;
//Х вывод на экран †информации о товаре, название которого введено с клавиатуры; если таких товаров нет, вывести соответствующее сообщение.
//Х вывод на экран информации о товаре, чье количество наибольшее в магазине;
//Х вывод на экран информации о самом дешевом товаре в магазине.

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstring>
#include <limits.h>

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
        cout<<"¬ведите название товара: ";
        cin>>SPISOK[i].TOVAR;

        cout<<"¬ведите количество товара: ";
        cin>>SPISOK[i].KOL;

        cout<<"¬ведите цену товара: ";
        cin>>SPISOK[i].TSENA;

        cout<<"¬ведите стоимость товара: ";
        cin>>SPISOK[i].STOIM;


        system("cls");
    }

    int Select;
    int RepeatSelect;
    bool Menu = true;

    while(Menu)
    {
        cout<<"1.”знать, информацию о товаре."<<endl;
        cout<<"2.»нформаци€ о товаре с самым большим количеством."<<endl;
        cout<<"3.»нформаци€ о самом дешЄвом товаре."<<endl;
        cout<<"¬аш выбор: ";
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

            cout<<"¬ведите название товара: ";
            cin>>Tovar;

            for(int i=0; i<8; i++)
            {
                if(strcmp(Tovar,SPISOK[i].TOVAR)==0)
                {
                    cout<<"¬ нашем магазине есть "<<Tovar<<" начальна€ цена - "<<SPISOK[i].TSENA<<" стоимость товара - "<<SPISOK[i].STOIM<<" в количестве: "<<SPISOK[i].KOL<<endl;
                    k++;
                }
            }
            if (k==0)
                cout<<"  сожалению, в нашем магазине нет такого товара."<<endl;

            cout<<endl<<endl;
            cout<<"1. ¬ернутьс€ в меню."<<endl;
            cout<<"2. ¬ыйти из программы."<<endl;
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
            int pmax;
            int max = 0;

            for(int i=0; i<8; i++)
            {
                if(SPISOK[i].KOL>max)
                {
                    max = SPISOK[i].KOL;
                    pmax = i;
                }
            }

            cout<<"»нформаци€ о товаре, с самым большим количеством: "<<endl;
            cout<<SPISOK[pmax].TOVAR<<" начальна€ цена - "<<SPISOK[pmax].TSENA<<" стоимость товара - "<<SPISOK[pmax].STOIM<<" в количестве: "<<SPISOK[pmax].KOL<<endl;


            cout<<endl<<endl;
            cout<<"1. ¬ернутьс€ в меню."<<endl;
            cout<<"2. ¬ыйти из программы."<<endl;
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
            int min = INT_MAX;
            int pmin = 0;

            for(int i=0; i<8; i++)
            {
                if(min>SPISOK[i].STOIM)
                {
                    pmin = i;
                    min=SPISOK[i].STOIM;
                }
            }

            cout<<"—амый дешЄвый товар: "<<endl;
            cout<<SPISOK[pmin].TOVAR<<" начальна€ цена - "<<SPISOK[pmin].TSENA<<" стоимость товара - "<<SPISOK[pmin].STOIM<<" в количестве: "<<SPISOK[pmin].KOL<<endl;


            cout<<endl<<endl;
            cout<<"1. ¬ернутьс€ в меню."<<endl;
            cout<<"2. ¬ыйти из программы."<<endl;
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
