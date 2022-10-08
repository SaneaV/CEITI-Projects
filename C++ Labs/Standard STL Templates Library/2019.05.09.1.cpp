#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int do_Work(int &a)
{
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout<<"====================Start Work===================="<<endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout<<"====================End Work===================="<<endl;
    return a*=2;
}

int main()
{
    int q = 5;

    thread t(do_Work, std::ref(q));

    for(int i=0;i<10;i++)
    {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"Number of iteration: "<<i<<endl;
    }

    cout<<"The number is: "<<q<<endl;
    t.join();
    return 0;
}
