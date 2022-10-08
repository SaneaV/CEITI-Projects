//В одномерном массиве, вводимом с клавиатуры и состоящем из N
//Вычислить произведение элеменнтов с чётным номером

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
    int S=1;
    for (int i=2;i<n;i+=2)
    {
        S*=Array[i];
    }
        for (int i=2;i<n;i+=2)
    {
        Array[i]=S;
    }
    for (int i=0;i<n;i++)
    {
        cout<<Array[i]<<endl;
    }

}
