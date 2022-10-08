//Сортировка методом подсчёта №1

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    cout<<"Введите количество чисел: ";
    int n;
    cin>>n;

    int a[100];
    int b[100];

    for (int i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>a[i];
    }
    cout<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;


    for (int i=0;i<100;i++)
    {
        b[i]=0;
    }

    int k=0;

    for (int i=0;i<n;i++)
    {
        b[a[i]]++;
    }

    for (int i=0;i<100;i++)
    {
        for (int j=0;j<b[i];j++)
        {
            a[k]=i;
            k++;
        }
    }


    cout<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

