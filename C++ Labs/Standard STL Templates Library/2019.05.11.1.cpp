#include <iostream>

int decrement_Cout(int a)
{
    if(a<1) return 0;
    else decrement_Cout(--a);
    std::cout<<a<<std::endl;
}

int cout_Decrement(int a)
{
    if(a<1) return 0;
    std::cout<<a<<std::endl;
    cout_Decrement(--a);
}

int main()
{
    decrement_Cout(10);
    std::cout<<std::endl;
    cout_Decrement(10);

    return 0;
}
