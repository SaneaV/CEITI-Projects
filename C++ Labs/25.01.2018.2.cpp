//Сортировка подсчёта №1
//Предположим, что все элементы массива меньше чем 100, но не отрицательные


#include <iostream>

using namespace std;

main()
{
    int n;
    cout<<"Vvedite kolichestov chisel: ";
    cin>>n;
    int b[100];
    int a[100];

    for (int i=0;i<n;i++)
    {
        cout<<"Vvvedite chislo: ";
        cin>>a[i];
    }

    for (int i=0;i<100;i++)
    {
        b[i]=0;
    }

    for (int i=0;i<n;i++)
    {
        b[a[i]]++;
    }

    int k=0;

    for (int i=0;i<100;i++)
    {
        for (int j=0;j<b[i];j++)
        {
            a[k]=i;
            k++;
        }
    }

    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
