//¬вод/вывод матрицы

#include <iostream>

using namespace std;

main()
{
    setlocale (0,"");
    int n=0,m=0,x[10][30];
    cout<<"¬ведите N: ";
    cin>>n;
    cout<<"¬ведите M: ";
    cin>>m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<"¬ведите число: ";
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
