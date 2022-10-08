#include <iostream>

class Car
{
public:
    Car()
    {
       std::cout<<"The car constructor was claimed"<<std::endl;
    };

    void Drive()
    {
        std::cout<<"I drive"<<std::endl;
    }
};

class Airplane
{
public:
    Airplane()
    {
        std::cout<<"The airplane constructor was claimed"<<std::endl;
    }

    void Fly()
    {
        std::cout<<"I fly"<<std::endl;
    }
};

class FlyingCar:public Car, public Airplane
{
public:
    FlyingCar()
    {
        std::cout<<"The flyingcar constructor was claimed"<<std::endl;
    }

};

int main()
{
    Car c;
    c.Drive();

    Airplane a;
    a.Fly();


    std::cout<<std::endl;

    FlyingCar fc;
    fc.Drive();
    fc.Fly();

    return 0;
}
