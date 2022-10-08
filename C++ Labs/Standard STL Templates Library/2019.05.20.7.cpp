#include <iostream>

class IBicycle
{
public:
    virtual void TwistTheWheel() =0;
    virtual void Ride() = 0;
};

class SimpleBicycle : public IBicycle
{
    void TwistTheWheel() override
    {
        std::cout<<"method TwistTheWell Simple Bicycle"<<std::endl;
    }

    void Ride() override
    {
        std::cout<<"method Ride Simple Bicycle"<<std::endl;
    }
};

class SportBicycle : public IBicycle
{
    void TwistTheWheel() override
    {
        std::cout<<"method TwistTheWell Sport Bicycle"<<std::endl;
    }

    void Ride() override
    {
        std::cout<<"method Ride Sport Bicycle"<<std::endl;
    }
};

class Human
{
public:
    void RideBicycle(IBicycle &bicycle)
    {
        std::cout<<"Twist the wheel"<<std::endl;
        bicycle.TwistTheWheel();
        std::cout<<"Ride the bike"<<std::endl;
        bicycle.Ride();
    }

};




int main()
{
    SimpleBicycle sm;
    SportBicycle spm;
    Human h;

    h.RideBicycle(sm);
    h.RideBicycle(spm);

    return 0;
}
