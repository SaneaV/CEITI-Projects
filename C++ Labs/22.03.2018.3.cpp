//Используя подпрограммы составить программу. Даны две матрицы A(n,m) и B(n,m).
//Составить матрицу C(n,m), следующим образом:
//C(i,j)=среднее геометрическое A(i,j) и B(i,j)

#include <iostream>
#include <cmath>

using namespace std;

void InputArray (int x[20][20],int n, int m)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cout<<"Введите число: ";
            cin>>x[i][j];
        }
    }
}

void ShowArray (int x[20][20], int n, int m)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            cout<<x[i][j]<<" ";
        cout<<endl;
    }
}

void CArray(int x[20][20], int y[20][20], int z[20][20], int n, int m)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            z[i][j]=sqrt(x[i][j]*y[i][j]);
        }
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");
    int n1,m1;
    int a[20][20];
    int b[20][20];
    int d[20][20];

    cout<<"Введите количество строк: ";
    cin>>n1;
    cout<<"Введите количество столбцов: ";
    cin>>m1;

    cout<<"\nВвод первой матрицы: "<<endl;
    InputArray(a,n1,m1);
    cout<<"\nВвод второй матрицы: "<<endl;
    InputArray(b,n1,m1);

    cout<<"\nВывод первой матрицы: "<<endl;
    ShowArray(a,n1,m1);
    cout<<"\nВывод первой матрицы: "<<endl;
    ShowArray(b,n1,m1);

    cout<<"\nИх среднее геометрическое: "<<endl;
    CArray(a,b,d,n1,m1);
    ShowArray(d,n1,m1);


}
