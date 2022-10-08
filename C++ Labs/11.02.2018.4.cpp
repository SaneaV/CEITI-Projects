//Дана масса в тоннах. Выразить массу в центнерах, килограммах и граммах.

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale(LC_ALL,"Rus");

    int tonni,kg,centner,gram;

    cout<<"Введите количество тонн: ";
    cin>>tonni;

    centner=tonni*10;
    kg=tonni*1000;
    gram=tonni*1000000;

    cout<<"Количество центнеров: "<<centner<<endl;
    cout<<"Количество килограмм: "<<kg<<endl;
    cout<<"Количество грамм: "<<gram;

}
