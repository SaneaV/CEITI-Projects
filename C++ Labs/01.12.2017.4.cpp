//В двумерном массиве подсчитать количество элементов, меньших, чем среднее арефмитическое

#include<iostream>
#include<windows.h>
#include<stdlib.h>

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

    int x[n][m];
    int S=0;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>x[i][j];
            S+=x[i][j];
        }
    }


    S/=(n*m);
    int k=0;

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (x[i][j]<S) k++;
    cout<<endl<<"Чисел, которые больше чем среднее арефмитическое всех чисел: "<<k;

    system ("Pause");
}
