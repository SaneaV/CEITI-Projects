//Заменить чётные числа на 0 и нечётные на 1

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
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>x[i][j];
            if (x[i][j]%2==0) x[i][j]=0;
            else (x[i][j]=1);
        }
    }

    for (int i=0;i<n;i++)
    {
      for (int j=0;j<m;j++)
        cout<<x[i][j]<<"\t";
      cout<<endl;
    }

}
