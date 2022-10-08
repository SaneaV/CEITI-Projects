#include <iostream>

class myFunctor
{
public:
    void operator()()
    {
        std::cout<<"I am functor - "<<count<<std::endl;
        count++;
    }

private:
    int count = 0;
};

int main()
{
    myFunctor f;
    f();
    f();
    f();
    f();

    return 0;
}
