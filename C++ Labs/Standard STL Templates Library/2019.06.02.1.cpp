#include <iostream>

class MyClass
{
private:
    int a;
    std::string msg;

public:
    MyClass()
    {
        msg = "Hi! How are you?";
    }

    void lampda()
    {
        auto f = [this]()
        {
            std::cout<<msg<<std::endl;
        };
        f();
    }
};

int main()
{
    int a = 10;

    auto f = [&a]()
    {
        std::cout<<"a = "<<a<<std::endl;

    };

    f();

    MyClass mClass;

    mClass.lampda();

    return 0;
}
