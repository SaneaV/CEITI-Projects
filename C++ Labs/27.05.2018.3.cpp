//Сортировка методом выбора

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    cout<<"Введите количество чисел: ";
    int n;
    cin>>n;

    int *a = new int [n];

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

    for (int i=0; i<n-1; i++)
    {
        int pmin=i;
        for (int j=i+1; j<n; j++)
            if (a[j]<a[pmin])
                pmin=j;

        int temp = a[i];
        a[i]=a[pmin];
        a[pmin]=temp;

    }



    cout<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
