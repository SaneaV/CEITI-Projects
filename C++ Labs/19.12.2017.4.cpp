//Дана масса в килограммах. Найти число полных центнеров в ней.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");

    cout<<"Введите количество киллограмм: ";
    int kg,c;
    cin>>kg;
    c=kg/100;
    cout<<"Количество полных центнеров в ваших килограммах: "<<c;
}

