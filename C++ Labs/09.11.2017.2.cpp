//Вводятся числа от 1 до n включительно
//Вывести на экран сумму произведений этих чисел

#include <iostream>

using namespace std;

main()
{
    setlocale (0,"Rus");
    int n,S=0,r=1;
    cout<<"Введите число: ";
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        r*=i;
        S+=r;
    }
    cout<<"Сумма равна: "<<S;
}
