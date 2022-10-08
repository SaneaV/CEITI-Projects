//С клавиатуры вводится последовательность целых чисел, завершающаяся нулем. Создать односвязный список, вывести его на экран.
//Удалить все числа кратные 4 и снова вывести его на экран.

#include <iostream>
using namespace std;

struct List
{
    int info;
    List *next;
} *bg;

List *Create(List *bg)
{

    List *cr, *prv;

    bg=NULL;

    do
    {
        cr=new List;
        cout<<"Input Element: ";
        cin>> cr->info;
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
    while(cr->info!=0);

    return bg;

}
void ShowList(List *cr)
{
    if(cr==NULL)
        cout<<"Empty";
    else
    {
        while (cr!=NULL)
        {
            cout<<cr->info<<" ";
            cr=cr->next;
        }

    }
}

List *Delete(List *bg)
{

    List *cr, *prv;

    while(bg->info%4==0)
    {
        cr=bg;
        bg=bg->next;
        delete bg;
    }
    prv=bg;
    while(prv->next!=NULL)
    {
        cr=prv->next;
        if(cr->info==4)
        {
            prv->next=cr->next;
        }
        else prv=cr;
    }

    return bg;
}

int main()
{

    int n;
    do
    {
        cout<<"1. Create list "<<endl;
        cout<<"2. Show  "<<endl;
        cout<<"3. Delete Element"<<endl;
        cin>>n;

        switch(n)
        {
        case 1:
        {
            bg=Create(bg);
            ShowList(bg);
            cout<<endl;
            break;

        }

        case 2:
        {
            cout<<"Show Elements "<<endl;
            ShowList(bg);
            cout<<endl;
            break;

        }
        case 3:
        {

            bg=Delete(bg);
            ShowList(bg);
            cout<<endl;
            break;
        }

        }
    }
    while(n!=0);

}
