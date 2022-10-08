#include <iostream>

class Human
{
public:
    std::string name;
    int age;
    int weight;


    Human(std::string name)
    {
        this->name = name;
        this->age = 0;
        this->weight = 0;
    }

    Human(std::string name, int age):Human(name)
    {
        this->age = age;
    }

    Human(std::string name, int age, int weight):Human(name, age)
    {
        this->weight = weight;
    }
};


int main()
{
    Human h("Nicolai", 10);

    return 0;
}
