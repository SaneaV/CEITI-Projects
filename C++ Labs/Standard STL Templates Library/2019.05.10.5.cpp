#include <iostream>

int Sum(int a, int b)
{
    return a+b;
}

double Sum(double a, double b)
{
    return a+b;
}

float Sum(int a, int b, float c)
{
    return a+b+c;
}

int main()
{
    std::cout<<Sum(2,2)<<std::endl;
    std::cout<<Sum(2.2, 3.3)<<std::endl;
    std::cout<<Sum(2, 3, 4.4)<<std::endl;

    return 0;
}
