//Количество положительных элементов матрицы

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
    int k=0;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<"Введите число матрицы для "<<i<<" строчки "<<j<<" столбца: ";
            cin>>mat[i][j];
            if (mat[i][j]>0) k++;
        }
    }
cout<<"Количество положительных элементов: "<<k;

}
