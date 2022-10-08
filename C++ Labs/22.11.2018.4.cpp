//Проверить, является ли граф G2 частичным графом G1

#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int n;
int G[100][100];
int G1[100][100];

void ReadTXT()
{
    ifstream f("Graf.txt");

    f>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            f>>G[i][j];
        }
    }
}

void ReadTXT2()
{
    ifstream g("Graf2.txt");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            g>>G1[i][j];
        }
    }
}

void Show()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<G[i][j]<<" ";
        cout<<endl;
    }
}

void Show2()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<G1[i][j]<<" ";
        cout<<endl;
    }
}

bool Chasti()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        if(G[i][j]!=G1[i][j]) return false;
    }
    return true;
}


int main()
{
    setlocale(LC_ALL,"RUS");

    ReadTXT();
    ReadTXT2();
    Show();
    cout<<endl;
    Show2();
    cout<<endl;
    cout<<"Граф 2 является частичным графом: "<<boolalpha<<Chasti();


}

