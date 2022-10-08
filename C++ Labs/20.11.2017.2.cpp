//В одномерном массиве, вводимом с клавиатуры и состоящем из N вещественных элеметов
//Напишите программу, которая заменяет значение каждого пятого элемента на минимальное значение начиная с первого

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

    for (int i=0; i<n;i++)
    {
       cout<<"Введите число: ";
       cin>>Array[i];
    }
    int min=Array[i];
    for (int i=0;i<n;i++)
    {
        if (Array[i]<min) min=Array[i];
    }
    for (int i=0;i<n;i+=4)
    {
        Array[i]=min;
    }
    for (int i=0;i<n;i++)
    {
        cout<<Array[i]<<endl;
    }
    }
