//Матрицу превратить в одномерный массив и записать максимальные числа из строк


#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");
    cout<<"Введите количество строк: ";
    int n,m,mat[20][20];
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;


    int a[20],sc=0;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<"Введите число матрицы для "<<i<<" строчки "<<j<<" столбца: ";
            cin>>mat[i][j];

        }
    }

    for (int i=0;i<n;i++)
    {
        int min=INT_MIN;
        sc++;
        for (int j=0;j<m;j++)
        {
        if (mat[i][j]>min) {min=mat[i][j];a[i]=mat[i][j];}
        }

    }

    for (int i=0;i<sc;i++)
    {
        cout<<a[i]<<" ";
    }

}
