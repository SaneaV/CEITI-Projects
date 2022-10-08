//Создайте L – односвязный список элементов типа CHAR.
//Добавить в список перед каждой большой буквы соответствующую маленькую,
//а все остальные элементы удалить из списка. Вывести элементы списка на экран.

#include<iostream>

using namespace std;

struct L
{
    char B;
    L *next;
}*bg;

int n;

L *Sozdat()
{
    L *cr,*prv;


    cout<<"Сколько букв - ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cr = new L;
        cout<<"Буква - ";
        cin>>cr->B;
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

void Show(L *cr)
{
    if(cr==NULL)
        cout<<"Empty"<<endl;
    else
    {
        while(cr!=NULL)
        {
            cout<<cr->B<<" ";
            cr=cr->next;
        }
    }
}

L *Delete(L *bg)
{
    L *cr, *prv;

    while(islower(bg->B) or isdigit(bg->B) or ispunct(bg->B))
    {
        cr=bg;
        bg=bg->next;
        delete cr;
        if(bg==NULL) return bg;
    }



    prv=bg;

    while(prv->next!=NULL)
    {
        cr=prv->next;
        if(islower(cr->B) or isdigit(cr->B) or ispunct(cr->B))
        {
            prv->next=cr->next;
            delete cr;
        }
        else
            prv=cr;
    }

    return bg;
}

L *Smena(L *bg)
{
    if(bg==NULL) return bg;
    L *cr, *prv, *r;

    prv=bg;

    while(prv->next!=NULL)
    {
        cr=prv->next;
        if(isupper(cr->B))
        {
            r = new L;
            r->B=tolower(prv->B);
            r->next=prv->next;
            prv->next=r;
        }
        prv=cr;

    }

    if(isupper(cr->B))
    {
        cr->next=new L;
        cr=cr->next;
        cr->B=tolower(prv->B);
        cr->next=NULL;
    }

    return bg;
}

int main()
{
    setlocale(LC_ALL,"russian");

    bg=NULL;
    bg=Sozdat();
    Show(bg);
    bg=Delete(bg);
    bg=Smena(bg);
    cout<<endl;
    Show(bg);
}
