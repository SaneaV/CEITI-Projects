#include <iostream>

class Apple;

class Human
{
public:

    void TakeApple(Apple &apple);
};

class Apple
{
private:
    int weight;
    std::string color;

public:
    Apple(int weight, std::string color)
    {
        this->weight = weight;
        this->color = color;
    }

    friend class Human;

    void Print()
    {
        std::cout<<"weight = "<<weight<<std::endl;
        std::cout<<"color = "<<color<<std::endl;
    }

    ~Apple()
    {

    }
};

void Human::TakeApple(Apple &apple)
{
    apple.color = "white";
}

int main()
{
    Apple a(50, "red");

    a.Print();

    Human human;

    human.TakeApple(a);

    a.Print();



    return 0;
}

