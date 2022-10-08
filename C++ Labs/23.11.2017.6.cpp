//Минимальный элемент матрицы поместить в левый правый угол

#include <iostream>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");
    cout<<"Введите n: ";
    int n, a[20][20],m;
    cin>>n;
    cout<<"Введите m: ";
    cin>>m;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {cout<<"Введите число: ";
        cin>>a[i][j];}
    }

    int i=0,j=0, p=0,q=0;
    int min=a[i][j];
        for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {if (a[i][j]<min) {min=a[i][j];p=i;q=j;}}
    }

        int temp;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            temp = a[0][0];
            a[0][0] = a[q][p];
            a[p][q] =temp;
        }


        for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        cout<<a[i][j]<<"\t";
        cout<<endl;
    }

}
