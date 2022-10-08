//Ввод/Вывод матрицы, сумма каждого числа

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
    int S=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>x[i][j];
            S+=x[i][j];
        }

    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<x[i][j]<<"\t";
            cout<<endl;
    }

    //Можно произвести подсчёт прямо в первом цикле
    //for (int i=0;i<n;i++)
       // for (int j=0;j<m;j++)
           //S+=x[i][j];
    cout<<"Ответ: "<<S;
}
