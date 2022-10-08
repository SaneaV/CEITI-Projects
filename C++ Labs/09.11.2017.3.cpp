//Вводятся N чисел.
//Найти максимальное из них

#include <iostream>

using namespace std;

main()
{
setlocale (0,"Rus");
int i,n,x=0,x1=INT_MIN;
cout<<"Введите количество число: ";
cin>>n;
for (i=0;i!=n;i++)
    {
    cout<<"Введите число: ";
    cin>>x;
    if (x>x1) (x1=x);
    }
    cout<<"Максимальное число: "<<x1;
}
