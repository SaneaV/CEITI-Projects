//Дана прямоугольная матрица целых чисел размером N*M (N,M- вводим с клавиатуры).
//Поменять местами первый столбец и столбец, в котором находится последний нулевой элемент.

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int n,m;
    cout<<"Введите количество строк: ";
    cin>>n;
    cout<<"Введите количество столбцов: ";
    cin>>m;

    int A[100][100];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cout<<"Введите число: ";
            cin>>A[i][j];
        }

    system("cls");

    cout<<"Изначальный вид матрицы: "<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }

    int k = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==0) k=j;
        }
    }

    int c = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j==k)
            {
                c = A[i][0];
                A[i][0] = A[i][j];
                A[i][j] = c;
            }
        }
    }

    cout<<endl<<endl;

    cout<<"Конечный вид матрицы: "<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }

}


