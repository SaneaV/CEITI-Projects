#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void do_Work(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<<"==============Do Work - Start ===================="<<endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout<<a<<" + "<<b<<" = "<<a+b<<endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout<<"==============Do Work - End ===================="<<endl;
}

int main()
{
    setlocale(LC_ALL,"RUS");

    thread th(do_Work, 2, 2);

    for(int i=0;true;i++)
    {
        cout<<"ID - потока - \t"<<this_thread::get_id()<<"\tFirst Threat\t"<<i<<endl;
        this_thread::sleep_for(chrono::milliseconds(400));
    }

    th.join();

    return 0;
}
