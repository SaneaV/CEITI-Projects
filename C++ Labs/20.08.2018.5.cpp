/*Используя тип данных запись с именем MARSH, содержащую следующие поля:
• BEGST – название начального пункта маршрута;
• TERM – название конечного пункта маршрута;
• NUMER – номер маршрута.
Написать программу, выполняющую следующие действия:
• ввод с клавиатуры данных в массив TRAFIC, состоящий из 8 записей типа MARSH;
• вывод на экран  информации о маршруте, номер которого введен с клавиатуры;
если таких маршрутов нет, вывести соответствующее сообщение.
•вывод на экран  информации о маршрутах, которые начинаются или оканчиваются в пункте, название которого введено с клавиатуры;
если таких маршрутов нет, вывести соответствующее сообщение
*/

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    struct MARSH
    {
        char BEGST[20];
        char TERM[20];
        int NUM;
    } TRAFIC[8];

    for(int i=0; i<8; i++)
    {
        cout<<"Введите название начала маршрута: ";
        cin>>TRAFIC[i].BEGST;

        cout<<"Введите название конца маршрута: ";
        cin>>TRAFIC[i].TERM;

        cout<<"Введите номер маршрута: ";
        cin>>TRAFIC[i].NUM;

        system("cls");
    }

    int Selection;
    int Reselection;
    bool FinishProgram = false;

    while(!FinishProgram)
    {
        cout<<"1. Узнать о маршруте по его номеру."<<endl;
        cout<<"2. Узнать о маршруте который пересекает точку..."<<endl;
        cout<<"Ваш выбор: ";
        do
        {
            cin>>Selection;
        }
        while(Selection>2 or Selection<1);

        system("cls");

        switch(Selection)
        {
        case 1:
        {
            int NUM;
            int k=0;
            cout<<"Введите номер маршрута: ";
            cin>>NUM;

            for(int i=0; i<8; i++)
                if(NUM==TRAFIC[i].NUM)
                {
                    cout<<"Маршрут №"<<TRAFIC[i].NUM<<" "<<TRAFIC[i].BEGST<<" - "<<TRAFIC[i].TERM<<endl;
                    k++;
                }

            if(k==0)
                cout<<"К сожалению, такого маршрута нет"<<endl;

            cout<<endl<<endl;
            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>Reselection;
            }
            while(Reselection>2 or Reselection<1);

            if (Reselection==1)
                system("cls");
            if(Reselection==2)
                FinishProgram=true;
            break;
        }
        case 2:
        {
            char Punct[20];
            int k=0;

            cout<<"Введите название пункта: ";
            cin>>Punct;

            for(int i=0; i<8; i++)
            {
                if(strcmp(TRAFIC[i].BEGST,Punct)==0)
                {
                    cout<<"Маршрут №"<<TRAFIC[i].NUM<<
                        " начинается в "<<Punct<<" и заканчивается в "<<TRAFIC[i].TERM<<endl;
                    k++;
                }
                if(strcmp(TRAFIC[i].TERM,Punct)==0)
                {
                    cout<<"Маршрут №"<<TRAFIC[i].NUM<<" заканчивается в "<<Punct<<
                        " и начинается в "<<TRAFIC[i].BEGST<<endl;
                    k++;
                }

            }
            if(k==0)
                cout<<"К сожалению, через данный пункт ни один маршрут не проходит"<<endl;

            cout<<endl<<endl;
            cout<<"1.Вернуться в меню."<<endl;
            cout<<"2.Выйти из программы."<<endl;
            do
            {
                cin>>Reselection;
            }
            while(Reselection>2 or Reselection<1);

            if (Reselection==1)
                system("cls");
            if(Reselection==2)
                FinishProgram=true;
            break;
        }
        }

    }
}
