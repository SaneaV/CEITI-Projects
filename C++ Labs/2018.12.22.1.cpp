///Различные задания на повторение графа
///1. Чтение графа из файла
///2. Вывод графа на экран
///3. Вывести висячие вершины и их количество
///4. Вывести изолированные вершины и их количество
///5. Вывести вершины чётной степени
///6. Вывести степень каждой вершины
///7. Вывести вершину с петлёй
///8. Является ли граф полным (без учёта вершин)
///9. Рёбра инцидентные вершины v

#include <iostream>
#include <fstream>

using namespace std;

int n;
int G[25][25];

///Чтение из файла

void Reading()
{
    ifstream f("Graf.txt");

    f>>n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            f>>G[i][j];

    f.close();
}

///Вывод на экран

void Show()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<G[i][j]<<" ";
        cout<<endl;
    }
}

///Висячие вершины

void HangingPeaks()
{
    cout<<endl;
    int k=0;
    int c=0;

    for(int i=0; i<n; i++)
    {
        k=0;
        for(int j=0; j<n; j++)
        {
            if(G[i][j]==1)
                k++;
        }
        if(k==1)
        {
            cout<<"Вершина "<<i+1<<" - висячая"<<endl;
            c++;
        }
    }

    cout<<"Количество висячих вершин: "<<c<<endl;
}

///Изолированные вершины

void IsolatedPeaks()
{
    cout<<endl;
    int k=0;
    int c=0;

    for(int i=0; i<n; i++)
    {
        k=0;
        for(int j=0; j<n; j++)
        {
            if(G[i][j]==1)
                k++;
        }

        if(k==0)
        {
            cout<<"Вершина "<<i+1<<" - изолированная"<<endl;
            c++;
        }
    }

    cout<<"Количество изолированных вершин: "<<c<<endl;
}

///Вершины чётной степени

void EvenDegreeOfPeaks()
{
    cout<<endl;
    int k=0;

    for(int i=0; i<n; i++)
    {
        k=0;
        for(int j=0; j<n; j++)
        {
            if(G[i][j]==1)
                k++;
        }

        if(k%2==0)
            cout<<"Вершина "<<i+1<<" - чётной степени"<<endl;
    }
}

///Вывести степень каждой вершины

void DegreeOfPeaks()
{
    cout<<endl;
    int k=0;

    for(int i=0; i<n; i++)
    {
        k=0;
        for(int j=0; j<n; j++)
        {
            if(G[i][j]==1)
                k++;
        }

        cout<<"Степень вершины "<<i+1<<" - "<<k<<endl;
    }
}

///Вершина с петлёй

void PeaksWithLoop()
{
    cout<<endl;

    bool Y=false;

    for(int i=0; i<n; i++)
    {
        Y=false;
        for(int j=0; j<n; j++)
        {
            if(j==i and G[i][j]==1)
                Y=true;
        }

        if(Y)
            cout<<"Вершина "<<i+1<<" - с петлёй"<<endl;
    }
}

///Является ли граф полным (без учёта вершин)

bool FullGraf()
{
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j!=i and G[i][j]!=1)
                return false;
        }
    }
}

///Рёбра инцидентные вершины v

void IncidentRebra()
{
    cout<<endl;

    int v;

    do
    {
        cout<<"Введите вершину(от 0 до "<<n-1<<"): ";
        cin>>v;
    }
    while(v<0 or v>n-1);

    for(int i=v; i==v; i++)
        for(int j=0; j<n; j++)
            if(G[i][j]==1)
            {
                cout<<"Ребро ["<<i<<":"<<j<<"]"<<endl;
            }

}

int main()
{
    setlocale(LC_ALL,"RUS");


    Reading();
    Show();
    HangingPeaks();
    IsolatedPeaks();
    EvenDegreeOfPeaks();
    DegreeOfPeaks();
    PeaksWithLoop();
    cout<<"Граф является полным - "<<boolalpha<<FullGraf()<<endl;
    IncidentRebra();
}
