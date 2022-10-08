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
    time operator -(time t1);
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

time time::operator -(time t1)
{
    time tmp(hours,minutes,seconds);

    tmp.hours=t1.hours-hours;
    if(hours>0)
    {

        if(minutes<t1.minutes)
        {
            hours--;
            minutes+=60;

        }

        if(seconds<t1.seconds)
        {
            minutes--;
            minutes+=60;

        }

        if(tmp.hours<0)
            tmp.hours*-1.0;
        tmp.minutes=t1.minutes-minutes;
        if(tmp.minutes<0)
            tmp.minutes*(-1);
        tmp.seconds=t1.seconds-seconds;
        if(tmp.seconds<0)
            tmp.seconds*(-1);

        return tmp;
    }
    else
        cout<<"ќпераци€ невозможна."<<endl;
}

int main()
{
    setlocale(LC_ALL,"RUS");

    int h,m,s;
    cout<<"¬ведите часы: ";
    cin>>h;
    cout<<"¬ведите минуты: ";
    cin>>m;
    cout<<"¬ведите секунды: ";
    cin>>s;

    cout<<endl<<endl;

    time t1(h,m,s);
    t1.show();

    cout<<"¬ведите часы: ";
    cin>>h;
    cout<<"¬ведите минуты: ";
    cin>>m;
    cout<<"¬ведите секунды: ";
    cin>>s;

    cout<<endl<<endl;

    time t2(h,m,s);
    t2.show();

    time t3(h,m,s);

    t3=t1-t2;
    t3.show();
}

