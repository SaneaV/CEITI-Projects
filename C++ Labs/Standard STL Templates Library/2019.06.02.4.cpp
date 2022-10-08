#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <windows.h>
#include <ctime>

using std::cout;
using std::endl;
using std::thread;

class Even
{
private:
    int evenSum;
    int evenCount;

public:
    Even()
    {
        evenCount = 0;
        evenSum = 0;
    }
    void showEvenCoutn()
    {
        cout<<evenCount<<endl;
    }

    void showEvenSum()
    {
        cout<<evenSum<<endl;
    }

    void operator ()(int a)
    {
        if(a%2==0)
        {
            evenCount++;
            evenSum+=a;
        }

    }
};

int main()
{
    srand(time(NULL));

    bool menuWork = true;
    int number;
    Even ef;

    while(menuWork)
    {
        number = rand()%100;
        ef(number);

        ef.showEvenCoutn();
        ef.showEvenSum();
        system("cls");

    }
    return 0;
}
