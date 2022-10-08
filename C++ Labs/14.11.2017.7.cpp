//Вводятся два числа. Отнимать одно от другого, пока они не будут равны. Вывести конечное значение.

#include <iostream>

using namespace std;

main()
{
    setlocale (0,"Rus");
    cout<<"Введите x: ";
    int x,y;
    cin>>x;
    cout<<"Введите y: ";
    cin>>y;
    for (;x!=y;)
    {
        if (x>y) x-=y;
        if (x<y) y-=x;
    } cout<<x;
}
