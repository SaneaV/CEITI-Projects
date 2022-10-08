#include <iostream>

using std::cout;
using std::endl;

class Point
{
private:
    int x,y;

public:
    bool operator == (const Point &otherPoint);
    bool operator != (const Point &otherPoint);
    Point operator + (const Point &otherPoint);
    Point &operator = (const Point &otherPoint);

    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
    void SetX(int x)
    {
        this->x = x;
    }
    void SetY(int y)
    {
        this->y = y;
    }

    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void Print()
    {
        cout<<"x = "<<x<<";"<<"y = "<<y<<endl;
    }


    ~Point() {}
};

Point & Point::operator =(const Point &otherPoint)
{
    this->x = otherPoint.x;
    this->y = otherPoint.y;

    return *this;
}

bool Point::operator ==(const Point &otherPoint)
{
    return this->x==otherPoint.x and this->y==otherPoint.y;
}

bool Point::operator !=(const Point &otherPoint)
{
    return !(this->x==otherPoint.x and this->y==otherPoint.y);
}

Point Point::operator +(const Point &otherPoint)
{
    Point temp;

    temp.x=otherPoint.x + this->x;
    temp.y=otherPoint.y + this->y;

    return temp;
}

int main()
{
    Point first(10,20);
    Point second(20,10);
    Point third;
    third = first;
    bool result;

    result = first == second;
    cout<<"First == second: "<<result<<endl;
    result = first == third;
    cout<<"First == third: "<<result<<endl;
    result = second == third;
    cout<<"Second == third: "<<result<<endl;
    cout<<endl;
    result = first != second;
    cout<<"First != second: "<<result<<endl;
    result = first != third;
    cout<<"First != third: "<<result<<endl;
    result = second != third;
    cout<<"Second != third: "<<result<<endl;
    cout<<endl<<endl;


    Point four;
    four = third + second;

    first.Print();
    second.Print();
    four.Print();


    return 0;
}
