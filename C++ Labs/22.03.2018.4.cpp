//Используя подпрограммы составить программу.
//Дан одномерный массив, выполнить циклический сдвиг влево

#include <iostream>

using namespace std;

void InputArray (int x[20], int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>x[i];

    }
}

void SortArray (int x[20],int n)
{

    int c;
    for (int i=0; i<n; i++)
    {
        if (i==0)
            c=x[i];
        x[i]=x[i+1];
        if (i==n-1)
            x[i]=c;
    }
}

void ShowArray (int x[20],int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<x[i]<<" ";
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");
    cout<<"Введите размер массива: ";
    int m;
    cin>>m;

    int a[20];

    cout<<"Ввод матрицы: "<<endl;
    InputArray(a,m);
    SortArray(a,m);
    cout<<"\n\nВывод матрицы: "<<endl;
    ShowArray(a,m);


}
