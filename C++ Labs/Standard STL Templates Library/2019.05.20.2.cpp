#include <iostream>

class A
{
public:

    A() {};
    virtual ~A() = 0;
};

A::~A() {};

class B: public A
{
public:
    B() {};
    ~B() override {};
};

int main()
{
    A *Bptr = new B;
    delete Bptr;


    return 0;
}

