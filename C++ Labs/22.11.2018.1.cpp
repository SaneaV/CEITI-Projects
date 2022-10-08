//Поиск петлей в графе

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

void Petlia()
{
    int k=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==i and G[i][j]==1) cout<<"Вершина "<<i+1<<" имеет петлю"<<endl;
        }
    }
}



int main()
{
    setlocale(LC_ALL,"RUS");

    ReadTXT();
    Show();
    cout<<endl;
    Petlia();

}
