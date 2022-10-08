#include <iostream>

class Apple
{
private:
    int weight;
    std::string color;

public:
        static int Count;

    Apple(int weight, std::string color)
    {
        Count++;
        this->weight = weight;
        this->color = color;
    }

    void Print()
    {
        std::cout<<"weight = "<<weight<<std::endl;
        std::cout<<"color = "<<color<<std::endl;
    }

    ~Apple()
    {

    }
};

int Apple::Count = 0;

int main()
{
    Apple a(50, "red");
    Apple a2(100, "green");
    std::cout<<a.Count<<std::endl;
    std::cout<<a2.Count<<std::endl;

    return 0;
}

