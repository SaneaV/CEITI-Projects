//Даны четыре вещественных числа. Найти сумму тех из них, которые больше десяти.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    float a,b,c,d;
    cout<<"Введите число a: ";
    cin>>a;
    cout<<"Введите число b: ";
    cin>>b;
    cout<<"Введите число c: ";
    cin>>c;
    cout<<"Введите число d: ";
    cin>>d;

    float S=0;

    a>=10.0? S+=a:S+=0;
    b>=10.0? S+=b:S+=0;
    c>=10.0? S+=c:S+=0;
    d>=10.0? S+=d:S+=0;

    cout<<"Сумма вещественных чисел, которые больше десяти: "<<S;
}
