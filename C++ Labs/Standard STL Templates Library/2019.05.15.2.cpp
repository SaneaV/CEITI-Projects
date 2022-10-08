#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

class CoffeeGrinder
{
private:

    bool GetVoltResult()
    {
        switch (rand()%3)
        {
        case 1:
        {
            return false;
        }
        case 2:
        {
            return true;
        }
        default: return false;
        }

    }

public:
    void Start()
    {
        if(GetVoltResult())
        {
            cout<<"Coffee Grinder started"<<endl;
        }
        else
        {
            cout<<"Coffee Grinder has not been started"<<endl;
            cout<<"Check your voltage!"<<endl;
        }


    }

};

int main()
{
    srand(time(NULL));
    CoffeeGrinder FirstCG;

    FirstCG.Start();


    return 0;
}
