#include <iostream>

using std::cout;
using std::endl;

class POINT
{
public:
    int x;
    int y;
    int z;
};

int main()
{
    POINT FirstPoint;

    FirstPoint.x = 10;
    FirstPoint.y = 3;
    FirstPoint.z = 4;

    cout<<"("<<FirstPoint.x<<":"<<FirstPoint.y<<":"<<FirstPoint.z<<")"<<endl;


}
