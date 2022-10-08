#include <iostream>
#include <stdlib.h>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

class Point
{
private:
    int x,y;

public:

    Point(int valueX, int valueY)
    {
        x = valueX;
        y = valueY;
    }

    Point(int valueX, bool boolean)
    {
        x=valueX;
        boolean? y=1:y=3;
    }

    Point()
    {
        x=0;
        y=0;
    }

    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
    void SetX(int valueX)
    {
        x=valueX;
    }
    void SetY(int valueY)
    {
        y=valueY;
    }

    void Print()
    {
        cout<<"X = "<<x<<"; Y = "<<y<<endl;
    }

};

int main()
{
    srand(time(NULL));
    Point A(10,5);
    Point B(5,7);
    Point C;
    Point D(2, true);
    Point E(3, false);

    A.Print();
    B.Print();
    C.Print();
    D.Print();
    E.Print();

    return 0;
}

