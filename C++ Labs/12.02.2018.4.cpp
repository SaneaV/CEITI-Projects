//С начала суток прошло N секунд. Сколько полных секунд прошло с начала очередной минуты?

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"Введите количество секунд: ";
    int N;
    cin>>N;

    int minutes=0, hours=0;


    while (N>=60)
    {
        minutes+=1;
        N-=60;
    }

    while (minutes>= 60)
    {
        hours+=1;
        minutes-=60;
    }

    cout<<"С начала очередной минуты прошло: "<<N<<" полных секунд(ы).";


}

