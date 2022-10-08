#include <iostream>

int main()
{
    int p=0;

    auto f = [&p] ()
    {
        return p = 5;
    };

    std::cout<<f()<<std::endl;
    return 0;
}
