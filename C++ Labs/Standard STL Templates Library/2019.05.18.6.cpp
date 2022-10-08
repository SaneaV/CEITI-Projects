#include <iostream>

class A
{
public:
    A()
    {
        std::cout<<"The parent constructor was claimed!"<<std::endl;
    }

    ~A()
    {
        std::cout<<"The parent destructor was claimed!"<<std::endl;
    }

};

class B : public A
{
public:
    B()
    {
        std::cout<<"The children constructor was claimed!"<<std::endl;
    }
    ~B()
    {
        std::cout<<"The children destructor was claimed!"<<std::endl;
    }

};

class C : public B
{
public:
    C()
    {
        std::cout<<"The second children constructor was claimed!"<<std::endl;
    }

    ~C()
    {
        std::cout<<"The second children destructor was claimed!"<<std::endl;
    }
};

int main()
{
    C c;
    std::cout<<std::endl;

    return 0;
}

