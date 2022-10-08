#include <iostream>
#include <stdlib.h>
#include <ctime>

using std::endl;
using std::cout;
using std::cin;

void input_Size(int &size)
{
    cout<<"Input size: ";
    cin>>size;
}

template <typename T>
void fill_Array(T* const arr, const int &size)
{
    for(int i=0; i<size; i++)
        arr[i] = rand()%9;
}

template <typename T>
void show_Array(const T* const arr, const int &size)
{
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

template <typename T>
void copy_Array(const T* const arr1, T *&arr2, const int size1, int &size2)
{
    delete [] arr2;

    size2 = size1;
    arr2 = new int[size2];

    for(int i=0; i<size2; i++)
    {
        arr2[i]=arr1[i];
    }
}

int main()
{
    srand(time(0));

    int SIZE1 = 5;
    int SIZE2 = 5;

    input_Size(SIZE1);
    input_Size(SIZE2);

    int *arr1 = new int[SIZE1];
    int *arr2 = new int[SIZE2];

    cout<<endl;
    cout<<"First array: ";
    fill_Array(arr1, SIZE1);
    show_Array(arr1, SIZE1);

    cout<<endl;
    cout<<"Second array: ";
    fill_Array(arr2, SIZE2);
    show_Array(arr2, SIZE2);

    cout<<endl<<endl;
    cout<<"First array copy in second array: ";
    copy_Array(arr1, arr2, SIZE1, SIZE2);
    show_Array(arr2, SIZE2);


    delete [] arr1;
    delete [] arr2;

    return 0;
}
