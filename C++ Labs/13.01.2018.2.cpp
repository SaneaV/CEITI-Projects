//С начала суток прошло N секунд. Определить, сколько полных часов прошло с начала суток.

#include <iostream>

using namespace std;

main()
{
    setlocale(LC_ALL,"Rus");

    cout<<"Введите количество секунд: ";
    int sec;
    cin>>sec;

    int mint=0;
    int hours=0;
    int days=0;

    if (sec>=60)
    {
        mint = sec/60;
        while (sec>=60)
            sec-=60;
    }
    if (mint>=60)
    {
        hours= mint/60;
        while (mint>=60)
            mint-=60;
    }

        if (mint>=60)
    {
        hours= mint/60;
        while (mint>=60)
            mint-=60;
    }

        if (hours>=24)
    {
        days= hours/24;
        while (hours>=24)
            hours-=24;
    }

    cout<<"Прошло: "<<sec<<" секунд, "<<mint<<" минут, "<<hours<<" часов, "<<days<<" дней.";
}
