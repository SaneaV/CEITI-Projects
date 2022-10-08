//Номер столбца с первым нулём на нулевой позиции

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    int n,m;

    cout<<"Количество строк: ";
    cin>>n;
    cout<<"Количество столбцов: ";
    cin>>m;

    int a[20][20];

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>a[i][j];
        }
    }

    int s=0;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (a[i][j]==0)
            {
                s=j;
                i=n;
                j=m;
            }
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }

    cout<<endl<<"Столбец с первым нулём: "<<s+1;
}
