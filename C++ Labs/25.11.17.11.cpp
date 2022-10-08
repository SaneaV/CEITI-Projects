//Среднее арифметическое строки матрицы

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

   int S=0;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число матрицы для "<<i<<" строчки "<<j<<" столбца: ";
            cin>>mat[i][j];
        }
    }

    for (int i=0;i<n;i++)
    {S=0;
        for (int j=0;j<m;j++)
           {
              S+=mat[i][j];
              }
              S/=n;
           cout<<"В "<<i<<" строке среднее арефмитическое: "<<S<<endl;
    }


}
