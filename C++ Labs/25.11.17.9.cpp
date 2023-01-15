//Среднее арефмитическое матрицы

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
    int S=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            S+=mat[i][j];
        }
    }
      S/=(n*m);
    cout<<"Среднее арефмитическое матрицы: "<<S;


}
