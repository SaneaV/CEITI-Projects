//Рекурсия. Ввод матрицы, вывод матрицы, сумма матрицы, количество чисел больше нуля, инверсия.

#include <iostream>

using namespace std;

void InputArray(int x[], int n)
{
    if(n==1)
    {
        cout<<"Введите элемент: ";
        cin>>x[0];
    }
    else
    {
        InputArray(x,n-1);
        cout<<"Введите элемент: ";
        cin>>x[n-1];
    }
}

void ShowArray (int x[], int n)
{
    if (n==1)
        cout<<x[0]<<" ";
    else
    {
        ShowArray(x,n-1);
        cout<<x[n-1]<<" ";
    }
}

int Sum (int x[], int n)
{
    if (n==0) return 0;
    else return Sum(x,n-1)+x[n-1];
}

int Kol(int x[], int n)
{
    if(n==0) return 0;
    else if (x[n-1]>0) return Kol(x,n-1)+1;
    else return Kol(x,n-1);
}

void Invers(int x[], int l, int r)
{
    int t;
    if (l<r)
    {
        t=x[r];
        x[r]=x[l];
        x[l]=t;
        Invers(x,l+1,r-1);
    }
}


int main()
{
    setlocale(LC_ALL,"RUS");
    cout<<"Введите количество элементов: ";
    int m;
    cin>>m;
    int Array[50];
    cout<<endl;
    InputArray(Array,m);
    cout<<endl;
    ShowArray(Array,m);
    cout<<endl<<"Сумма массива: "<<Sum(Array,m);
    cout<<endl<<"Количество чисел больше нуля: "<<Kol(Array,m);
    cout<<endl<<"Числа в обратном порядке: ";
    Invers(Array,0,m-1);
    ShowArray(Array,m);
}
