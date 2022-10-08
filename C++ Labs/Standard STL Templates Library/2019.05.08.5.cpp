#include <iostream>

using namespace std;

main()
{
    int const SIZE = 5;
    int arr[SIZE] = {1,2,3,4,5};

    for(int i=0;i<SIZE;i++)
    {
        cout<<*(arr+i)<<" ";
    }

    cout<<endl<<endl;

    for(int i=0;i<SIZE;i++)
    {
        cout<<arr+i<<endl;
    }
}
