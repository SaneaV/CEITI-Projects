#include <iostream>

enum PCstate
{
    OFF,
    ON,
    Sleep
};

class PC
{
public:
    PCstate getPCstate()
    {
        return state;
    }

    void setPCstate(const PCstate &state)
    {
        this->state=state;
    }

private:
    PCstate state;
};

int main()
{
    PC pc;

    std::cout<<"PC was turned on!"<<std::endl;
    pc.setPCstate(ON);

    if(pc.getPCstate()==ON)
    {
        std::cout<<"PC was turned off"<<std::endl;
    }

    pc.setPCstate(OFF);

    std::cout<<"The state of PC is - "<<pc.getPCstate()<<std::endl;

    return 0;
}
