//Матрицу превратить в одномерный массив и записать максимальные числа из строк
#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (0,"");
    int n=0,m=0,a[20][20];
    cout<<"Введите N: ";
    cin>>n;
    cout<<"Введите M: ";
    cin>>m;
    int x[20];
    int min;
    int k=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>a[i][j];
        }

    }
    for (int i=0; i<n; i++)
    {
        min=a[i][0];
        k++;
        for (int j=0; j<m; j++)
            if (min<abs(a[i][j]))
            {
                min=abs(a[i][j]);
                x[i]=min;
            }
    }

    cout<<"\n\n";
    for (int i=0; i<k; i++)
        {cout<<x[i]<<endl;}
    cout<<"\n\n";




    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }
}
