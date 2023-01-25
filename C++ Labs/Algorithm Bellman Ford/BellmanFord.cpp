#include <iostream>
#include <fstream>
#include <vector>
#define inf 100000

using namespace std;


struct Edges
{
    int u, v, w;
};

void ReadSizeFromFile(int &n, int &m)
{
    ifstream f("Graf.txt");
    f>>n;
    f>>m;
    f.close();
}

void ReadGrafFromFile(int **&Graf, int const n, int const m)
{
    ifstream f("Graf.txt");
    f.ignore();
    f.ignore();
    f.ignore();
    f.ignore();
    f.ignore();

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            f>>Graf[i][j];
        }
    }
    f.close();
}

void Show(int** const Graf,int const n,int const m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<Graf[i][j]<<" ";
        cout<<endl;
    }
}

const int Vmax=1000;
const int Emax=Vmax*(Vmax-1)/2;
int i, j, n, e, start;
Edges edge[Emax];
int d[Vmax];

void InputGraf(int** const Graf, int const n, int const m)
{
    e=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            if(Graf[i][j]!=0)
            {
                edge[e].v=i;
                edge[e].u=j;
                edge[e].w=Graf[i][j];
                e++;
            }
        }
}


void Solve(int n, int m, int s)
{
    for (i=0; i<n; i++) d[i]=inf;
    d[s]=0;

    for (i=0; i<n-1; i++)
        for (j=0; j<e; j++)
            if (d[edge[j].v]+edge[j].w<d[edge[j].u])
                d[edge[j].u]=d[edge[j].v]+edge[j].w;

    for (i=0; i<n; i++) if (d[i]==inf)
            cout<<endl<<start<<"->"<<i<<"="<<"Not";
        else cout<<endl<<start<<"->"<<i<<"="<<d[i];

}

int main()
{


    int n,m;

    ReadSizeFromFile(n,m);

    int** Graf=new int*[n];
    for(int i=0; i<n; i++)
        Graf[i]=new int[m];

    ReadGrafFromFile(Graf, n, m);
    Show(Graf, n, m);
    InputGraf(Graf,n,m);
    Solve(n,m,0);

}
