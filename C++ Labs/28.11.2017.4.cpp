//Вычислить сумму минимального и максимального элемента

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");
    int n,m,x[20][20];
    cout<<"Введите количество строк: ";
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
    {
        cout<<"Введите число: ";
        cin>>x[i][j];
    }
    int max=x[0][0];
    int min=x[0][0];
    for (int i=0;i<n;i++)
    {
       for (int j=0;j<m;j++)
            {if (min>x[i][j]) min=x[i][j];
            if (max<x[i][j]) max=x[i][j];
            }
    }
    cout<<"Сумма максимального и минимального элемента матрицы: "<<min+max;



}
