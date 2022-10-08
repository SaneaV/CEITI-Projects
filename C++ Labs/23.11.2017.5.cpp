//Даны две матрицы(двумерных массива) A(n,m) и B(n,m).
//Составить матрицу C(n,m) следующим образом: Cij=среднее арифметическое(Aij+Bij).

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
    int b[n][m];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>a[i][j];
        }
    }
    cout<<"\n\nВвод второй матрицы: "<<endl;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>b[i][j];
        }

    }

    float c[n][m];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            c[i][j]=((a[i][j]+b[i][j])/2.0);
        }

    }




    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }

    cout<<"\n\n";

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<b[i][j]<<"\t";
        cout<<endl;
    }

    cout<<"\n\n";

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<c[i][j]<<"\t";
        cout<<endl;
    }
}
