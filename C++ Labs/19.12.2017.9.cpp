//Дана масса в килограммах. Найти число полных тонн в ней.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale(LC_ALL,"Russian");

    cout<<"Введите количество килограмм: ";
    int kg;
    cin>>kg;
    int t=kg/1000;
    cout<<"Количество полных тонн в ваших килограммах: "<<t;
}
