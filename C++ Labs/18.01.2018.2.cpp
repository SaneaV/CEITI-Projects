//Усовершенствованная сортировка пузырьком

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"Введите количество элементов в массиве: ";
    int n;
    cin>>n;

    int x[n];

    for (int i=0; i<n; i++)
        cin>>x[i];

    int c=0;

    bool y=false;

int k=0;

    do
    {
        y=false;
        for (int i=0; i<n; i++)
        {
            if (x[i]>x[i+1])
            {
                c=x[i];
                x[i]=x[i+1];
                x[i+1]=c;
                y=true;
            }
        }
        k++;
    }
    while (y);
    cout<<endl<<--k<<endl<<endl;

        for (int i=0; i<n; i++)
            cout<<x[i]<<" ";
}

