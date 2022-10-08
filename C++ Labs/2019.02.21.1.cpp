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
    void add_time(time, time);
};

time::time(int h, int m, int s)
{
    hours=h;
    minutes=m;
    seconds=s;

    if(hours<0) hours=0;
    if(minutes<0 or minutes>=60) minutes=0;
    if(seconds<0 or seconds>=60) seconds=0;
}

void time::show()
{
    if(hours<10) cout<<"0";
    cout<<hours<<":";
    if(minutes<10) cout<<"0";
    cout<<minutes<<":";
    if(seconds<10) cout<<"0";
    cout<<seconds<<endl;
}

void time::add_time(time t1, time t2)
{
    hours=t1.hours+t2.hours;
    minutes=t1.minutes+t2.minutes;
    seconds=t1.seconds+t2.seconds;

    if(seconds>=60) {seconds = 60; minutes++;}
    if(minutes>=60) {minutes = 60; hours++;}

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

    cout<<endl<<endl;
    t3.add_time(t1,t2);
    t3.show();
}
