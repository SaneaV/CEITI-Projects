#include <iostream>

template <typename T1, typename T2>
class MyClass
{
private:
    T1 value1;
    T2 value2;
public:

    MyClass(T1 value1)
    {
        this->value1 = value1;

    }

    MyClass(T2 value2):MyClass(value1)
    {
        this->value2 = value2;
    }

    int ValueSize()
    {
        return sizeof(value1) + sizeof(value2);
    }
};

class Point
{
private:
    int x,y,z;
public:

    Point()
    {

    }

    Point(int x, int y, int z)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    }
};

int main()
{
    Point p(10,20,25);
    MyClass<Point, int> s(p);


    std::cout<<"The size of your value is: "<<s.ValueSize()<<std::endl;

    return 0;
}
