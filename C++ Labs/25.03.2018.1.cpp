//¬вод, вывод и сортировка матрицы при использовании функций

#include <iostream>
#include <windows.h>

using namespace std;

void InputArray (int x[20][20], int &n, int &m)
{
    cout<<"¬ведите количество строк: ";
    cin>>n;
    cout<<"¬ведите количество столбцов: ";
    cin>>m;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"¬ведите число: ";
            cin>>x[i][j];
        }
    }
}

void OutputArray (int x[20][20], int &n, int &m)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<x[i][j]<<" ";
        cout<<endl;
    }
}

void SortArray (int x[20][20], int &n, int &m)
{
    int c;
    for (int i=0; i<n; i++)
    {
        for (int t=0; t<m-i-1; t++)
        {
            if (x[i][t]>x[i][t+1])
            {
                for (int q=0; q<m; q++)
                {
                    c=x[q][t];
                    x[q][t]=x[q][t+1];
                    x[q][t+1]=c;
                }
            }
        }
    }

}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int FirstArray[20][20];
    int SecondArray[20][20];
    int n1,m1;

    InputArray(FirstArray, n1, m1);
    cout<<"\n\n";
    InputArray(SecondArray, n1, m1);
    cout<<"\n\n";

    OutputArray(FirstArray, n1, m1);
    cout<<"\n\n";
    OutputArray(SecondArray, n1, m1);
    cout<<"\n\n";

    SortArray(FirstArray, n1, m1);
    SortArray(SecondArray, n1,m1);

    OutputArray(FirstArray, n1, m1);
    cout<<"\n\n";
    OutputArray(SecondArray, n1, m1);
    cout<<"\n\n";


}
