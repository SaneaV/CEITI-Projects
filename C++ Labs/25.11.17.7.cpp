//Даны две матрицы, найти их среднее геометрическое

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

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<"Введите число матрицы для "<<i<<" строчки "<<j<<" столбца: ";
            cin>>mat[i][j];
        }
    }

    cout<<"\n\nВторая матрица:"<<endl;
    int mat1[20][20];


    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число матрицы для "<<i<<" строчки "<<j<<" столбца: ";
            cin>>mat1[i][j];
        }
    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            mat1[i][j]=sqrt(mat1[i][j]*mat[i][j]);

        }
    }

    cout<<"\n\nСреднее геометрическое: "<<endl;
        for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            cout<<mat1[i][j]<<"\t";
            cout<<endl;

    }

}
