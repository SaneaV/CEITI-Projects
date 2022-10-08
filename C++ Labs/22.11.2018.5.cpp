//Имея граф смежностей, составить граф инцидентности

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

int n;
int m=0;
int G[100][100];
int I[100][100];
int k=0;
int c=0;

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



void KolOfReb()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(G[i][j]==1)
                k++;

    k/=2;
}

void Incidentnosti()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            I[i][j]=0;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(G[i][j])
            {
                I[i][c]=1;
                I[j][c]=1;
                c++;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
            cout<<I[i][j]<<" ";
        cout<<endl;
    }
}



int main()
{
    setlocale(LC_ALL,"RUS");

    ReadTXT();
    Show();

    cout<<endl;
    KolOfReb();
    Incidentnosti();


}

