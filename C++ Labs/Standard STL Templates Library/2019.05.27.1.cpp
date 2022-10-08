#include <iostream>
#include <functional>

void Foo()
{
    std::cout<<"The function \"Foo\" was called"<<std::endl;
}

void Bar()
{
    std::cout<<"The function \"Bar\" was called"<<std::endl;
}

inline int Sum1(int &a, int &b)
{
    return a+b;
}

inline int Sum2(int a, int b)
{
    return a+b;
}

int main()
{
    std::function<void()> f;
    std::function<int(int&, int&)> f2;
    std::function<int(int, int)> f3;

    f = Foo;
    f();
    f = Bar;
    f();

    int a = 10;
    int b = 9;

    f2 = Sum1;
    std::cout<<f2(a,b)<<std::endl;

    f3 = Sum2;
    std::cout<<f3(10,9)<<std::endl;


    return 0;
}
