//—умма отрицательных чисел в матрице

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");
    cout<<"¬ведите n: ";
    int n, a[20][20],m;
    cin>>n;
    cout<<"¬ведите m: ";
    cin>>m;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {cout<<"¬ведите число: ";
        cin>>a[i][j];}
    }

    int S=0;
        for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {if (a[i][j]<0) S+=a[i][j];}
    }

        for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        cout<<a[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"\n\n\n—умма отрицательных чисел: "<<S<<"\n\n";

}
