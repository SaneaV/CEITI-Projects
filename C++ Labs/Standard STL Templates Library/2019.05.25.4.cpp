#include <iostream>

template<typename T>
class Printer
{
public:
    Printer(T value)
    {
        std::cout<<value<<std::endl;
    }
};

template<>
class Printer<std::string>
{
public:
    Printer(std::string s)
    {
        std::cout<<"["<<s<<"]"<<std::endl;
    }

};

int main()
{
    Printer<std::string> p("Hello World!");
    Printer<int> p1(10);

    return 0;
}
