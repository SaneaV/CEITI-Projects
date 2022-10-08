//Подсчитать количество чётных чисел в строке матрицы

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
    int chet;
    for (int i=0; i<n; i++)
    {
        chet=0;
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>x[i][j];
            if(x[i][j]%2==0) chet++;
        }
        cout<<"В этой строке чётных чисел: "<<chet<<endl;
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<x[i][j]<<"\t";
        cout<<endl;
    }
}
