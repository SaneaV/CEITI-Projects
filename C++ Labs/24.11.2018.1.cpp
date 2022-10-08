//Вывести два графа на жкран

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

int n=0;
int m=0;
int G[100][100];
int G2[100][100];


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

void ReadTXT2()
{
    ifstream g("Graf2.txt");

    g>>m;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            g>>G2[i][j];
        }
    }
    g.close();
}

void Show(int T[100][100],int k)
{
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k; j++)
            cout<<T[i][j]<<" ";
        cout<<endl;
    }
}


int main()
{
    setlocale(LC_ALL,"RUS");

    ReadTXT();
    ReadTXT2();

    Show(G,n);
    cout<<endl;
    Show(G2,m);




}

