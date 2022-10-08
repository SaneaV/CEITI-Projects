#include <iostream>
#include <windows.h>

using namespace std;

struct List
{
    int info;
    List *next;
    List *previous;
}*bg, *fn;

struct List* Finish(List *bg)
{
    List *cr;

    cr=bg;

    if(bg->next==NULL)
    {
        fn=bg;
    }

    while(cr->next!=NULL)
    {
        cr=cr->next;
        if(cr->next==NULL)
            fn=cr;
    }

    return fn;
};

struct List* Create()
{
    List *cr, *prv;
    bool Y=true;
    int Sel;

    do
    {
        cr=new List;
        cout<<"Input Number: ";
        cin>>cr->info;

        if(bg==NULL)
        {
            bg=cr;
            cr->next=NULL;
            cr->previous=NULL;
            prv=cr;
        }
        else
        {
            prv->next=cr;
            cr->previous=prv;
            prv=cr;
        }

        cout<<"1.Yes."<<endl;
        cout<<"2.No."<<endl;
        cout<<"Repeat Input: ";
        do
        {
            cin>>Sel;
        }
        while(Sel>2 or Sel<1);

        if(Sel==1)
        {
            system("cls");
        }
        else
            Y=false;
    }
    while(Y);

    fn=Finish(bg);
    return bg;
};

void Show(List *bg, List *fn)
{
    List *cr;
    int Ch;

    cout<<"1. From the beginning of the list."<<endl;
    cout<<"2. From the end of the list."<<endl;
    cout<<"Your choice: ";
    do
    {
        cin>>Ch;
    }
    while(Ch>2 or Ch<1);

    system("cls");


    if (Ch==1)
    {
        cr=bg;

        if(bg==NULL)
            cout<<"The list is empty."<<endl;

        while(cr!=NULL)
        {
            cout<<cr->info<<" ";
            cr=cr->next;
        }
    }

    if (Ch==2)
    {
        if(fn==NULL)
            cout<<"The list if empty."<<endl;

        cr=fn;
        while(cr!=NULL)
        {
            cout<<cr->info<<" ";
            cr=cr->previous;
        }
    }

}

struct List* DeleteFromBegin(List *bg)
{
    List *cr, *prv;

    system("cls");

    cr=bg;

    int Ch2;

    cout<<"1. Delete by position."<<endl;
    cout<<"2. Delete selected number."<<endl;
    cout<<"Your choice: ";
    do
    {
        cin>>Ch2;
    }
    while(Ch2>2 or Ch2<1);

    if (Ch2==1)
    {
        int i=1;

        cout<<"Input position: ";
        int p;
        cin>>p;

        if(bg==fn and p==1)
        {
            bg=NULL;
            fn=NULL;
            return bg;
        }

        if(p==1)
        {
            bg=bg->next;
            bg->previous=NULL;
            delete cr;
        }

        else
        {
            cr=bg->next;
            prv = bg;

            while(cr!=NULL)
            {
                i++;
                if(p==i)
                {
                    if(cr==fn)
                    {
                        cr=fn;
                        fn=fn->previous;
                        fn->next=NULL;
                        delete cr;
                        fn = Finish(bg);
                    }
                    else
                    {
                        cr->next->previous=cr->previous;
                        prv->next=cr->next;
                    }
                }
                prv=cr;
                cr=cr->next;
            }
        }
    }

    if(Ch2==2)
    {
        cout<<"Input Number: ";
        int num;
        cin>>num;

        cr=bg;

        if(bg==fn and num==bg->info)
        {
            bg=NULL;
            fn=NULL;
            return bg;
        }

        while(bg->info==num)
        {
            bg=bg->next;
            bg->previous=NULL;


        }
        prv=bg;
        cr=bg->next;

        if(fn->info==num)
        {
            cr=fn;
            fn=fn->previous;
            fn->next=NULL;
            delete cr;
            fn = Finish(bg);
        }

        while(cr!=NULL)
        {
            if(cr->info==num)
            {
                cr->next->previous=cr->previous;
                prv->next=cr->next;
            }
            prv=cr;
            cr=cr->next;
        }
    }

    return bg;
}

struct List *DeleteFromEnd(List *fn)
{
    List *cr, *prv;

    system("cls");

    cr=bg;

    int Ch2;

    cout<<"1. Delete by position."<<endl;
    cout<<"2. Delete selected number."<<endl;
    cout<<"Your choice: ";
    do
    {
        cin>>Ch2;
    }
    while(Ch2>2 or Ch2<1);

