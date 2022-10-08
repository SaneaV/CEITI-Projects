//В одномерном массиве вводимом с клавиатуры и состощем из N вещественных элементов, вычислить:
//произведение отрицательных элементов массива

#include <iostream>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;

    cout<<"Введите размер массива: ";
    cin>>n;
    int *x= new int [n];

    cout<<endl;
    for (int i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>x[i];
    }
    int S=1;
    for (int i=0; i<n; i++)
        if (x[i]<0) S*=x[i];

    cout<<endl;
    for (int i=0; i<n; i++)
        cout<<x[i]<<" ";

    cout<<endl<<"Произведение отрицательных элементов массива: "<<S<<endl;

    system("Pause");

}
