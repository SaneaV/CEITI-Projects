//Дана скорость в км/ч перевести скорость в м/с.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"Rus");

    cout<<"Введите скорость (км/ч): ";
    int km,m;
    cin>>km;

    m=(km*1000)/3600;

    cout<<"Скорость в (м/с): "<<m;
}
