//Вычисление суммы главной диагонали матрицы при использовании функций, указателей и адресов.

#include <iostream>
using namespace std;
int** inputArrow (int &n)
{

    cout<<"Введите количество строк и столбцов массива: ";
    cin>>n;
     int **x=new int*[n];
    for(int i = 0; i < n; i++)
         x[i]=new int[n];
    cout<<"Введите массив: ";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        cin>>x[i][j];
        return x;
}
void showArrow (int **x, int n)
{
    cout<<"Массив: "<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout<<x[i][j]<<"\t";
        cout<<endl;
    }
}
float sum (int **x, int n)
{
    float s = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if (i == j) s+= x[i][j];
    return s;
}
int main ()
{
    int **a, m;
    setlocale (LC_ALL,"Russian");
    a=inputArrow(m);
    showArrow(a,m);
    cout<<"Сумма главной диагонали матрицы равна "<<sum(a,m);
    return 0;
}
