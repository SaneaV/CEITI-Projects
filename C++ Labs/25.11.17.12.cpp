//Матрицу превратить в одномерный массив и записать минимальные по модулю числа строк

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");
    cout<<"Введите количество строк: ";
    int n,m,mat[20][20];
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;

    int min;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число матрицы для "<<i<<" строчки "<<j<<" столбца: ";
            cin>>mat[i][j];
        }
    }

    int a[20];
    for (int i=0; i<n; i++)
    {
        min=INT_MAX;
        for (int j=0; j<m; j++)
        {
            if (min>abs(mat[i][j]))
            {
                min=mat[i][j];
                a[i]=mat[i][j];
            }
        }


    }

    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }




}
