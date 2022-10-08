#include <iostream>
#include <windows.h>
#include <conio.h>

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

    time  operator ++();
    time  operator ++(int);

    time  operator --();
    time  operator --(int);


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

time time::operator ++()
{
    ++seconds;
    if(seconds>=60)
    {
        ++minutes;
        seconds=0;
    }
    if(minutes>=60)
    {
        ++hours;
        minutes=0;
    }
    return *this;
}

time time::operator --()
{
    --seconds;
    if(seconds<=0)
    {
        --minutes;
        seconds=59;
    }
    if(minutes<=0)
    {
        --hours;
        minutes=59;
    }
    return *this;
}

time time::operator ++(int)
{

    time x = *this;

    seconds++;
    if(seconds>=60)
    {
        minutes++;
        seconds=0;
    }
    if(minutes>=60)
    {
        hours++;
        minutes=0;
    }
    return x;
}

time time::operator --(int)
{

    time x = *this;

    seconds--;
    if(seconds<=0)
    {
        minutes--;
        seconds=59;
    }
    if(minutes<=0)
    {
        hours--;
        minutes=59;
    }
    return x;
}




int main()
{
    setlocale(LC_ALL,"RUS");

    int h,m,s;
    bool Stop=false;

    cout<<"¬ведите часы: ";
    cin>>h;
    cout<<"¬ведите минуты: ";
    cin>>m;
    cout<<"¬ведите секунды: ";
    cin>>s;

    cout<<endl<<endl;

    time t1(h,m,s);
    t1.show();

    while(!Stop)
    {
        cout<<"1. Press 1 for (++i)"<<endl;
        cout<<"2. Press 2 for (i++)"<<endl;
        cout<<"3. Press 3 for (--i)"<<endl;
        cout<<"4. Press 4 for (i--)"<<endl;


        if(_kbhit)
        {
            switch(getch())
            {
            case '1':
            {
                system("cls");
                ++t1;
                t1.show();
                break;
            }
            case '2':
            {
                system("cls");
                t1++.show();
                break;
            }
            case '3':
            {
                system("cls");
                --t1;
                t1.show();
                break;
            }
            case '4':
            {
                system("cls");
                t1--.show();
                break;
            }
            case 'x':
                {
                    Stop=true;
                    break;
                }
            }
        }
    }

}


