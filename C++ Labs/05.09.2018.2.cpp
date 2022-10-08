//Добавление в начало списка

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    struct List
    {
        char info;
        List *next;
    }*bg,*cr,*prv, *r;

    bg = NULL;

    char x;

    cout<<"Введите символ: ";
    cin>>x;

    cr = new List;
    cr->info=x;
    cr->next=NULL;
    bg=cr;
    prv=cr;

    while(x!='0')
    {

        cout<<"Введите символ: ";
        cin>>x;

        if(x!='0')
        {
            cr = new List;
            cr->info=x;
            cr->next=NULL;
            prv->next=cr;
            prv=cr;
        }



    }

    r = new List;
    r->info='S';
    r->next=bg;
    bg = r;


    cr=bg;

    while(cr!=NULL)
    {
        cout<<cr->info;
        cr=cr->next;
    }



}

