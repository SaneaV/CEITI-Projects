//—ортировка пузырьком

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"¬ведите количество элементов в массиве: ";
    int n;
    cin>>n;

    int x[n];

    for (int i=0; i<n; i++)
        cin>>x[i];

    int c=0;

    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (x[j]>x[j+1])
            {
                c=x[j];
                x[j]=x[j+1];
                x[j+1]=c;
            }
        }
    }

    for (int i=0; i<n; i++)
        cout<<x[i]<<" ";
}
