//Поместить ферзей на шахматной доске так, чтобы они не били друг друга.

#include <iostream>
#include <cmath>

using namespace std;

int a[50][50],n,m[50],x[50];
bool flag;

int FirstElement(int k)
{
    return 0;
}
bool Continue(int k)
{
    for(int i=0; i<k; i++)
    {
        if(x[i]==x[k])
            return false;
        if(abs(x[i]-x[k])==abs(i-k))
            return false;
    }
    return true;
}

bool ExistSuccessor(int k)
{
    return (x[k]<n-1);
}

int Successor(int k)
{
    return x[k]+1;
}

void ProcessingSolution()
{
    for(int i=0; i<n; i++)
        a[i][x[i]]=1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<" ";

        cout<<endl;
    }
    cout<<endl<<endl;
    flag=true;
    for(int i=0; i<n; i++)
        a[i][x[i]]=0;
}

void Backtracking(int k)
{
    if(k<n)
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
    setlocale(0,"");

    cout<<"Введите количество ферзей: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            a[i][j]=0;
    }

    flag=false;
    Backtracking(0);
    if(!flag)
        cout<<"Решения нет";
}
