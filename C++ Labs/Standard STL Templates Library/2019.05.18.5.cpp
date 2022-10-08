#include <iostream>

class A
{
public:
   std::string msgOne = "The first message";
private:
   std::string msgTwo = "The second message";
protected:
   std::string msgTree = "The thirty message";
};

class B : public A
{
public:
    void printMessage()
    {
        std::cout<<msgOne<<std::endl;
    }
};

int main()
{
    B b;
    b.printMessage();

    return 0;
}
