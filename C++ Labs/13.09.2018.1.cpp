/*1. Показать начальный список.
2. Проверить на возрастание списка.
3. Разделить список на отрицательный и положительный.
4. Сумма элементов списка.
5. Максимальный элемент.
6. Минимальный элемент.*/

#include <iostream>
#include <windows.h>

using namespace std;

struct List
{
    int info;
    List *next;
}*bg1, *bg2, *bg3;

List *Create()
{
    List *cr,*prv,*bg;
    int n;
    cout<<"Введите количество чисел: ";
    cin>>n;

    bg = NULL;

    for(int i=0; i<n; i++)
    {
        cr=new List;

        cout<<"Введите число: ";
        cin>>cr->info;
        cr->next=NULL;

        if(bg==NULL)
        {
            bg=cr;
            prv=cr;
        }
        else
        {
            prv->next=cr;
            prv=cr;
        }
    }
    return bg;
}

void Show(List *cr)
{
    if(cr==NULL)
        cout<<"Empty"<<endl;
    else
    {
        while(cr!=NULL)
        {
            cout<<cr->info;
            cr=cr->next;
        }
    }
}

bool Increment(List *bg1)
{
    List *cr, *r;

    cr = bg1;
    // r = cr->next;

    while(cr->next!=NULL)
    {
        r=cr->next;

        if(cr->info>r->info)
            return false;
        cr=cr->next;
    }

    return true;
}

List *Sort(List *bg1)
{
    List *cr, *cr1, *cr2;
    List *prv1, *prv2;
    cr = bg1;

    bg2 = NULL;
    bg3 = NULL;

    while(cr!=NULL)
    {
        if(cr->info>0)
        {
            cr1=new List;
            cr1->info=cr->info;
            cr1->next=NULL;

            if(bg2==NULL)
            {
                bg2=cr1;
                prv1=cr1;
            }
            else
            {
                prv1->next=cr1;
                prv1=cr1;
            }
        }
        else
        {

            cr2=new List;
            cr2->info=cr->info;
            cr2->next=NULL;

            if(bg3==NULL)
            {
                bg3=cr2;
                prv2=cr2;
            }
            else
            {
                prv2->next=cr2;
                prv2=cr2;
            }
        }
        cr=cr->next;
    }

    cout<<"Список положительных элементов: ";
    Show(bg2);
    cout<<endl;
    cout<<"Список отрицательных элементов: ";
    Show(bg3);
    cout<<endl;
}

int Sum(List *bg1)
{
    List *cr;

    cr=bg1;
    int S=0;

    while(cr!=NULL)
    {
        S+=cr->info;
        cr=cr->next;
    }

    return S;
}

int Max(List *bg1)
{
    List *cr;
    cr=bg1;
    int max=bg1->info;

    while(cr!=NULL)
    {
        if(max<cr->info)
            max=cr->info;
        cr=cr->next;
    }

    return max;
}

int Min(List *bg1)
{
    List *cr;
    cr=bg1;
    int min=bg1->info;

    while(cr!=NULL)
    {
        if(min>cr->info)
            min=cr->info;
        cr=cr->next;
    }

    return min;
}


int main()
{
    setlocale(LC_ALL,"RUS");

    bg1=Create();

    system("cls");

    int Selection;
    bool Main=false;
    int SecondMain;

    while(!Main)
    {
        cout<<"Что будем делать?"<<endl;
        cout<<"1. Показать начальный список."<<endl;
        cout<<"2. Проверить на возрастание списка."<<endl;
        cout<<"3. Разделить список на отрицательный и положительный."<<endl;
        cout<<"4. Сумма элементов списка."<<endl;
        cout<<"5. Максимальный элемент."<<endl;
        cout<<"6. Минимальный элемент."<<endl;
        cout<<"Ваш выбор: ";
        do
        {
            cin>>Selection;
        }
        while(Selection>5 or Selection<1);
        system("cls");


        switch(Selection)
        {
        case 1:
        {
            Show(bg1);

            cout<<endl<<endl;
            cout<<"1. Вернуться в меню."<<endl;
            cout<<"2. Выйти из программы."<<endl;
            cout<<"Ваш выбор: ";
            do
            {
                cin>>SecondMain;
            }
            while(SecondMain>2 or SecondMain<1);

            if(SecondMain==1)
                system("cls");
            else
                Main=true;

            break;
        }
        case 2:
        {
            cout<<"Список возрастает: "<<Increment(bg1)<<endl;

            cout<<endl<<endl;
            cout<<"1. Вернуться в меню."<<endl;
            cout<<"2. Выйти из программы."<<endl;
            cout<<"Ваш выбор: ";
            do
            {
                cin>>SecondMain;
            }
            while(SecondMain>2 or SecondMain<1);

            if(SecondMain==1)
                system("cls");
            else
                Main=true;

            break;
        }
        case 3:
        {
            Sort(bg1);

            cout<<endl<<endl;
            cout<<"1. Вернуться в меню."<<endl;
            cout<<"2. Выйти из программы."<<endl;
            cout<<"Ваш выбор: ";
            do
            {
                cin>>SecondMain;
            }
            while(SecondMain>2 or SecondMain<1);

            if(SecondMain==1)
                system("cls");
            else
                Main=true;

            break;
        }
        case 4:
        {
            cout<<"Cумма элементов: "<<Sum(bg1)<<endl;

            cout<<endl<<endl;
            cout<<"1. Вернуться в меню."<<endl;
            cout<<"2. Выйти из программы."<<endl;
            cout<<"Ваш выбор: ";
            do
            {
                cin>>SecondMain;
            }
            while(SecondMain>2 or SecondMain<1);

            if(SecondMain==1)
                system("cls");
            else
                Main=true;

            break;

        }
        case 5:
        {
            cout<<"Макисальный элемент: "<<Max(bg1)<<endl;

            cout<<endl<<endl;
            cout<<"1. Вернуться в меню."<<endl;
            cout<<"2. Выйти из программы."<<endl;
            cout<<"Ваш выбор: ";
            do
            {
                cin>>SecondMain;
            }
            while(SecondMain>2 or SecondMain<1);

            if(SecondMain==1)
                system("cls");
            else
                Main=true;

            break;
        }

        case 6:
        {
            cout<<"Минимальный элемент: "<<Min(bg1)<<endl;

            cout<<endl<<endl;
            cout<<"1. Вернуться в меню."<<endl;
            cout<<"2. Выйти из программы."<<endl;
            cout<<"Ваш выбор: ";
            do
            {
                cin>>SecondMain;
            }
            while(SecondMain>2 or SecondMain<1);

            if(SecondMain==1)
                system("cls");
            else
                Main=true;

            break;
        }

        }

    }
    system("cls");
    cout<<"Программа окончена."<<endl;


}
