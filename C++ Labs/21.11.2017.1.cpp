//Ввод/вывод матрицы

#include <iostream>

using namespace std;

main()
{
    setlocale (0,"");
    int n=0,m=0,x[10][30];
    cout<<"Введите N: ";
    cin>>n;
    cout<<"Введите M: ";
    cin>>m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<"Введите число: ";
            cin>>x[i][j];
        }

    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout<<x[i][j]<<"\t";
            cout<<endl;
    }
}
