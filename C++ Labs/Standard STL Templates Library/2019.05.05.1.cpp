#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void SecondThread()
{
    for(int i=1;i<=10;i++)
    {
        cout<<"ID - потока - \t"<<this_thread::get_id()<<"\tSecond Threat\t"<<i<<endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");

    thread th(SecondThread);

    for(size_t i=1;i<=10;i++)
    {
        cout<<"ID - потока - \t"<<this_thread::get_id()<<"\tFirst Threat\t"<<i<<endl;
        this_thread::sleep_for(chrono::milliseconds(400));
    }

    th.join();

    return 0;
}
