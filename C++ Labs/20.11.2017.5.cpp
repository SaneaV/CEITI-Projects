//В одномерном массиве, вводимом с клавиатуры и состоящем из N
//Вычислить cумму элементов расположенных между первым и последним нулевым элементом

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL, "Russian");
    int n,i=0;
    cout<<"Введите N: ";
    cin>> n;
    int *Array=new int[n];

    for (int i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>Array[i];
    }
    int p=0,p1=0,S=0;
    for (int i=0;i<n;i++)
    {
        if (Array[i]==0) {p=i;break;}
    }
    for (int i=p;i<n;i++)
    {
        if (Array[i]==0) p1=i;
    }
    for (int i=p;i<p1;i++)
    {
        S+=Array[i];
    }
    cout<<S;


}
