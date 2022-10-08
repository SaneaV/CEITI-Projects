//Дана матрица А(n,m). Подсчитать количество элементов больше чем X (X - вводится с клавиатуры)

#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n,m;

    cout<<"Введите количество строк: ";
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;

    int mat[n][m];

    int x;

    cout<<"Введите значение \"X\": ";
    cin>>x;

    cout<<endl;

    int k=0;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
                cin>>mat[i][j];
                if (mat[i][j]>x) k++;
            }
    }

                cout<<endl;

                for (int i=0;i<n;i++)
            {
                for (int j=0;j<m;j++)
                cout<<mat[i][j]<<"\t";
                cout<<endl;
            }

                cout<<endl<<"Количество чисел, больше чем ваше ( \"X\" = "<<x<<" ): "<<k<<endl;


                        system("PAUSE");
        }
