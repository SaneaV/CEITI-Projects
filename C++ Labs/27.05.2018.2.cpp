//”совершенствованна€ сортировка пузырьком

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

    bool y=false;
    do
    {
        y=false;
        for (int i=0; i<n-1; i++)
        {
            if(a[i]>a[i+1])
            {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                y=true;
            }
        }
    }
    while (y);



    cout<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
