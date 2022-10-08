#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

struct Candidat
{
    char name[20];
    float Mark;
    Candidat *next;
}*bg;

struct Candidat2
{
    char name[20];
    float Mark;
    Candidat2 *next;
}*bg2;


void Create()
{
    Candidat *cr, *prv;
    if(bg!=NULL)
        cout<<"Лист создан."<<endl;
    else
        do
        {
            cr = new Candidat;

            do
            {
                cout<<"Введите имя ученика: ";
                cin>>cr->name;
                cout<<"Введите средний балл: ";
                cin>>cr->Mark;
                cout<<endl;
            }
            while(cr->Mark>10 or cr->Mark<0);


            if(cr->Mark!=0)
            {
                cr->next=NULL;
                if(bg==NULL)
                    bg = cr;
                else
                    prv->next = cr;
                prv = cr;
            }

        }
        while(cr->Mark!=0);
}

void Show()
{
    Candidat *cr;

    if(bg==NULL)
        cout<<"Лист пуст."<<endl;
    else
    {
        cr=bg;
        while(cr!=NULL)
        {
            cout<<cr->name<<" - "<<cr->Mark<<endl;
            cr=cr->next;
        }
        cout<<endl;
    }

}


void Delete()
{
    Candidat *prev=0, *cr;

    char NameS[20];
    cout<<"Введите имя ученика, который покидает школу: ";
    cin>>NameS;

    cr=bg;
    int k=0;

    while(cr)
    {
        Candidat *next = cr->next;
        if(strcmp(cr->name,NameS)==0)
        {
            k++;
            if (prev)
                prev->next = next;
            delete cr;
        }
        else
        {
            prev = cr;
        }
        cr = next;
    }
    if(k==0)
        cout<<"Такого студента нет"<<endl;
}

Candidat* Find(int p)
{
    Candidat *cr;
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
    Candidat *r, *q;
    int poz;
    r = new Candidat;
    cout<<"Введите имя ученика: ";
    cin>>r->name;
    cout<<"Введите средний балл ученика: ";
    cin>>r->Mark;
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

void MT75()
{
    Candidat *cr;

    cr=bg;

    while(cr!=NULL)
    {
        if(cr->Mark>7.5)
        {
            cout<<cr->name<<" "<<cr->Mark<<endl;
        }
        cr=cr->next;
    }
}

void CtoC2()
{
    Candidat2 *cr2, *prv;
    Candidat *cr;

    cr = bg;

    while(cr!=NULL)
    {
        if(cr->Mark>9)
        {
            cr2= new Candidat2;
            cr2->next=NULL;

            strcpy(cr2->name,cr->name);
            cr2->Mark=cr->Mark;

            if(bg2==NULL)
                bg2 = cr2;
            else
                prv->next = cr2;
            prv = cr2;

        }
        cr=cr->next;
    }
}

void Show2()
{
    Candidat2 *cr;

    if(bg2==NULL)
        cout<<"Лист пуст."<<endl;
    else
    {
        cr=bg2;
        while(cr!=NULL)
        {
            cout<<cr->name<<" - "<<cr->Mark<<endl;
            cr=cr->next;
        }
        cout<<endl;
    }

}


void DeleteM6 ()
{
    Candidat *cr, *r, *q;

    cr = bg;
    int i=0;

    while(cr!=NULL)
    {
        i++;
        if(cr->Mark<6)
        {
            if(i==1)
            {
                r=bg;
                bg=bg->next;
                delete r;
            }
            else
            {
                q=cr;

                r=q->next;
                q->next=r->next;
                delete r;
            }
        }
        cr=cr->next;
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");

    bg=NULL;
    cout<<"Введите значения."<<endl;
    cout<<"Ввод закончите нулём в поле среднего балла."<<endl<<endl;;

    Create();

    system("cls");


    bool Y = false;
    int YY;
    do
    {
        int Selection;
        cout<<"Что вы хотите сделать дальше: "<<endl;
        cout<<"1. Посмотреть список."<<endl;
        cout<<"2. Удалить ученика из списка.(возникают ошибки)"<<endl;
        cout<<"3. Добавить ученика."<<endl;
        cout<<"4. Вывод на экран людей, у которых балл выше 7,5."<<endl;
        cout<<"5. Создать второй список и ввести туда людей, у которых балл выше 9"<<endl;
        cout<<"6. Удалить из списка людей, средний балл которых меньше 6.(работает частично)"<<endl;
        do
        {
            cin>>Selection;
        }
        while(Selection<0);
        system("cls");

        switch(Selection)
        {
        case 1:
        {
            cout<<"Список учеников: "<<endl<<endl;
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
            MT75();

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
            CtoC2();
            Show2();

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
        case 6:
        {
            DeleteM6();
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

        }
    }
    while(!Y);

}


