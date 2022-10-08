#include <iostream>
#include <thread>

using namespace std;

Sum(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(500));
    cout<<"ID - "<<this_thread::get_id()<<" - Sum Started "<<endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout<<"ID - "<<this_thread::get_id()<<" - Sum Started "<<endl;
    return a+b;
};

int main()
{
    int result;
    thread t([&result]()
    {
        return result = Sum(2,6);
    }
            );

    for(size_t i=1; i<=10; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(200));
        cout<<"ID - "<<this_thread::get_id()<<" - Main - "<<i<<endl;
    }

    cout<<result;

    t.join();
    return 0;
}
