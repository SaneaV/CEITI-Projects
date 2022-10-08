#include <iostream>

class Point
{
private:
    int x,y;
public:
    Point()
    {
        x=0;
        y=0;
        std::cout<<this<<std::endl;
    }

    void SetY(int y)
    {
        this->y=y;
    }

    int GetY()
    {
        return y;
    }
};

int main()
{
    Point A;
    A.SetY(5);
    std::cout<<A.GetY();

    return 0;
}
