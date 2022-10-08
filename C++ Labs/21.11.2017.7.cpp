//Две матрицы А и В, суммировать из в матрице С
#include <iostream>

using namespace std;

main()
{
    setlocale (0,"");
    int n=0,m=0,a[20][20],b[20][20],c[20][20];
    cout<<"Введите N: ";
    cin>>n;
    cout<<"Введите M: ";
    cin>>m;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>a[i][j];
        }
    }
    cout<<"\n\nДля второй матрицы: \n\n"<<endl;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>b[i][j];
        }
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }


    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<c[i][j]<<"\t";
            cout<<endl;
    }
}
