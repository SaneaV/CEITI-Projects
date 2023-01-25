#include <iostream>

using namespace std;

void InputArray(int *&Array, int const n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>Array[i];
    }
}

void ShowArray(int const *Array, int const n)
{
    for(int i=0; i<n; i++)
        cout<<Array[i]<<" ";

    cout<<endl;
}

void QuickSort(int *Array, int first, int last)
{
    int Middle, Count;
    int f=first, l=last;
    Middle=Array[(f+l) / 2];

    do
    {
        while (Array[f]<Middle)
            f++;
        while (Array[l]>Middle)
            l--;
        if (f<=l)
        {
            Count=Array[f];
            Array[f]=Array[l];
            Array[l]=Count;
            f++;
            l--;
        }
    }while (f<l);


    if (first<l)
        QuickSort(Array, first, l);
    if (f<last)
        QuickSort(Array, f, last);
}

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;
    cout<<"Введите количество чисел в массиве: ";
    cin>>n;

    int *Array = new int [n];

    InputArray(Array, n);
    cout<<endl;
    ShowArray(Array,n);
    QuickSort(Array,0, n-1);
    ShowArray(Array,n);
}
