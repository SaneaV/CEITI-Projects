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

void fill_Array(int* const arr, const int size)
{
    for(int i=0; i<size; i++)
        arr[i] = rand()%9;
}

void show_Array(const int* const arr, const int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    srand(time(0));

    int SIZE = 5;
    input_Size(SIZE);
    int *arr = new int[SIZE];

    fill_Array(arr, SIZE);
    show_Array(arr, SIZE);
    delete [] arr;

    return 0;
}
