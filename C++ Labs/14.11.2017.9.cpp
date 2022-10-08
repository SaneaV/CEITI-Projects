//Вводяся N чисел. Подсчитать количество чисел, кратных двум.

#include <iostream>

using namespace std;

main()
{
    setlocale(0,"Rus");
    int n, S=0, x;
    cout<<"Введите n: ";
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        if (x%2==0) {S++;}
    }
    cout<<S;
}

