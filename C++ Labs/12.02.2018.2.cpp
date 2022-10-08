//— начала суток прошло N секунд. —колько полных минут прошло с очередного часа?

#include <iostream>
#include <cmath>

using namespace std;

main()
{
    setlocale (LC_ALL,"Rus");

    cout<<"¬ведите количество секунд: ";
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

    cout<<"— начала очередного часа прошло: "<<minutes<<" полных минут(ы).";


}
