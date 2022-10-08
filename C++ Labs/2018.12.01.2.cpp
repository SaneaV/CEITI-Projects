//Является ли граф гамильтонов

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int n;
int G[100][100];

void ReadTXT()
{
    ifstream f("Graf.txt");

    f>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            f>>G[i][j];
        }
    }
    f.close();
}

void Show()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<G[i][j]<<" ";
        cout<<endl;
    }
}



bool GamelitinovGraf()
{
    if(n<3) return false;

    int k=0;
    int c=0;

    for(int i=0;i<n;i++)
    {
        k=0;
        for(int j=0;j<n;j++)
        {
            if(G[i][j]==1) k++;
        }
        if(k<2) return false;
        if(n/2>k) c++;
    }

    if(c==n-1) return true;


}


int main()
{
    setlocale(LC_ALL,"RUS");

    ReadTXT();
    Show();

    cout<<endl;
       if (GamelitinovGraf())
        cout<<"Гамельтонов граф";
    else
        cout<<"Не гамельтонов граф";


}
