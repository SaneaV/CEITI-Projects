//В одномерном массиве, вводимом с клавиатуры и состоящем из N (1<=N<=1000) вещественных элементов,
//вычислить сумму модулей элементов массива, расположенных после минимального по модудю жлемента
#include <iostream>
#include <cmath>
using namespace std;
main()
{
    setlocale (0,"");
    cout<<"Введите количество цифр: ";
    int i,n, S=0, x[1000],m=0,pmin=0;
    cin>>n;
    for (i=0;i<n;i++)
    {
    cout<<"Введите число: ";
    cin>>x[i];
    }
    int min=abs(x[i]);
    for (int i=1;i<n;i++)
    {
        if (abs(x[i])<=min) {min=abs(x[i]);pmin=i;}
    }
    for (int i=pmin+1;i<n;i++)
    {
        S+=abs(x[i]);
    }
    cout<<"Ответ: "<<S;
}
