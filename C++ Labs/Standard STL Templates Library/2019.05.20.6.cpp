#include <iostream>

class Car
{
public:
    void Use()
    {
        std::cout<<"I drive"<<std::endl;
    }
};

class Airplane
{
public:
    void Use()
    {
        std::cout<<"I fly"<<std::endl;
    }
};

class FlyingCar:public Car, public Airplane
{
public:


};

int main()
{
    FlyingCar fc;
    ((Car)fc).Use();
    ((Airplane)fc).Use();

    return 0;
}
