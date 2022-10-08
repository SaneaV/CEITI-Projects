//Даны две матрицы, составить третью матрицу, в которой будут максимальные элементы двух матриц

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");
    cout<<"Введите количество строк: ";
    int n,m,a[20][20],b[20][20],c[20][20];
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;

    cout<<"Первая матрица: "<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<"Введите число матрицы для "<<i<<" строчки "<<j<<" столбца: ";
            cin>>a[i][j];
        }
    }

    cout<<"\n\nВторая матрица: "<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число матрицы для "<<i<<" строчки "<<j<<" столбца: ";
            cin>>b[i][j];
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (a[i][j]>=b[i][j]) c[i][j]=a[i][j];
                else c[i][j]=b[i][j];
        }
    }
cout<<"\n\nТретья матрица (состоящая из максимальных элементов первой и второй матрицы): "<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)

            cout<<c[i][j]<<"\t";
            cout<<endl;

    }






}
