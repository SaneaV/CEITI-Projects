//Проверка, является ли граф полным.

#include <iostream>
#include <fstream>

using namespace std;

int n;
int G[100][100];

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

void Show()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<G[i][j]<<" ";
        cout<<endl;
    }
}

bool Polnii()
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==i and G[i][j]!=0) return false;
        }
    }
    return true;
}



int main()
{
    setlocale(LC_ALL,"RUS");

    ReadTXT();
    Show();
    cout<<endl;
    cout<<"Граф является полный - "<<Polnii();

}

