//Сортировка методом вставок

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"Введите количество элементов в массиве: ";
    int n;
    cin>>n;

    int x[n];

    for (int i=0; i<n; i++)
        cin>>x[i];

    int c=0;
    int j;


    for (int i=1; i<n; i++)
    {
        j=i;

            while (x[j]<x[j-1] and j>0)
            {
                c=x[j];
                x[j]=x[j-1];
                x[j-1]=c;
                j--;
            }
    }

    for (int i=0; i<n; i++)
        cout<<x[i]<<" ";
}

