//—ортировка пузырьком

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    cout<<"¬ведите количество чисел: ";
    int n;
    cin>>n;

    int *a = new int [n];

    for (int i=0; i<n; i++)
    {
        cout<<"¬ведите число: ";
        cin>>a[i];
    }
    cout<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-1-i; j++)
            if (a[j]>a[j+1])
            {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }



    cout<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
