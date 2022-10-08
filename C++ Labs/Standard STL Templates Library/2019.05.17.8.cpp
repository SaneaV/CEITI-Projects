#include <iostream>

class Apple
{
private:
    int id;
    int weight;
    std::string color;
    static int Count;

public:

    Apple(int weight, std::string color)
    {
        this->weight = weight;
        this->color = color;
        Count ++;
        id = Count;
    }

    int GetID()
    {
        return id;
    }

    static int GetCount()
    {
        return Count;
    }

    std::string GetColor()
    {
        return color;
    }

    static void ChangeColor(Apple &apple, std::string color)
    {
        apple.color = color;
    }

    ~Apple()
    {

    }
};

int Apple::Count = 0;

int main()
{

    Apple a(50, "red");
    Apple::ChangeColor(a, "yellow");
    Apple a2(100, "green");
    Apple a3(100, "green");
    std::cout<<a.GetID()<<std::endl;
    std::cout<<a2.GetID()<<std::endl;
    std::cout<<a3.GetID()<<std::endl;
    std::cout<<a.GetColor()<<std::endl;
    std::cout<<a2.GetColor()<<std::endl;
    std::cout<<a3.GetColor()<<std::endl;

    std::cout<<Apple::GetCount()<<std::endl;

    return 0;
}
