#include <iostream>

using namespace std;

void InputArray(int *&Array, const int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>Array[i];
    }
}

void ShowArray(const int *Array, const int n)
{
    for(int i=0; i<n; i++)
        cout<<Array[i]<<" ";
}

int tempA[20];
int k = 0;

void heapify(int *Array, const int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && Array[l] > Array[largest])
        largest = l;

    if (r < n && Array[r] > Array[largest])
        largest = r;

    if (largest != i)
    {
        swap(Array[i], Array[largest]);
        heapify(Array, n, largest);
    }
}

void heapifylow(int *Array, const int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l > n && Array[l] < Array[largest])
        largest = l;

    if (r > n && Array[r] < Array[largest])
        largest = r;

    if (largest != i)
    {
        swap(Array[i], Array[largest]);
        heapify(Array, n, largest);
    }
}

void heapSort(int *Array,const int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(Array, n, i);
    }


    for (int i = n - 1; i >= 0; i--)
    {
        tempA[k++] = Array[0];
        ShowArray(Array, n);
        cout<<"     ";
        ShowArray(tempA,k);
        cout<<endl;

        swap(Array[0], Array[i]);
        heapify(Array, i, 0);
    }
}

void heapSortLow(int *Array,const int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifylow(Array, n, i);
    }


    for (int i = 0; i <= n - 1; i++)
    {
        tempA[k++] = Array[i];
        ShowArray(Array, n);
        cout<<"     ";
        ShowArray(tempA,k);
        cout<<endl;

        swap(Array[0], Array[i]);
        heapifylow(Array, i, 0);
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;
    cout<<"Введите размер массива: ";
    cin>>n;

    int *Array = new int [n];
    InputArray(Array, n);
    cout<<endl;
    cout<<"Начальный массив: ";
    ShowArray(Array, n);
    cout<<endl;
    heapSort(Array, n);
    cout<<endl;
    k = 0;
    heapSortLow(Array, n);
    return 0;
}
