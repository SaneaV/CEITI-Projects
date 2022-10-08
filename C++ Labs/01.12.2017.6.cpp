//В одномерном массиве, вводимом с клавиатуры и состоящем из N вещественных элементов
//Номер максимального элемента
//Произведение элементов массива, расположенных между первым и вторым нулевым эдементом

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

    int x[n];
    int max=x[0];
    int pmax=0;

    for (int i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>x[i];
    }

    for (int i=0; i<n; i++)
    {
        if (max<x[i])
        {
            max=x[i];
            pmax=i;
        }
    }

    int pfirst=0;

    for (int i=0; i<n; i++)
    {
        if (x[i]==0)
        {
            pfirst=i;
            i=n;
        }
    }

    int psecond=0;

    for (int i=pfirst+1; i<n; i++)
    {
        if (x[i]==0)
        {
            psecond=i;
            i=n;
        }
    }

    int S=1;

    for (int i=pfirst+1; i<psecond; i++)
    {
        S*=x[i];
    }


    cout<<"Позиция максимального элемента: "<<pmax<<endl;
    cout<<"Произведение между первым и вторым нулём: "<<S<<endl;

    system ("Pause");

}
