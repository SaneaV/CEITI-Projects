#include <iostream>

using namespace std;

class time
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    time(int, int, int);
    void show();
    time operator *(float);

};

time::time(int h, int m, int s)
{
    hours=h;
    minutes=m;
    seconds=s;

    if(hours<0)
        hours=0;
    if(minutes<0 or minutes>=60)
        minutes=0;
    if(seconds<0 or seconds>=60)
        seconds=0;
}

void time::show()
{
    if(hours<10)
        cout<<"0";
    cout<<hours<<":";
    if(minutes<10)
        cout<<"0";
    cout<<minutes<<":";
    if(seconds<10)
        cout<<"0";
    cout<<seconds<<endl;
}

time time::operator *( float n)
{
    ////////////////////////////////
    time tmp(hours,minutes,seconds);
    float t=0;
    ////////////////////////////////


    /////////////HOURS///////////////
    tmp.hours=hours*n;
    t=(hours*n-tmp.hours*1.0)*100.0;

    //////////MINUTES////////////////
    tmp.minutes=minutes*n+t;

    while(tmp.minutes>=60)
    {
        tmp.hours++;
        tmp.minutes-=60;
    }

    t=(minutes*n-tmp.minutes*1.0);
    cout<<t<<endl;

    ////////////SECONDS//////////////
    tmp.seconds=seconds*n+t;

    while(tmp.seconds>=60)
    {
        tmp.minutes++;
        tmp.seconds-=60;
    }
    /////////////////////////////////

    return tmp;
}



int main()
{
    setlocale(LC_ALL,"RUS");

    int h,m,s;
    float n;
    cout<<"¬ведите часы: ";
    cin>>h;
    cout<<"¬ведите минуты: ";
    cin>>m;
    cout<<"¬ведите секунды: ";
    cin>>s;

    cout<<endl<<endl;

    time t1(h,m,s);
    t1.show();

    time t2(h,m,s);

    cout<<"¬ведите число дл€ умножени€: ";
    cin>>n;

    t2=t1*n;
    t2.show();
}

