/*1 - to create the tree
2 - to insert new node
3 - to show tree with method NLR
4 - to show tree with method LNR
5 - to show tree with method LRN
6 - to show
7 - to find
8 - to remove node*/

#include<iostream>
using namespace std;
struct Tree
{
    int info;
    Tree *left, *right;
}*root;

void add(Tree *&p, int inf)
{
    Tree *r;
    if(p==NULL)
    {
        r = new Tree;
        r->info=inf;
        r->left=NULL;
        r->right=NULL;
        p=r;

    }
    else if(inf>p->info)
    {
        if(p->right!=NULL)
            add(p->right,inf);
        else
        {
            r = new Tree;
            r->info=inf;
            r->left=NULL;
            r->right=NULL;
            p->right=r;
        }
    }
    else
    {
        if(p->left!=NULL)
            add(p->left,inf);
        else
        {
            r = new Tree;
            r->info=inf;
            r->left=NULL;
            r->right=NULL;
            p->left=r;
        }
    }
}
Tree * createTree()
{
    Tree *p=NULL;
    int x=1;
    while(x!=0)
    {
        cin>>x;
        if (x!=0)
            add(p,x);
    }
    return p;
}

void NLR(Tree *p)
{
    if (p!=NULL)
    {
        cout<<p->info;
        NLR(p->left);
        NLR(p->right);
    }
}

void LNR(Tree *p)
{
    if (p!=NULL)
    {
        LNR(p->left);
        cout<<p->info;
        LNR(p->right);
    }
}

void LRN(Tree *p)
{
    if (p!=NULL)
    {
        LRN(p->left);
        LRN(p->right);
        cout<<p->info;
    }
}

void ShowTree(Tree *p, int level)
{

    if(p!=NULL)
    {
        ShowTree(p->left, level+1);
        for(int i=0; i<level; i++)
            cout<<"        ";
        cout<<p->info<<endl;
        ShowTree(p->right, level+1);
    }
}

Tree * findNode(Tree *p,int x)
{
    if (p!=NULL)
    {
        if(x==p->info)
            return p;
        else if(x<p->info)
            return findNode(p->left,x);
        else
            return findNode(p->right,x);
    }
    else
        return NULL;
}

Tree* findMaxNode(Tree *p)
{

    while (p->right)
        p = p->right;

    return p;
}

Tree * removeByPtr(Tree *p, Tree *rm)
{
    if (p == NULL)
        return p;
    if (rm->info < p->info)
        p->left = removeByPtr(p->left, rm);
    else if (rm->info > p->info)
        p->right = removeByPtr(p->right, rm);
    else if (p->left != NULL and p->right != NULL)
    {
        p->info = findMaxNode(p->left)->info;
        p->left = removeByPtr(p->left, rm);
    }
    else if (p->left != NULL)
        p = p->left;
    else
        p = p->right;
    return p;
}

void removeNode(Tree *p,int x)
{
    if (p==NULL)
        cout<<"tree is empty";
    else
    {
        Tree *rm= findNode(p,x);
        if (rm!=NULL)
            removeByPtr(p,rm);
        else
            cout<<x<<" absent in this tree"<< endl;
    }
}

int main()
{
    int n,inf;
    root=NULL;
    cout<<"Input "<<endl;
    do
    {
        cout<<"1 - to create the tree"<<endl;
        cout<<"2 - to insert new node"<<endl;
        cout<<"3 - to show tree with method NLR"<<endl;
        cout<<"4 - to show tree with method LNR"<<endl;
        cout<<"5 - to show tree with method LRN"<<endl;
        cout<<"6 - to show"<<endl;
        cout<<"7 - to find"<<endl;
        cout<<"8 - to remove node"<<endl;
        cout<<"0 - to exit"<<endl;
        cin>>n;

        switch (n)
        {
        case 1 :
        {
            root = createTree();
            break;
        }
        case 2 :
        {
            cout<<"Input node   ";
            cin>>inf;
            add(root,inf);
            break;
        }
        case 3 :
            NLR(root);
            break;
        case 4 :
            LNR(root);
            break;
        case 5 :
            LRN(root);
            break;
        case 6 :
            ShowTree(root,0);
            break;
        case 7 :
        {
            cout<<"Input element to find";
            cin>>inf;
            Tree *f = findNode(root,inf);
            if (f!=NULL)
                cout<<"yes "<<root->info<<endl;
            else
                cout<<"no"<<endl;
            break;
        }
        case 8 :
        {
            cout<<"Input element to remove";
            cin>>inf;
            removeNode(root,inf);
            break;
        }
        case 0 :
            break;
        default :
            cout<<"incorrect operation";
            break;
        }
        cout<<endl;
    }
    while(n!=0);
    return 0;
}

