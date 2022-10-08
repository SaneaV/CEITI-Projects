//Дана прямоугольная матрица вещественных чисел размером N*M (N,M- вводим с клавиатуры).
//Требуется заменить минимальный элемент в каждой строке матрицы на противоположный по знаку. 

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


    int pmin = 0;
    int min = A[0][0];

    for(int i=0; i<n; i++)
    {
        min = A[i][0];
        pmin = 0;
        for(int j=0; j<m; j++)
        {

            if(min>A[i][j])
            {
                min=A[i][j];
                pmin=j;
            }
        }
        A[i][pmin] = A[i][pmin]*(-1);
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
