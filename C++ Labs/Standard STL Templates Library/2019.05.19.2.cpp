#include <iostream>

class Gun
{
public:
    virtual void Shoot()
    {
        std::cout<<"Bang!"<<std::endl;
    }
};

class Player
{
public:

    void Shoot(Gun *gun)
    {
        gun->Shoot();
    }
};

class SubMachineGun:public Gun
{
public:
    void Shoot() override
    {
        std::cout<<"Bang, bang, bang!"<<std::endl;
    }
};

int main()
{
    Gun gun;
    SubMachineGun SMgun;
    Player p;

    SMgun.Shoot();
    gun.Shoot();

    Gun *weapon = &SMgun;
    weapon -> Shoot();
    std::cout<<"Player: "<<std::endl;
    p.Shoot(&gun);
    p.Shoot(&SMgun);

    return 0;
}
