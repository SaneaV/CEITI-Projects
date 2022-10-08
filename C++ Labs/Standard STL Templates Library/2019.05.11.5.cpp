#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int rows = 4;
    int cols = 5;

    int **arr = new int *[rows];
    for(int i=0; i<rows; i++)
    {
        arr[i] = new int[cols];
    }

    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            arr[i][j]=10+rand()%20;

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
            cout<<arr[i][j]<<"\t";
        cout<<endl;
    }

    for(int i=0; i<rows; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
    return 0;
}
