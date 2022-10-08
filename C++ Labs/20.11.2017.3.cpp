//В одномерном массиве, вводимом с клавиатуры и состоящем из N
//Напишите программу, которая удаляет все нули из массива

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
    while (i<n)
    {
        if (Array[i]==0)
        {
            for (int j=i; j<n; j++)
            {
                Array[j]=Array[j+1];
            }
            n--;
        }
        else i++;
    }
    for (int i=0; i<n; i++)
    {
        cout<<Array[i]<<endl;
    }
}
