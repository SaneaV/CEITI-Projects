//Количество отрицательных элементов в строке матрицы

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


        for (int i=0;i<n;i++)
    {
        int k=0;
        for (int j=0;j<m;j++)
        if (a[i][j]<0) k++;
        cout<<"\n\nКоличество отрицательных чисел в "<<i<<" строке: "<<k<<endl;

    }

        for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        cout<<a[i][j]<<"\t";
        cout<<endl;
    }

}
