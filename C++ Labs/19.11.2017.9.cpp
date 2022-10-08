//Данн массив содержащий N(1<=N<=1000) вещественных элементов.
//Напишите программу, перемещает по кругу на одну позицию влево все элементы массива
#include <iostream>
#include <cmath>
using namespace std;
main()
{
    setlocale (0,"");
    cout<<"Введите количество цифр: ";
    int i, x[1000],n,t=0;
    cin>>n;
    if (n<0) n=abs(n);
    for (i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>x[i];
    }
    t=x[0];
    for (i=0;i<n;i++)
    {
        x[n]=t;
        x[i]=x[i+1];
        cout<<x[i]<<endl;
    }


}
