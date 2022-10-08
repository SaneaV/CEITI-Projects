#include <iostream>
#include <fstream>

using namespace std;

class Point
{
private:
    int x,y,z;

public:

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getZ()
    {
        return z;
    }

    void setX(int x)
    {
        this->x = x;
    }

    void setY(int y)
    {
        this->y = y;
    }

    void setZ(int z)
    {
        this->z = z;
    }

    Point()
    {
        x=0;
        y=0;
        z=0;
    }

    Point(int x) : Point()
    {
        this->x=x;
    }

    Point(int x, int y, int z)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    }


    ~Point()
    {

    }
};

ostream& operator<<(ostream &os,Point& point)
{
    os<<point.getX()<<" "<<point.getY()<<" "<<point.getZ()<<endl;
    return os;
}

istream& operator>>(istream &is,Point& point)
{
    int x, y, z;
    is>>x>>y>>z;

    point.setX(x);
    point.setY(y);
    point.setZ(z);

    return is;
}

int main()
{
    Point firstPoint;
    Point secondPoint(1,2,3);

    Point firstTemp;
    Point secondTemp;

    fstream fs;

    fs.open("MyFile.txt", fstream::in | fstream::out | fstream::app);

    try
    {
        if(!fs.is_open())
            throw 0;
        else
        {

            fs>>firstTemp;
            fs>>secondTemp;

        }
    }
    catch(int i)
    {
        if(i==0)
            cout<<"File was not open"<<endl;
    }

    fs.close();

    cout<<firstTemp<<endl;
    cout<<secondTemp<<endl;

    return 0;
}
