///Различные задачи на повторение списков
///1. Создание списка
///2. Вывод списка
///3. Поиск максимального и минимального числа в списке.
///4. Сумма чисел
///5. Удаление элемента по значению
///6. Удаление элменета по позиции
///7. Добавление элемента в список на любую позицию
///8. Вывести на экран все элементы кратные "n"

#include <iostream>

using namespace std;

struct List
{
    int info;
    List *next;
}
*bg;

List *Filling()
{
    List *cr, *prv;
    int n;

    cout<<"Введите количество элементов списка: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cr=new List;
        cout<<"Введите число: ";
        cin>>cr->info;
        cr->next=NULL;

        if(bg==NULL)
        {
            bg=cr;
            prv=bg;
        }
        else
        {
            prv->next=cr;
            prv=cr;
        }

    }
    return bg;
}

void ShowList()
{
    if (bg==NULL)
    {
        cout<<"Список пуст"<<endl;
    }

    else
    {
        List *cr=bg;

        while(cr!=NULL)
        {
            cout<<cr->info<<" ";
            cr=cr->next;
        }
    }
}

void MaxMin()
{
    if(bg!=NULL)
    {
        List *cr=bg;
        int Max=bg->info;
        int Min=bg->info;

        while(cr!=NULL)
        {
            if(cr->info>Max)
                Max=cr->info;
            if(cr->info<Min)
                Min=cr->info;
            cr=cr->next;
        }

        cout<<endl<<endl;
        cout<<"Максимальное число: "<<Max<<endl;
        cout<<"Минимальное число: "<<Min<<endl;

    }
}

void Sum()
{
    if(bg!=NULL)
    {
        List *cr=bg;
        int Sum=0;

        while(cr!=NULL)
        {
            Sum+=cr->info;
            cr=cr->next;
        }

        cout<<endl<<endl;
        cout<<"Сумма чисел: "<<Sum<<endl;
    }
}

List *DeleteByINT()
{
    if(bg!=NULL)
    {
        cout<<endl<<endl;
        List *cr, *prv;
        int n;
        int k=0;

        cout<<"Введите число, которые вы хотите удалить: ";
        cin>>n;

        if(bg->info==n)
        {
            bg=bg->next;
            k++;
        }
        cr=bg;
        prv=bg;

        while(cr!=NULL)
        {
            if(cr->info==n)
            {
                prv->next=cr->next;
                k++;
            }
            prv=cr;
            cr=cr->next;
        }

        if(k!=0)
            cout<<"Элемент удалён"<<endl;
        else
            cout<<"Такой элемент не найден"<<endl;
    }

    return bg;
}

List *DeleteByPos()
{
    if(bg!=NULL)
    {
        cout<<endl<<endl;
        List *cr, *prv;
        int n;
        int k=1;

        cout<<"Введите позицию элемента: ";
        cin>>n;

        if(n==1)
        {
            bg=bg->next;
        }
        cr=bg;
        prv=bg;

        while(cr!=NULL)
        {
            if(k==n)
            {
                prv->next=cr->next;
            }
            prv=cr;
            cr=cr->next;
            k++;
        }

        if(k<n)
            cout<<"Такого номера в списке нет"<<endl;
        else
            cout<<"Элмент был удалён"<<endl;
    }
}

List *Add()
{
    List *cr, *r, *prv;

    int n;
    int p;
    int k=1;

    r=new List;
    cout<<"Введите элемент, который необходимо добавить: ";
    cin>>r->info;
    r->next=NULL;

    if(bg==NULL)
    {
        cout<<"Элмент будет добавлен на первую позицию"<<endl;
        bg=r;
    }
    else
    {
        cout<<"Введите позицию, на которую необходимо добавить элемент: ";
        cin>>p;

        if(p==1)
        {
            cr=bg;
            bg=r;
            bg->next=cr;
        }
        else
        {
            cr=bg;
            prv=cr;

            while(cr!=NULL)
            {
                if(k==p)
                {
                    prv->next=r;
                    r->next=cr;
                }

                prv=cr;
                cr=cr->next;
                k++;
            }

            if(k==p)
            {
                prv->next=r;
            }

        }

        if(k+1<p)
            cout<<"Позиция намного больше необходимой"<<endl;
        else
            cout<<"Элемент был добавлен"<<endl;
    }

    return bg;
}


int main()
{
    setlocale(LC_ALL,"RUS");

    bg=NULL;

    bg=Filling();
    cout<<endl<<endl;
    ShowList();
    MaxMin();
    Sum();
    bg=DeleteByINT();
    if(bg!=NULL)
    {
        cout<<endl<<endl<<"Новый вид списка: "<<endl;
        ShowList();
    }
    cout<<endl;
    DeleteByPos();
    if(bg!=NULL)
    {
        cout<<endl<<endl<<"Новый вид списка: "<<endl;
        ShowList();
    }
    cout<<endl<<endl;
    bg=Add();
    if(bg!=NULL)
    {
        cout<<endl<<endl<<"Новый вид списка: "<<endl;
        ShowList();
    }


}
