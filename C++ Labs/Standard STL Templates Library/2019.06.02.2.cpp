#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Timer
{
private:
     std::chrono::time_point<std::chrono::_V2::system_clock> start, stop;
public:
    Timer()
    {
        start = chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        stop = chrono::high_resolution_clock::now();
        chrono::duration<float> duration = stop - start;
        cout<<duration.count()<<endl;
    }
};

int Sum(int a, int b)
{
    Timer timer;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout<<"ID потока - "<<this_thread::get_id()<<" - Старт Функции"<<endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout<<"ID потока - "<<this_thread::get_id()<<" - Конец Функции"<<endl;
    return a+b;
}

int main()
{
    Timer timer;
    setlocale(LC_ALL,"RUS");

    int result=0;

    thread t ([&result]()
    {
        result = Sum(10, 20);
    });

    for(int i=1; i<=10; i++)
    {
        cout<<"ID потока - "<<this_thread::get_id()<<" - "<<i<<endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout<<endl<<result<<endl;
    t.join();

    return 0;
}
