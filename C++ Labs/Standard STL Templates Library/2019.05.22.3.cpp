#include <iostream>
#include <fstream>

using namespace std;

class Point
{
public:
    int x,y,z;

    Point(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Point()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    void Print()
    {
        cout<<"x = "<<x<<"\ty = "<<y<<"\tz = "<<z<<endl;
    }
};

int main()
{
    Point p(4,5,6);
    p.Print();

    ofstream fout;
    fout.open("MyFile.txt", ofstream::app);

    if(!fout.is_open())
    {
        cout<<"File was not open"<<endl;
    }
    else
    {
        fout.write((char *)&p, sizeof(Point));
    }
    fout.close();

    ifstream fin;
    fin.open("MyFile.txt");

        if(!fin.is_open())
    {
        cout<<"File was not open"<<endl;
    }
    else
    {
        Point pnt;
        while(fin.read((char *)&pnt, sizeof(Point)))
            pnt.Print();
    }
    fin.close();

    return 0;
}
