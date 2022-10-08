//Создание односвязного списка

#include <iostream>
#include <windows.h>

using namespace std;

struct List
{
    int info;
    List *next;
}*bg;


void Create()
{
    List *cr, *prv;
    if(bg!=NULL)
        cout<<"Лист создан."<<endl;
    else
        do
        {
            cr = new List;

            cout<<"Введите целое число: ";
            cin>>cr->info;

            if(cr->info!=0)
            {
                cr->next=NULL;
                if(bg==NULL)
                    bg = cr;
                else
                    prv->next = cr;
                prv = cr;
            }

        }
        while(cr->info!=0);
}

void Show()
{
    List *cr;

    if(bg==NULL)
        cout<<"Лист пуст."<<endl;
    else
    {
        cr=bg;
        while(cr!=NULL)
        {
            cout<<cr->info<<" ";
            cr=cr->next;
        }
        cout<<endl;
    }

}

List* Find(int p)
{
    List *cr;
    int i=0;
    cr=bg;
    while(cr!=NULL)
    {
        i++;
        if(i==p)
            return cr;
        cr=cr->next;
    };
    return cr;
}

void Insert()
{
    List *r, *q;
    int poz;
    r = new List;
    cout<<"Введите новый элемент: ";
    cin>>r->info;
    cout<<"Введите позицию: ";
    cin>>poz;
    q = Find(poz-1);
    if (poz==1)
    {
        r->next=bg;
        bg=r;
    }
    else
    {
        q=Find(poz-1);
        if(q==NULL)
            cout<<"Нневозможно ввести."<<endl;
        else
        {
            r->next=q->next;
            q->next=r;
        }

    }

}

void Delete()
{
    List *r, *q;

    int poz;
    cout<<"Введите позицию: ";
    cin>>poz;

    if(poz==1)
    {
        r=bg;
        bg=bg->next;
        delete r;
    }

    else
    {
        q=Find(poz-1);
        if(q==NULL)
            cout<<"Невозможно удалить."<<endl;
        else
        {
            r=q->next;
            q->next=r->next;
            delete r;
        }
    }
}

int Sum ()
{
    int Sum = 0;

    List *cr;

    cr = bg;

    while(cr!=NULL)
    {
        Sum+=cr->info;
        cr=cr->next;
    }
    return Sum;
}

int main()
{
    setlocale(LC_ALL,"RUS");

    bg=NULL;
    cout<<"Введите числа, для окончания введите ноль."<<endl<<endl;
    Create();
    system("cls");

    bool Y = false;
    int YY;
    do
    {
        int Selection;
        cout<<"Что вы хотите сделать дальше: "<<endl;
        cout<<"1. Вывести список."<<endl;
        cout<<"2. Найти элемент в списке."<<endl;
        cout<<"3. Добавить новый элемент."<<endl;
        cout<<"4. Удаление элемента."<<endl;
        cout<<"5. Сумма элементов."<<endl;
        cout<<"Ваш выбор: ";
        cin>>Selection;
        system("cls");

        switch(Selection)
        {
        case 1:
        {
            cout<<"Вот так выглядит ваш список: ";
            Show();

            cout<<endl<<endl<<"Продолжить?"<<endl;
            cout<<"1.Да"<<endl;
            cout<<"2.Нет"<<endl;
            cout<<"Ваш выбор: ";
            cin>>YY;

            if(YY==1)
                system("cls");
            if(YY==2)
                Y=true;

            break;
        }
        case 2:
        {
            cout<<"Введите позицию: ";
            int pp;
            cin>>pp;

            List *q=Find(pp);
            cout<<"Число на "<<pp<<" позиции: "<<q->info;

            cout<<endl<<endl<<"Продолжить?"<<endl;
            cout<<"1.Да"<<endl;
            cout<<"2.Нет"<<endl;
            cout<<"Ваш выбор: ";
            cin>>YY;

            if(YY==1)
                system("cls");
            if(YY==2)
                Y=true;
            break;
        }
        case 3:
        {
            Insert();
            Show();

            cout<<endl<<endl<<"Продолжить?"<<endl;
            cout<<"1.Да"<<endl;
            cout<<"2.Нет"<<endl;
            cout<<"Ваш выбор: ";
            cin>>YY;

            if(YY==1)
                system("cls");
            if(YY==2)
                Y=true;
            break;
        }
        case 4:
        {
            Delete();
            Show();

            cout<<endl<<endl<<"Продолжить?"<<endl;
            cout<<"1.Да"<<endl;
            cout<<"2.Нет"<<endl;
            cout<<"Ваш выбор: ";
            cin>>YY;

            if(YY==1)
                system("cls");
            if(YY==2)
                Y=true;
            break;
        }
        case 5:
        {
            cout<<"Сумма элементов: "<<Sum();

            cout<<endl<<endl<<"Продолжить?"<<endl;
            cout<<"1.Да"<<endl;
            cout<<"2.Нет"<<endl;
            cout<<"Ваш выбор: ";
            cin>>YY;

            if(YY==1)
                system("cls");
            if(YY==2)
                Y=true;
            break;
        }
        }
    }
    while(!Y);
    system("cls");




}

