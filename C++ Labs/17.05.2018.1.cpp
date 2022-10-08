//»спользу€ функцию: ¬вести массив, вывести, отсортировать пузырьком.

#include <iostream>
#include <windows.h>

using namespace std;

void InputArray (int *Array, int &n)
{
    for (int i=0;i<n;i++)
    {
        cout<<"¬ведите число: ";
        cin>>Array[i];
    }
}

void ShowArray (int *Array, int &n)
{
    for (int i=0;i<n;i++)
    {
        cout<<Array[i]<<" ";
    }
}

void SortArray (int *Array, int &n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-1-i;j++)
        {
            if (Array[j]>Array[j+1])
            {
                int t = Array[j];
                Array[j] = Array[j+1];
                Array[j+1]=t;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");
    int n;

    cout<<"¬ведите количество чисел в массиве: ";
    cin>>n;

    int *Array = new int [n];

    InputArray(Array,n);
    system("cls");
    ShowArray(Array,n);
    cout<<endl<<endl;
    SortArray(Array,n);
    ShowArray(Array,n);


}
