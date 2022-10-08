//Дана целочисленная прямоугольная матрица. Найти номер первого из столбцов, не содержащих ни одного отрицательного элемента. 

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int n,m;
    cout<<"Введите количество строк: ";
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;

    int **A=new int *[n];
    for (int i=0; i<n; i++)
        A[i]=new int [m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>A[i][j];
        }

    system("cls");

    cout<<"Изначальный вид матрицы: "<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }

    int k = 0;
    int pk = 0;

    for(int j=0; j<m; j++)
    {
        k=0;
        for(int i=0; i<n; i++)
        {
            if(A[i][j]<0)
                k++;
        }
        if(k==0)
        {
            pk=j;
            j=m;
        }

    }

    cout<<"Номер первого из столбцов без отрицательного числа: "<<pk+1<<endl;

    cout<<endl<<endl;

    cout<<"Конечный вид матрицы: "<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }

}

