//В одномерном массиве, вводимом с клавиатуры и состоящем из N
//Напишите программу, которая обнуляет значение каждого третьего элемента

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
    for (int i=0;i<n;i+=3)
    {
        Array[i]=0;
    }
    for (int i=0;i<n;i++)
    {
        cout<<Array[i]<<endl;
    }


}
