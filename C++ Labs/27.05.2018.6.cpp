//Сортировка методом подсчёта №2

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


    for (int i=0; i<n; i++)
    {
        b[i]=-1;//Так как все элементы больше, либо равны нулю
    }

    for (int i=0; i<n; i++)
    {
        int k=0,t=0;
        for (int j=0; j<n; j++)
        {
            if (a[i]>a[j])
                k++;
            if (a[i]==a[j])
                t++;
        }
        t--;
        if (b[k]==-1)
        {
            for (int j=k; j<=k+t; j++)
            {
                b[j]=a[i];
            }
        }
    }


    cout<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}
