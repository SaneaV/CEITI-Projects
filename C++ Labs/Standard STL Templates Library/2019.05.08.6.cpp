#include <iostream>

using namespace std;

template <typename t>
void Filling(t &arr, const int &n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Input number: ";
        cin>>arr[i];
    }
}

template <typename t>
void Print(t *arr)
{
    for(auto i : *arr)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    int const SIZE = 10;
    int arr[SIZE];

    Filling(arr, SIZE);
    Print(&arr);


    return 0;
}
