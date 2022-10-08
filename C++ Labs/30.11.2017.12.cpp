//Найти среднее арефмитическое положительных элементов каждого столбца матрицы

#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n,m;
    cout<<"Введите количество строк: ";
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;

    cout<<endl;
    int mat[n][m];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>mat[i][j];

        }

        cout<<endl;
    int S=0,k=0;
    for (int j=0; j<m; j++)
    {
        S=0;
        k=0;
        for (int i=0; i<n; i++)
        {
            if (mat[i][j]>0)
            {
                S+=mat[i][j];
                k++;
            }
        }
        cout<<"Среднее арифметическое "<<j<<" столбца: "<<S/k<<endl;
    }

    cout<<endl;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<mat[i][j]<<"\t";
        cout<<endl;
    }

    cout<<endl;
    system ("PAUSE");


}
