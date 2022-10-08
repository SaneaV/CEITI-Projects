#include <iostream>

class A
{
public:
    A() {};

    A(std::string msg)
    {
        this->msg=msg;
    }

    void PrintMSG()
    {
        std::cout<<msg<<std::endl;
    }

private:
    std::string msg;

};

class B : public A
{
public:
    B():A("The new message!") {};

};

int main()
{

    B b;

    b.PrintMSG();

    return 0;
}
