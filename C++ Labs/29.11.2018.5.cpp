#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

int n=0;
int G[100][100];
int A[100];

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

bool GameltonCikle()
{
    int k=0;
    int B[100];

    cout<<"Введите количество вершин: ";
    cin>>k;

    if (k!=n+1) return false;

    for(int i=0; i<k; i++)
    {
        cout<<"Введите вершину: ";
        cin>>A[i];
    }

    if(A[0]!=A[k-1]) return false;

    for(int i=0;i<k;i++)
    {
        B[i]=0;
    }

    for(int i=0; i<k-1; i++)
    {
        if(G[A[i]][A[i+1]]!=1)
            return false;
        B[i]+=1;
    }

    for(int i=0;i<k-1;i++)
    {
        if(B[i]!=1) return false;
    }

    return true;


}



int main()
{
    setlocale(LC_ALL,"RUS");

    ReadTXT();
    Show();
    if (GameltonCikle()) cout<<"Гамельтонов цикл";
    else cout<<"Не гамельтонов цикл";



}


