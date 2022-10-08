//Рекурсивный ввод массива, сортировка пузырьком, рекурсивный вывод
//Рекурсивная: сумма, произведение, количество, поиск максимума
//Выборочная сортировка

#include <iostream>
#include <limits.h>

using namespace std;

void InputArray(int A[], int n)
{
    if (n==1)
    {
        cout<<"Введите число: ";
        cin>>A[0];
    }

    else
    {
        InputArray(A,n-1);
        cout<<"Введите число: ";
        cin>>A[n-1];
    }
}

void SortArray(int A[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1-i; j++)
        {
            if (A[j]<A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void ShowArray (int A[], int n)
{
    if (n==1)
    {
        cout<<A[0]<<" ";
    }
    else
    {
        ShowArray(A,n-1);
        cout<<A[n-1]<<" ";
    }
}

int Sum (int A[], int n)
{

    if (n==0)
    {
        return 0;
    }
    else
    {
        return Sum(A,n-1)+A[n-1];
    }
}

int MoreZero (int A[], int n)
{
    if (n==0)
        return 0;
    else if (A[n-1]>0)
        return MoreZero(A,n-1)+1;
    else
        MoreZero(A,n-1);
}

int Proizvedenie (int A[], int n)
{
    if (n==0)
        return 1;
    else
        return Proizvedenie(A,n-1) * A[n-1];
}

int Max (int A[], int n)
{
    int max = n-1;
    if (n==1)
        return A[max];

    else if (A[max]>A[max-1])
    {
        A[max] = A[max-1];
    }
    return
        Max(A,n-1);
}


void SortArraySelect(int A[], int n)
{
    for (int i=0; i<n;i++)
    {
        int pmin=i;
        for (int j=i+1;j<n;j++)
            if (A[j]<A[pmin])
            pmin = j;

        int temp = A[pmin];
        A[pmin] = A[i];
        A[i] = temp;
}
}
