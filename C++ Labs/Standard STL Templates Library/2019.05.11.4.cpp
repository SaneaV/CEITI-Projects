#include <iostream>
#include <stdlib.h>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    srand(time(NULL));

    int SIZE = 10;
    cout<<"Input array size: ";
    cin>>SIZE;

    int *arr = new int[SIZE];

    for(int i=0; i<SIZE; i++)
        arr[i] = rand()%10;


    for(int i=0; i<SIZE; i++)
    {
        cout<<arr[i]<<"\t";
        cout<<arr+i<<endl;
    }

    delete [] arr;

    return 0;
}
