#include <iostream>

using std::endl;
using std::cout;
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

    Point &operator ++()
    {
        this->x++;
        this->y++;

        return *this;
    }

    Point &operator --()
    {
        this->x--;
        this->y--;

        return *this;
    }

    Point &operator++ (int value)
    {
        Point temp(*this);

        this->x++;
        this->y++;

        return temp;
    }

    Point &operator-- (int value)
    {
        Point temp(*this);

        this->x--;
        this->y--;

        return temp;
    }

    void Print()
    {
        cout<<"("<<x<<":"<<y<<")"<<endl;
    }

    ~Point()
    {

    }
};

int main()
{
    Point a(1,1);
    a.Print();
    ++a;
    a.Print();
    a++;
    a.Print();
    --a;
    a.Print();
    a--;
    a.Print();

    return 0;
}
