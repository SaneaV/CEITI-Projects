//Сортировка вставками

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL, "RUS");

    int n;
    cout<<"Введите количество чисел: ";
    cin>>n;

    int mat[30];

    for (int i=0;i<n;i++)
    {
        cout<<"Введите число: ";
        cin>>mat[i];
    }

    for (int i=1;i<n;i++)
    {
        int j=i-1;
        int c=mat[i];
        while (c>mat[j] and j>=0)
        {
            mat[j+1]=mat[j];
            --j;
        }
        mat[j+1]=c;
    }

    for (int i=0;i<n;i++)
    {
        cout<<mat[i]<<" ";
    }
}
