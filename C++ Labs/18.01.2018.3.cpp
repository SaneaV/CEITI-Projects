//сортировка методом выбора

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"¬ведите количество элементов в массиве: ";
    int n;
    cin>>n;

    int x[n];

    for (int i=0; i<n; i++)
        cin>>x[i];

    int c=0;
    int pmin=0;

    for (int j=0; j<n-1; j++)
    {
        pmin=j;
        for (int i=j+1; i<n; i++)

            if (x[i]<x[pmin])
        pmin=i;

        c=x[j];
        x[j]=x[pmin];
        x[pmin]=c;

    }



    for (int i=0; i<n; i++)
        cout<<x[i]<<" ";
}

