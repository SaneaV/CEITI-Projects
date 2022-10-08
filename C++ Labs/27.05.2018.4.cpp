//Сортировка методом вставки

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


    for (int i=1;i<n;i++)
    {
        int j=i;
        while (a[j]<a[j-1] and j>0)
        {
            int c = a[j];
            a[j] = a[j-1];
            a[j-1] = c;
            j--;
        }
    }


    cout<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
