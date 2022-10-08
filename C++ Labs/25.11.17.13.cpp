/*
Вывести матрицу:
n n-1 n-2 n-3 n-4 n-5 1
1 n n-1 n-2 n-3 n-4 . 2
1 1 n n-1 n-2 n-3 ... 3
1 1 1 n n-1 n-2 ..... 4
1 1 1 n n-1 ......... 5
1 1 1 1 n ........... 6
*/


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

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (i==j) mat[i][j]=n;
            else if (j<i) mat[i][j]=1;
            else (mat[i][j]=n+i-j);
        }
    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            cout<<mat[i][j]<<"\t";
        cout<<endl;
    }






}
