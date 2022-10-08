//Сортировка методом подсчёта №3

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
    int c[100];

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


    for(int i=0; i<n; i++)
        b[i] = 0;

    for(int i=n-1; i>0; i--)
        for(int j=i-1; j>=0; j--)
            if (a[i] < a[j])
            b[j] = b[j]+1;
            else b[i]= b[i]+1;

    for(int i=0; i<n; i++)
    c[b[i]] = a[i];



    cout<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
}

