//Дано трехзначное число. Верно ли, что сумма первой и последней его цифр больше, чем сумма второй и третьей его цифр.
#include <iostream>

using namespace std;

main()
{
    setlocale (0,"Rus");
    cout<<"Трёхзначное число: ";
    int x;
    cin>>x;
    int a,b,c;
    a=x%10;//последняя цифра
    b=x/10%10;//цифра посередине
    c=x/100;//первая цифра
    int z,y;
    z=a+c;//сумма последней и первой цифры
    y=b+a;//сумма средней и последней цифры
    (z>y)? cout<<"Сумма сумма последней и первой цифры больше.":cout<<"сумма средней и последней цифры больше.";
}
