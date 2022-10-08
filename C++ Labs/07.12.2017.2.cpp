//Дана прямоугольная матрица целых чисел размером N*M (N,M- вводим с клавиатуры).
//Поменять местами в каждой строке первый отрицательный и последний положительный элементы.

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL,"Russian");

    cout<<"Введите n: ";
    int n,m;
    cin>>n;
    cout<<"Введите m: ";
    cin>>m;

    int mat[50][50];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            cin>>mat[i][j];
        }

    int min=mat[0][0];

    for (int i=0; i<n; i++)
    {
        min=mat[i][0];
        int q=0,p=0;
        for (int j=0; j<m; j++)
        {
            if (min>=mat[i][j])
            {
                min=mat[i][j];
                p=i;
                q=j;
            }
        }
        mat[p][q]=mat[p][q]*-1;
    }


    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<mat[i][j]<<"\t";
        cout<<endl;
    }

}
