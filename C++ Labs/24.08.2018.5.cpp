//Дана прямоугольная матрица целых чисел размером N*M (N,M- вводим с клавиатуры).
//Поменять местами в каждой строке первый отрицательный и последний положительный элементы.

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

    int **A=new int *[n];
    for (int i=0; i<n; i++)
        A[i]=new int [m];

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

    int PFPj = 0;
    int PFPi = 0;
    int PFNi = 0;
    int PFNj = 0;

    int k=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]>=0 and k==0)
            {
                k = 1;
                PFPj = j;
                PFPi = i;
            }

            if(A[i][j]<0)
            {
                PFNj = j;
                PFNi = i;
            }
        }
    }

    int c = 0;
    c = A[PFPi][PFPj];
    A[PFPi][PFPj] = A[PFNi][PFNj];
    A[PFNi][PFNj] = c;

    cout<<endl<<endl;

    cout<<"Конечный вид матрицы: "<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }

}

