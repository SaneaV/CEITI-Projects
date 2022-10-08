#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int a[50][50],n,m,x[50];
bool flag = false;

struct Color
{
    char color[20];
}
C[100];

void Reading()
{
    ifstream f("Map.txt");
    f>>n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            f>>a[i][j];
}

int FirstElement(int k)
{
    return 1;
}
bool Continue(int k)
{
    for(int i=0; i<k; i++)
        for(int j=0; j<k; j++)
            if(a[i][j]==1 and x[i]==x[j])
                return false;
    return true;
}

bool ExistSuccessor(int k)
{
    return (x[k]<m);
}

int Successor(int k)
{
    return x[k]+1;
}

void ProcessingSolution()
{
    /*if(strcmp(C[0].color,"0")==0)
    for(int i=0;i<m;i++)
    {
        cout<<"Введите цвет: ";
        cin>>C[i].color;
    }*/

    cout<<endl<<"Решение:"<<endl;
    cout<<m<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<x[i]<<" ";
        //if(x[i]) cout<<C[i].color<<endl;
    }
    flag=true;
}

void Backtracking(int k)
{
    if(k<=n)
    {
        x[k]=FirstElement(k);
        if(Continue(k))
            Backtracking(k+1);
        while (ExistSuccessor(k))
        {
            x[k]=Successor(k);
            if(Continue(k))
                Backtracking(k+1);
        }
    }
    else
        ProcessingSolution();
}

int main()
{
    setlocale(0,"rus");

    Reading();

    /*for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }*/

    strcpy(C[0].color,"0");
    m=1;
    while(!flag)
    {
        Backtracking(0);
        m++;
    }
}

