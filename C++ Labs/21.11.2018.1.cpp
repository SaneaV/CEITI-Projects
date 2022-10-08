//Элементарные операции над графом

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

void Vesiachii()
{
    int k=0;

    for(int i=0;i<n;i++)
    {
        k=0;
        for(int j=0;j<n;j++)
        {
            if(G[i][j]==1) k++;
        }
        if(k==1) cout<<"Вершина - "<<i+1<<" является весячей"<<endl;
    }
}

void Izolirovan()
{
    int k=0;

    for(int i=0;i<n;i++)
    {
        k=0;
        for(int j=0;j<n;j++)
        {
            if(G[i][j]==1) k++;
        }
        if(k==0) cout<<"Вершина - "<<i+1<<" является изолированной"<<endl;
    }
}

void Chetnosti()
{
    int k=0;

    for(int i=0;i<n;i++)
    {
        k=0;
        for(int j=0;j<n;j++)
        {
            if(G[i][j]==1) k++;
        }
        if(k%2==0) cout<<"Вершина - "<<i+1<<" c чётной степенью"<<endl;
    }
}

void Max()
{
    int max=0;
    int k=0;
    int pmax=0;


    for(int i=0;i<n;i++)
    {
        k=0;
        for(int j=0;j<n;j++)
        {
            if(G[i][j]==1) k++;
        }
        if(k>max) {max=k; pmax=i;}
    }

    cout<<"Максимальное число вершин у графа - "<<pmax+1<<endl;
}

void Stepeni()
{
    int k=0;

    for(int i=0;i<n;i++)
    {
        k=0;
        for(int j=0;j<n;j++)
        {
            if(G[i][j]==1) k++;
        }
        cout<<"Степень вершины: "<<i+1<<" - "<<k<<endl;
    }
}

void KolOfViseach()
{
    int k=0;
    int KOfIVisech=0;

    for(int i=0;i<n;i++)
    {
        k=0;
        for(int j=0;j<n;j++)
        {
            if(G[i][j]==1) k++;
        }
        if (k==1) KOfIVisech++;
    }

    cout<<"Количество висячих вершин: "<<KOfIVisech<<endl;
}

void KolOfIzolat()
{
    int k=0;
    int KOfIzol=0;

    for(int i=0;i<n;i++)
    {
        k=0;
        for(int j=0;j<n;j++)
        {
            if(G[i][j]==1) k++;
        }
        if (k==0) KOfIzol++;
    }

    cout<<"Количество изолированных вершин: "<<KOfIzol<<endl;
}

int main()
{
    setlocale(LC_ALL,"RUS");

    ReadTXT();
    Show();
    cout<<endl;
    Vesiachii();
    cout<<endl;
    Izolirovan();
    cout<<endl;
    Chetnosti();
    cout<<endl;
    Max();
    cout<<endl;
    Stepeni();
    cout<<endl;
    KolOfIzolat();
    cout<<endl;
    KolOfViseach();
    cout<<endl;
}
