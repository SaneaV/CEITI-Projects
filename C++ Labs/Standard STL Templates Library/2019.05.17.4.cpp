#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Point
{
private:
    int x,y;
public:
    Point(int x,int y)
    {
        this->x = x;
        this->y = y;
    }

    void Print()
    {
        cout<<"("<<x<<":"<<y<<")"<<endl;
    }

    ~Point(){}
    friend void ChangeX(Point &value);
};

void ChangeX(Point &value)
{
    value.x--;;
}

int main()
{
    Point a(10,8);
    a.Print();
    ChangeX(a);
    a.Print();
    return 0;
}

