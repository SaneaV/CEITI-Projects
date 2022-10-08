//Последний столбец матрицы с нулём заменить на первый столбец.

#include <iostream>
#include <windows.h>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    int n,m;

    cout<<"Введите количество строк: ";
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;

    int A[n][m];

    system("cls");

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>A[i][j];
        }
    }

    cout<<endl<<endl;
    int RemeberZero;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<A[i][j]<<" ";
            if(A[i][j]==0)
                RemeberZero=j;
        }
        cout<<endl;
    }

    int RememberThirt;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if(j==RemeberZero)
            {
                RememberThirt = A[i][j];
                A[i][j] = A[i][0];
                A[i][0] = RememberThirt;
            }
        }
    }


    cout<<endl<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }

}
