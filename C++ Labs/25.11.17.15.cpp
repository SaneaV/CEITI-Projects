//Минимальный элемент матрицы поместить в левый нижний угол

#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");
    cout<<"Введите количество строк: ";
    int n,m,mat[20][20];
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;
//Ввод матрицы:
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            mat[i][j]=rand()%100;
        }
    }

//Поиск самаого минимального числа матрицы:
    int p=0,q=0;
    int min=mat[0][0];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (mat[i][j]<min)
            {
                min=mat[i][j];
                p=i;
                q=j;
            }
        }
    }
//Меняем местами

    int temp;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        temp = mat[n-1][0];//Запоминаем положение левого нижнего угла
        mat[n-1][0] = mat[p][q];//В левый нижний угол вставляем наш минимальный элемент
        mat[p][q] =temp;//На места, где находился минимальный элемент вставляем элемент левого нижнего угла
    }

//Выводим матрицу
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<mat[i][j]<<"\t";
        cout<<endl;
    }




}
