//Дана матрица, минимальный элемент поместить в правый верхний угол

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
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число матрицы для "<<i<<" строчки "<<j<<" столбца: ";
            cin>>mat[i][j];
        }
    }

    int p=0,q=0;
    int x=INT_MAX;
    for (int i=0;i<n;i++)
    {

        for (int j=0;j<m;j++)
        {
            if (mat[i][j]<x) {x=mat[i][j];p=i;q=j;}
        }
    }

    int t=0;
    for (int i=0;i<n;i++)
    {
            t=mat[0][m-1];
            mat[0][m-1]=mat[p][q];
            mat[p][q]=t;}

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            cout<<mat[i][j]<<"\t";
        cout<<endl;
    }




}
