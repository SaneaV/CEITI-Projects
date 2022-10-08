//Создание и вывод двоичного дерева.

#include<iostream>

using namespace std;

struct Tree
{
    char info;
    Tree *left, *right;
}*T;

struct Queue
{
    Tree *info;
    Queue *next;
}*first,*last;

void AddElementQueue(Tree *tmp)
{
    Queue *cr = new Queue;
    cr->info = tmp;
    cr->next = NULL;
    if (first == NULL)
    {
        first=cr;
        last = cr;
    }
    else
    {
        last->next = cr;
        last = cr;
    }
}

Tree * ExtractElementQueue()
{
    Tree *tmp;
    if (first==NULL)
        cout<<"Queue is empty"<<endl;
    else
    {
        Queue *cr = first;
        tmp = cr->info;
        first=first->next;
        delete cr;
    }
    return tmp;
}

void CreateTree()
{
    char ch;
    Tree *r;
    T=NULL;
    first=NULL;
    last=NULL;
    cout<<"Input root"<<endl;
    cin>>ch;

    if(ch!='$')
    {
        r = new Tree;//создание корня
        r->info = ch;
        T=r; //Инициализация адреса корня
        AddElementQueue(T);
    }
    while(first!=NULL)
    {
        Tree *q,*r;
        r = ExtractElementQueue();
        cout<<"Input children of "<<r->info<<endl;
        cout<<"left: ";
        cin>>ch;
        if(ch=='$') r->left=NULL;
        else
        {
            q = new Tree;
            r->left = q;
            q->info = ch;
            AddElementQueue(q);
        }
        cout<<endl<<"right: ";
        cin>>ch;
        if(ch=='$') r->right=NULL;
        else
        {
            q = new Tree;
            r->right = q;
            q->info = ch;
            AddElementQueue(q);
        }
    }
}

void ShowTree()
{
    Tree *r;
    if(T==NULL) cout<<"Tree is empty"<<endl;
    else
    {
        cout<<"Tree:"<<endl;
        first = NULL;
        last = NULL;
        AddElementQueue(T);
        while(first!=NULL)
        {
            r= ExtractElementQueue();
            cout<<endl<<"Node "<<r->info<<endl;
            cout<<"Cildren: ";
            if (r->left==NULL)
                cout<<"NULL ";
            else
            {
                cout<<r->left->info<<",";
                AddElementQueue(r->left);
            }
            if (r->right==NULL)
                cout<<"NULL ";
            else
            {
                cout<<r->right->info<<",";
                AddElementQueue(r->right);
            }
        }
    }
}
int main()
{
    cout<<"Input nodes of tree. To finish input - input \'$\'"<<endl;
    CreateTree();
    ShowTree();
    return 0;
}
