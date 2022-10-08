//Данн массив содержащий N(1<=N<=1000) вещественных элементов.
//вычислить номер максимально по модудю элемента
#include <iostream>
#include <cmath>
using namespace std;
main()
{
    setlocale (0,"");
    cout<<"Введите количество цифр: ";
    int i, x[1000],pmax=0,n;
    cin>>n;
    if (n<0) n=abs(n);
    for (i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>x[i];
    }
    int max=0;
    for (int i=1;i<n;i++)
    {
        if (abs(x[i])>=max) {max=abs(x[i]);pmax=i;}
    }
    cout<<"Ответ: "<<pmax;
}
