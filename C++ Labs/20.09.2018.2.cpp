/*1. Добавить элемент.
2. Вывести на экран.
3. Удаление элемента.
ОЧЕРЕДЬ*/

#include <iostream>
#include <windows.h>

using namespace std;

struct Queue
{
    int info;
    Queue *next;
}*first,*last;

void AddElement()
{
    Queue *cr=new Queue;
    cout<<"Введите элемент: ";
    cin>>cr->info;
    cr->next=NULL;
    if(first==NULL)
    {
        first=cr;
        last=cr;
    }
    else
    {
        last->next=cr;
        last=cr;
    }

}

void DelElement()
{
    if(first==NULL)
        cout<<"Пусто"<<endl;
    else
    {
        Queue *cr=first;
        first=first->next;
        delete cr;
    }

}

void Show()
{
    if(first==NULL)
        cout<<"Пусто"<<endl;
    else
    {
        Queue *cr=first;
        while(cr!=NULL)
        {
            cout<<cr->info<<" ";
            cr=cr->next;
        }
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");

    int Selection;
    bool Main = true;
    int SecondSelection;

    do
    {
        cout<<"1. Добавить элемент."<<endl;
        cout<<"2. Вывести на экран."<<endl;
        cout<<"3. Удаление элемента."<<endl;
        cout<<"0. Выйти из программы."<<endl;
        cout<<"Ваш выбор: ";
        do
        {
            cin>>Selection;
        }
        while(Selection>3 or Selection<0);
        system("cls");

        switch(Selection)
        {
        case 1:
        {
            bool RepeatMenu = false;

            do
            {
                AddElement();
                cout<<endl<<endl;
                cout<<"1. Вернуться в меню."<<endl;
                cout<<"2. Повторить ввод элемента."<<endl;
                cout<<"0. Выйти из программы."<<endl;
                cout<<"Ваш выбор: ";
                do
                {
                    cin>>SecondSelection;
                }
                while(SecondSelection>2 or SecondSelection<0);
                if(SecondSelection==1)
                {
                    system("cls");
                    RepeatMenu = true;
                }
                else if(SecondSelection==2)
                {
                    system("cls");
                }
                else
                {
                    Main = false;
                    RepeatMenu = true;
                }
            }
            while(!RepeatMenu);
            break;
        }

        case 2:
        {
            Show();
            cout<<endl<<endl;
            cout<<"1. Вернуться в меню."<<endl;
            cout<<"0. Выйти из программы."<<endl;
            cout<<"Ваш выбор: ";
            do
            {
                cin>>SecondSelection;
            }
            while(SecondSelection>1 or SecondSelection<0);
            if(SecondSelection==1)
                system("cls");
            else
                Main = false;
            break;


        }

        case 3:
        {
            bool RepeatMenu = false;

            do
            {
                cout<<"Первоначальный вид: "<<endl;
                Show();
                DelElement();
                cout<<endl<<endl;
                cout<<"Конечный вид: "<<endl;
                Show();
                cout<<endl<<"1. Вернуться в меню."<<endl;
                cout<<"2. Удалить ещё один элемент."<<endl;
                cout<<"0. Выйти из программы."<<endl;
                cout<<"Ваш выбор: ";
                do
                {
                    cin>>SecondSelection;
                }
                while(SecondSelection>2 or SecondSelection<0);
                if(SecondSelection==1)
                {
                    system("cls");
                    RepeatMenu = true;
                }
                else if(SecondSelection==2)
                {
                    system("cls");
                }
                else
                {
                    Main = false;
                    RepeatMenu = true;
                }
            }
            while(!RepeatMenu);
            break;
        }
        case 0:
            {
                Main = false;
                break;
            }
        }

    }
    while(Main);

    system("cls");
}

