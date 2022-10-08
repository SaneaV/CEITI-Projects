#include <iostream>

class Weapon
{
public:
    virtual void use() = 0;
};

class Gun : public Weapon
{
public:
    void use() override
    {
        std::cout<<"Bang!"<<std::endl;
    }
};

class SubmachineGun : public Gun
{
public:
    void use() override
    {
        std::cout<<"Bang, bang, bang!"<<std::endl;
    }
};

class Bazooka : public Weapon
{
public:
    void use() override
    {
        std::cout<<"BUM!"<<std::endl;
    }
};

class Knife : public Weapon
{
public:
    void use() override
    {
        std::cout<<"Shhhk"<<std::endl;
    }
};

class Player
{
public:
    void use(Weapon *wp)
    {
        wp -> use();
    }
};

int main()
{
    Gun g;
    SubmachineGun sg;
    Bazooka b;
    Knife k;

    Player p;

    p.use(&g);
    p.use(&sg);
    p.use(&b);
    p.use(&k);

    return 0;
}
