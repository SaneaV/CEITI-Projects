//Работа со списком

#include <iostream>

using namespace std;

struct List
{
    int info;
    List *next;
}*bg1, *bg2;

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

void *Combine(List *bg1, List *bg2)
{
    List *cr;
    cr=bg1;
    while(cr->next!=NULL)
        cr=cr->next;
    cr->next=bg2;
}

List *Find(List *cr, int key)
{
    while(cr!=NULL)
    {
        if(key==cr->info)
            return cr;
        cr=cr->next;
    }
    return cr;
}

List *Delete(List *bg1)
{
    List *prv, *cr;

    while(bg1->info==1)
    {
        cr=bg1;
        bg1=bg1->next;
        delete cr;
    }

    prv=bg1;

    while(prv->next!=NULL)
    {
        cr=prv->next;
        if(cr->info==1)
        {
            prv->next=cr->next;
            delete cr;
        }
        else prv=cr;
    }
    return bg1;
}

int main()
{
    setlocale(LC_ALL,"RUS");
    bg1=Create();
    cout<<endl;
    bg2=Create();

    Show(bg1);
    cout<<endl;
    Show(bg2);
    cout<<endl;

    cout<<endl;
    List *q=Find(bg1,3);
    cout<<q<<endl;
    cout<<endl;
    List *q2=Find(bg2,4);
    cout<<q2<<endl;

    Combine(bg1,bg2);
    cout<<endl;
    Show(bg1);

    cout<<endl;
    bg1= Delete(bg1);
    Show(bg1);


}
