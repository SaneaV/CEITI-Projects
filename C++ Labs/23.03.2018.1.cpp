//"Используя тип данных запись с именем MARSH, содержащую следующие поля:
//• BEGST – название начального пункта маршрута;
//• TERM – название конечного пункта маршрута;
//• NUMER – номер маршрута.
//Написать программу, выполняющую следующие действия:
//• ввод с клавиатуры данных в массив TRAFIC, состоящий из 8 записей типа MARSH;
//• вывод на экран  информации о маршруте, номер которого введен с клавиатуры; если таких маршрутов нет, вывести соответствующее сообщение.
//вывод на экран  информации о маршрутах, которые начинаются или оканчиваются в пункте, название которого введено с клавиатуры; если таких маршрутов нет, вывести соответствующее сообщение



#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    struct Marsh
    {
        char Begst [80];
        char Term [80];
        int Numer;
    } Trafic[8];


    for(int i=0; i<8; i++)
    {

        cout<<"Название начального пункта маршрута: ";
        cin>>Trafic[i].Begst;
        cout<<"Название конечного пункта маршрута: ";
        cin>>Trafic[i].Term;
        cout<<"Номер маршрута: ";
        cin>>Trafic[i].Numer;
        cout<<endl;
    }

    bool c=true;

    //Поиск по номеру маршрута
    do
    {
        cout<<"\n\nНапишите номер маршрута: ";
        int Number;
        bool y=true;
        cin>>Number;

        for (int i=0; i<8; i++)
        {
            if (Trafic[i].Numer==Number)//проверка на совпадение
            {
                y=false;
                cout<<"Название начального пункта маршрута: "<<Trafic[i].Begst<<endl;
                cout<<"Название конечного пункта маршрута: "<<Trafic[i].Term<<endl;
                cout<<"Номер маршрута: "<<Trafic[i].Numer<<endl;
            }
        }
        if (y)
            cout<<"Такого маршрута нет";


        cout<<endl<<endl<<"Вы хотите повторить?";
        cout<<endl<<"1. Да."<<endl;
        cout<<"2. Нет."<<endl;
        cout<<"Ответ = ";
        int Select;
        cin>>Select;
        if (Select==1)
            c=true;
        else if (Select==2)
            c=false;
    }
    while (c);

    //Проверка на совпадение маршрутов
    do
    {
        cout<<"\n\nНапишите точка отбытия или прибытия маршрута: ";
        char Name[30];
        bool y=true;
        cin>>Name;

        for (int i=0; i<8; i++)
        {
            if (strcmp(Trafic[i].Begst,Name)==0 or strcmp(Trafic[i].Term,Name)==0)//проверка на совпадение
            {
                y=false;
                cout<<"Название начального пункта маршрута: "<<Trafic[i].Begst<<endl;
                cout<<"Название конечного пункта маршрута: "<<Trafic[i].Term<<endl;
                cout<<"Номер маршрута: "<<Trafic[i].Numer<<endl;
            }
        }
        if (y)
            cout<<"Такого маршрута нет";

        cout<<endl<<endl<<"Вы хотите повторить?";
        cout<<endl<<"1. Да."<<endl;
        cout<<"2. Нет."<<endl;
        cout<<"Ответ = ";
        int Select;
        cin>>Select;
        if (Select==1)
            c=true;
        else if (Select==2)
            c=false;
    }
    while (c);
}
