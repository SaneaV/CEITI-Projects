//Известна площадь квадрата. Найти его периметр.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"Введите площадь квадрата: ";
    int S;
    cin>>S;

    int P;
    P=4*sqrt(S);

    cout<<"Периметр квадрата: "<<P;
}
