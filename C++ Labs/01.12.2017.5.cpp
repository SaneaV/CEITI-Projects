//Дана матрица А(n,m). Определить количество отрицательных элементов матрицы в каждой строке

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
    cout<<"Введите количство столбцов: ";
    cin>>m;

    int x[n][m];
    int k=0;

    for (int i=0;i<n;i++)
    {
        k=0;
        for (int j=0;j<m;j++)
            {
                cout<<"Введите число: ";
                cin>>x[i][j];
                if (x[i][j]<0) k++;
            }
            cout<<endl<<"В "<<i<<" строке: "<<k<<" отрицательных элемента/ов."<<endl<<endl;

    }

system ("Pause");
}
