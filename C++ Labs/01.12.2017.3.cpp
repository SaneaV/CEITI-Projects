//В одномерном массиве, вводимом с клавиатуры и состоящем из N вещественных элементов
//Вычислить сумму элементов массива с нечётными номерами
//Сумму элементов массива расположенных между первым и последним отрицательным элементом

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
    int S=0;

    for (int i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>x[i];
    }

    for (int i=0; i<n; i++)
        if (i%2!=0)
        {
            S+=x[i];
        }

    int pfirst=0, psecond=0;

    for (int i=0; i<n; i++)
    {
        if (x[i]<0)
        {
            pfirst = i;
            break;
        }
    }

    for (int i=0;i<n;i++)
    {
        if (x[i]<0)
        {
            psecond = i;
        }

    }

    int S1=0;
    for (int i=pfirst+1; i<psecond; i++)
        {S1+=x[i];}


    cout<<endl<<"Сумма элементов массива под нечётными номерами: "<<S;
    cout<<endl<<"Сумма элементов массива расположенных между первым и последним отрицательными элементами: "<<S1;

    system ("Pause");
}