    if(Ch2==1)
    {
        int i=1;

        cout<<"Input position: ";
        int p;
        cin>>p;

        if(bg==fn and p==1)
        {
            bg=NULL;
            fn=NULL;
            return fn;
        }

        if(p==1)
        {
            fn=fn->previous;
            fn->next=NULL;
        }

        else
        {
            cr=fn->previous;
            prv = fn;

            while(cr!=NULL)
            {
                i++;
                if(p==i)
                {
                    if(cr==bg)
                    {
                        cr=bg;
                        bg=bg->next;
                        bg->previous=NULL;
                        delete cr;
                    }
                    else
                    {
                        cr->previous->next=cr->next;
                        prv->previous=cr->previous;
                    }
                }
                prv=cr;
                cr=cr->previous;
            }
        }
    }

    if(Ch2==2)
    {
        cout<<"Input Number: ";
        int num;
        cin>>num;

        cr=bg;

        if(bg==fn and num==fn->info)
        {
            bg=NULL;
            fn=NULL;
            return fn;
        }

        while(fn->info==num)
        {
            fn=fn->previous;
            fn->next=NULL;


        }
        prv=fn;
        cr=fn->previous;

        if(bg->info==num)
        {
            cr=bg;
            bg=bg->next;
            bg->previous=NULL;
            delete cr;
            fn = Finish(bg);
        }

        while(cr!=NULL)
        {
            if(cr->info==num)
            {
                cr->previous->next=cr->next;
                prv->previous=cr->previous;
            }
            prv=cr;
            cr=cr->previous;
        }
    }

    return fn;


};

struct List* AddElement(List *bg)
{
    List *cr, *prv, *r;
    cr=bg;
    int i=1;

    cout<<"Input Element: ";
    r=new List;
    int num;
    cin>>num;

    cout<<endl<<endl<<"Input Position: ";
    int poz;
    cin>>poz;

    r->info=num;

    if(poz==1 and bg!=NULL)
    {
        bg->previous=r;
        r->next=bg;
        r->previous=NULL;
        bg=r;
    }


    cr=bg->next;
    prv = bg;

    while(cr!=NULL)
    {
        i++;
        if(poz==i)
        {
            prv->next=r;
            cr->previous=r;
            r->previous=prv;
            r->next=cr;


        }
        else if (cr->next==NULL and poz==i+1)
        {
            fn->next=r;
            r->previous=fn;
            r->next=NULL;
            return bg;
        }
        prv=cr;
        cr=cr->next;

    }

    return bg;
}


int main()
{

    bg=NULL;
    fn=NULL;

    bg=Create();

    bool Menu = true;
    int Selection;

    system("cls");

    do
    {
        cout<<"1. Show on the screen."<<endl;
        cout<<"2. Delete from beginning of the list."<<endl;
        cout<<"3. Delete from end of the list."<<endl;
        cout<<"4. Add element in the list."<<endl;
        cout<<"Your choice: ";
        do
        {
            cin>>Selection;
        }
        while(Selection<1 or Selection>4);

        system("cls");

        switch (Selection)
        {
        case 1:
        {
            Show(bg,fn);

            cout<<endl<<"1. Back to Menu."<<endl;
            cout<<"2. Exit."<<endl;
            cout<<"Your choice: ";
            do
            {
                cin>>Selection;
            }
            while(Selection>2 or Selection<1);

            if(Selection==1)
            {
                system("cls");
            }
            else
                Menu=false;
            break;
        }

        case 2:

        {
            bg = DeleteFromBegin(bg);
            Show(bg,fn);

            cout<<endl<<endl<<"1. Back to Menu."<<endl;
            cout<<"2. Exit."<<endl;
            cout<<"Your choice: ";
            do
            {
                cin>>Selection;
            }
            while(Selection>2 or Selection<1);

            if(Selection==1)
            {
                system("cls");
            }
            else
                Menu=false;
            break;
        }

        case 3:
            {
                fn = DeleteFromEnd(fn);
                Show(bg,fn);

            cout<<endl<<endl<<"1. Back to Menu."<<endl;
            cout<<"2. Exit."<<endl;
            cout<<"Your choice: ";
            do
            {
                cin>>Selection;
            }
            while(Selection>2 or Selection<1);

            if(Selection==1)
            {
                system("cls");
            }
            else
                Menu=false;
            break;
            }

        case 4:
        {
            bg = AddElement(bg);
            fn = Finish(bg);
            Show(bg,fn);

            cout<<endl<<endl<<"1. Back to Menu."<<endl;
            cout<<"2. Exit."<<endl;
            cout<<"Your choice: ";
            do
            {
                cin>>Selection;
            }
            while(Selection>2 or Selection<1);

            if(Selection==1)
            {
                system("cls");
            }
            else
                Menu=false;
            break;
        }
        }
    }
    while(Menu);


}
