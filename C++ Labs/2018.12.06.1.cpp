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

void Tsepi()
{
    int k=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(G[i][j]==1)
                for(int p=j; p<n; p++)
                    if(G[j][p]==1)
                        for(int q=p; q<n; q++)
                            if(G[p][q]==1)
                            {
                                if(i==p and q==j) cout<<"Öèêë: "<<endl;
                                else cout<<"Öåïü: "<<endl;
                                cout<<i<<" "<<j<<endl;
                                cout<<j<<" "<<p<<endl;
                                cout<<p<<" "<<q<<endl;
                                q=n;
                                p=n;
                                cout<<endl<<endl;

                            }
        }
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");

    ReadTXT();
    Show();

    cout<<endl;
    Tsepi();
}
