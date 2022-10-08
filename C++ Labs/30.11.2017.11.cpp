//В одномерном массиве вводимом с клавиатуры и состощем из N вещественных элементов, вычислить:
//Cумму положительных элементов массива расположенных после до максимального элемента

#include <iostream>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<"Введите размер массива: ";
    int n;
    cin>>n;
    int *x = new int [n];

    cout<<endl;

    for (int i=0;i<n;i++)
    {
        cout<<"Введите число: ";
        cin>>x[i];
    }

    cout<<endl;
    int max=x[0];
    int pmax=0;
    for (int i=0;i<n;i++)
        if (max<x[i]) {max=x[i];pmax=i;}

    int S=0;
    for (int i=0;i<pmax;i++)
        if (x[i]>0) S+=x[i];

    cout<<"Ваш массив: ";
    for (int i=0;i<n;i++)
        cout<<x[i]<<" ";

    cout<<endl<<"Сумма положительных элементов расположенных до максимального элемента массива: "<<S<<endl;

    system("PAUSE");
}

