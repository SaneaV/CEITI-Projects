#include <iostream>

class A
{
public:
    A()
    {
        std::cout<<"The dynamic memory was picked out for class A"<<std::endl;
    }

    virtual ~A()
    {
        std::cout<<"The dynamic memory was deleted for class A"<<std::endl;
    }
};

class B: public A
{
public:
    B()
    {
        std::cout<<"The dynamic memory was picked out for class B"<<std::endl;
    }

    ~B() override
    {
        std::cout<<"The dynamic memory was deleted for class B"<<std::endl;
    }

};

int main()
{
    A *btrp = new B;
    delete btrp;


    return 0;
}
