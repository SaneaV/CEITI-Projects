//ѕросмотр инцидентных вершин по заданой пользователем.

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

void Incidentnosti()
{
    cout<<"¬ведите вершину: ";
    int v;
    cin>>v;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v==i+1 and G[i][j]==1) cout<<i+1<<" "<<j+1<<endl;
        }
    }

}


int main()
{
    setlocale(LC_ALL,"RUS");

    ReadTXT();
    Show();
    Incidentnosti();


}


