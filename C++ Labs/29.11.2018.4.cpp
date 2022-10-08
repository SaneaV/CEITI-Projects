//Проверить является ли цикл простой


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

bool ProstoiCekli()
{
    int k=0;

    cout<<"Введите количество вершин: ";
    cin>>k;

    for(int i=0; i<k; i++)
    {
        cout<<"Введите вершину: ";
        cin>>A[i];
    }

    if(A[0]!=A[k-1]) return false;

    for(int i=0;i<k;i++)
        for(int j=i+1;j<k-1;j++)
        if(A[i]==A[j])
        return false;

    for(int i=0; i<k-1; i++)
    {
        if(G[A[i]][A[i+1]]!=1)
            return false;
    }

    return true;

}



int main()
{
    setlocale(LC_ALL,"RUS");

    ReadTXT();
    Show();
    if (ProstoiCekli()) cout<<"Простой цикл";
    else cout<<"Не простой цикл";


}




