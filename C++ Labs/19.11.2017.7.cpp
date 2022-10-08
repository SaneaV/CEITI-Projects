//Данн массив содержащий N(1<=N<=1000) вещественных элементов.
//Напишите программу, которая заменяет значение каэдого второго элемента на максимальное, начиная с первого.
#include <iostream>
#include <cmath>
using namespace std;
main()
{
    setlocale (0,"");
    cout<<"Введите количество цифр: ";
    int i, x[1000],n;
    cin>>n;
    if (n<0) n=abs(n);
    for (i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>x[i];
    }
    int max=INT_MIN;
    for (int i=0; i<n; i++)
    {
        if  (x[i]>=max) max=(x[i]);
    }
    for (int i=0; i<n; i+=2)
    {
        x[i] = max;
    }
    for (int i=0; i<n; i++)
    {
        cout<<x[i]<<endl;
    }

}
