//Создание односвязного списка

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    struct List
    {
        char info;
        List *next;
    }*bg,*cr,*prv;

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

        cr = new List;
        cr->info=x;
        cr->next=NULL;
        prv->next=cr;
        prv=cr;


    }

    cr=bg;

    while(cr!=NULL)
    {
        cout<<cr->info;
        cr=cr->next;
    }



}
