// C++ program to perform TimSort.
#include<bits/stdc++.h>
#include <IOSTREAM>
using namespace std;
const int RUN = 32;

// utility function to print the Array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int globaln = 3*5;

// this function sorts array from left index to
// to right index which is of size atmost RUN
void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

// merge function merges the sorted runs
void merge(int arr[], int l, int m, int r)
{
    // original array is broken in two parts
    // left and right array
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    // after comparing, we merge those two array
    // in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    // copy remaining element of right, if any
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }

}


// iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void timSort(int arr[], int n)
{
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
    {

        insertionSort(arr, i, min((i+31), (n-1)));
    }



    // start merging from size RUN (or 32). It will merge
    // to form size 64, then 128, 256 and so on ....
    for (int size = RUN; size < n; size = 2*size)
    {


        // pick starting point of left sub array. We
        // are going to merge arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we increase left by 2*size
        for (int left = 0; left < n; left += 2*size)
        {

            // find ending point of left sub array
            // mid+1 is starting point of right sub array
            int mid = left + size - 1;
            int right = min((left + 2*size - 1), (n-1));

            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            cout<<"G"<<" "<<globaln;
            merge(arr, left, mid, right);
        }
    }

}



void printMatrix(int matrix[10][10], int nM, int mM)
{
    for(int i=0; i<nM; i++)
    {
        for(int j=0; j<mM; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

void MassivToMatrix(int matrix[10][10], int nM, int mM, int arr[])
{
    int k=0;
    for(int i=0;i<nM;i++)
        for(int j=0;j<mM;j++)
    {
        matrix[i][j] = arr[k++];
    }
}

// Driver program to test above function
int main()
{
    setlocale(LC_ALL,"RUS");
    int matrix[10][10] = {{5, 4, 7},
                          {8, 9, 10,},
                          {23, 15, 6},
                          {3, 11, 36},
                          {19, 20, 55}};

    int nM = 5;
    int mM = 3;
    cout<<"Начальная матрица: "<<endl;
    printMatrix(matrix, nM, mM);
    printf("\n");

    int arr[] = {5,4,7,8,9,10,23,15,6,3,11,36,19,20,55};

    int n = 5*3;
    printf("Числа из массива в матрицу: ");
    printArray(arr, n);

    timSort(arr, n);

    printf("Отсортированный массив: ");
    printArray(arr, n);

    cout<<endl<<endl;

    MassivToMatrix(matrix, nM, mM, arr);
    cout<<"Конечная матрица°: "<<endl;
    printMatrix(matrix, nM, mM);
    return 0;
}
