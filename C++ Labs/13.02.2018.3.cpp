//С клавиатуры вводится время (часы и минуты). Определить сколько минут прошло с начала суток.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"Rus");

    int minutes,hours;

    cout<<"Введите количество часов: ";
    cin>>hours;

    cout<<"Введите количество минут: ";
    cin>>minutes;

    int days=0;

    while (minutes>=60)
    {
        hours++;
        minutes-=60;
    }

    while (hours>=24)
    {
        days++;
        hours-=24;
    }

    if (hours<=23)
    {
        minutes+=hours*60;
    }

    cout<<"С начала суток прошло: "<<minutes<<" минут";
}
