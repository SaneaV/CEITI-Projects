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
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

template <typename t>
void push_back(t *&arr, int &size, const int value)
{
    t *temp = new t[size+1];

    for(int i=0; i<size; i++)
        temp[i] = arr[i];
    temp[size++] = value;

    delete [] arr;
    arr = new t [size];
    arr = temp;
}

template <typename t>
void pop_back(t *&arr, int &size)
{
    size--;
    t *temp = new t[size];

    for(int i=0; i<size; i++)
        temp[i]=arr[i];

    delete [] arr;
    arr = new t [size];
    arr = temp;
}

template <typename t>
void push_front(t *&arr, int &size, const int value)
{
    t *temp = new t[size+1];
    temp[0] = value;

    for(int i=0, j=1; i<size; i++, j++)
        temp[j] = arr[i];
    size++;

    delete [] arr;
    arr = new t [size];
    arr = temp;
}

template <typename t>
void pop_front(t *&arr, int &size)
{
    size--;
    t *temp = new t[size];

    for(int i=0, j=1; i<size; i++, j++)
        temp[i]=arr[j];

    delete [] arr;
    arr = new t [size];
    arr = temp;
}

template <typename t>
void push_random(t *&arr, int &size, const int value,const int position)
{
    t *temp = new t[size+1];

    for(int i=0, j=0; i<size; i++, j++)
    {
        if(j==position)
        {
            temp[j] = value;
            i--;
        }
        else
            temp[j] = arr[i];
    }
    size++;

    delete [] arr;
    arr = new t [size];
    arr = temp;
}

template <typename t>
void pop_random(t *&arr, int &size, const int position)
{
    t *temp = new t[size-1];

    for(int i=0, j=0; i<size; i++, j++)
    {
        if(i==position) j--;
        else
            temp[j]=arr[i];
    }
    --size;

    delete [] arr;
    arr = new t [size];
    arr = temp;
}


int main()
{
    srand(time(NULL));

    int SIZE = 2+rand()%9;
    //input_Size(SIZE);
    int *arr = new int[SIZE];

    fill_Array(arr, SIZE);
    show_Array(arr, SIZE);

    cout<<endl<<"Push_back: ";
    push_back(arr, SIZE, 5+rand()%5);
    show_Array(arr, SIZE);

    cout<<endl<<"Pop_back: ";
    pop_back(arr, SIZE);
    show_Array(arr, SIZE);

    cout<<endl<<"Push_front: ";
    push_front(arr, SIZE, 5+rand()%5);
    show_Array(arr, SIZE);

    cout<<endl<<"Pop_front: ";
    pop_front(arr, SIZE);
    show_Array(arr, SIZE);

    cout<<endl<<"Push_random: ";
    push_random(arr, SIZE, 5+rand()%5, 2+rand()%SIZE);
    show_Array(arr, SIZE);

    cout<<endl<<"Pop_random: ";
    pop_random(arr, SIZE, 1+rand()%SIZE);
    show_Array(arr, SIZE);


    delete [] arr;

    return 0;
}
