//Дана прямоугольная матрица вещественных чисел размером N*M (N,M- вводим с клавиатуры).
//Требуется увеличить в два раза все числа в тех строках матрицы, которые содержат только положительные числа. 

#include<iostream>
using namespace std;
int main()
{
    setlocale (0,"");
    int a[25][30];
    int n,m,i,j;
    int pi;
    bool plus;
    cout<<"Введите строки: "<<endl;
    cin>>n>>m;
    cout<<"Введите матрицу: " <<endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];


    for(i=0; i<n; i++)
    {
        plus = true;

        for(j=0; j<m; j++)
            if (a[i][j] <0)
                plus = false;

        if (plus)
        {
            pi = i;
            for (int i = pi, j = 0; j < m; j++)
                a[i][j]=a[i][j]*2;

        }
    }

    for (int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }

}
