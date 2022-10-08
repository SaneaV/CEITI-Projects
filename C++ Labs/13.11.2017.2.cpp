//Вводятся N чисел
//Найти минимальное число, которое больше либо равно нулю

#include <iostream>
#include <cmath>

using namespace std;

main ()
{
    setlocale (LC_ALL,"Rus");
    cout<<"Введите число";
    int n,x,x1=INT_MAX;
    cin>>n;
    for (int i=0;i<=n;i++)
    {
        cin>>x;
        if (x<x1 and x>=0) x1=x;
    }cout<<x1;



}
