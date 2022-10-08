#include<iostream>
using namespace std;
struct Tree
{
    char info;
    Tree *left, *right;
}*T;

Tree *CreateTree()
{
    Tree *r;
    char ch;
    cout<<"Input info"<<endl;
    cin>>ch;
    if(ch=='$') return NULL;
    else
    {
        r=new Tree;
        r->info = ch;
        cout<<"Input the left child of "<<ch<<": ";
        r->left=CreateTree();
        cout<<"Input the right child of "<<ch<<": ";
        r->right=CreateTree();
        return r;
    }
}

void ShowTree(Tree *T, int level)
{
    if(T!=NULL)
    {
        ShowTree(T->left, level+1);
        for(int i=0; i<level; i++)   cout<<"        ";
        cout<<T->info<<endl;
        ShowTree(T->right, level+1);
    }
}
void NLR(Tree *T)
{
    if (T!=NULL)
    {
        cout<<T->info<<" ";
        NLR(T->left);
        NLR(T->right);
    }
}
void LNR(Tree *T)
{
    if (T!=NULL)
    {
        LNR(T->left);
        cout<<T->info<<" ";
        LNR(T->right);
    }
}

void LRN(Tree *T)
{
    if (T!=NULL)
    {
        LRN(T->left);
        LRN(T->right);
        cout<<T->info<<" ";
    }
}

int main()
{
    cout<<"Input nodes of tree. To finish input - input \'$\'"<<endl;
    T=CreateTree();
    ShowTree(T,0);
    cout<<endl<<"NLR"<<endl;
    NLR(T);
    cout<<endl<<"LNR"<<endl;
    LNR(T);
    cout<<endl<<"LRN"<<endl;
    LRN(T);
    return 0;
}
