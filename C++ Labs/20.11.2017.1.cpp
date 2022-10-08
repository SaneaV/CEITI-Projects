//В одномерном массиве, вводимом с клавиатуры и состоящем из N вещественных элеметов вычислить
//произведение массивов элементов, расположенных после максимального по модулю числа
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
    int max=abs(Array[i]);
    int pmax=0;
    for (int i=0;i<n;i++)
    {
        if (Array[i]>=max) {max=abs(Array[i]);pmax=i;}
    }
    int S=1;
    for (int i=pmax+1;i<n;i++)
    {
        S*=Array[i];
    }
    cout<<"Ответ: "<<S;
}
