//В одномерном массиве вводимом с клавиатуры и состощем из N вещественных элементов, вычислить:
//количество элементов массива равных 0
//Сумму элементов массива расположенных после минимального элемента

#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;

    cout<<"Введите размер массива: ";
    cin>>n;

    cout<<endl;

    int x[n];
    int k=0;
    int min=x[0],pmin=0;

    for (int i=0;i<n;i++)
    {
        cout<<"Введите число: ";
        cin>>x[i];
        if (x[i]==0) k++;
        if (x[i]<min) {min=x[i];pmin=i;}
    }

    int S=0;

    for (int i=pmin;i<n;i++)
        S+=x[i];


    cout<<endl<<"В вашем массиве, элементов, равных нулю: "<<k<<endl;
    cout<<endl<<"Сумма элементов массива расположенных после минимального элемента: "<<S<<endl;

    system ("Pause");
}
