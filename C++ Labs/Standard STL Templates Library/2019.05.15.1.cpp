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
    int GetX(){return x;}
    int GetY(){return y;}
    void SetX(int valueX){x=valueX;}
    void SetY(int valueY){y=valueY;}

    void Print() {cout<<"X = "<<x<<"; Y = "<<y<<endl;}

};

int main()
{
    srand(time(NULL));
    Point A;

    A.SetX(rand()%10);
    A.SetY(rand()%10);
    A.Print();

    cout<<endl<<endl;

    cout<<A.GetX()<<endl;
    cout<<A.GetY()<<endl;

    return 0;
}
