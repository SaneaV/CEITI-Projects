#include <iostream>

class MSG
{
private:
    std::string msg;

public:
    MSG(std::string msg)
    {
        this->msg = msg;
    }

    virtual std::string getMSG()
    {
        return msg;
    }
};

class BraketsMSG : public MSG
{
public:
    BraketsMSG(std::string msg):MSG(msg)
    {
    }

    std::string getMSG() override
    {
        return "[" + ::MSG::getMSG() + "]";
    }

};

class Printer
{
public:
    void Print(MSG *msg)
    {
        std::cout<<msg->getMSG()<<std::endl;
    }
};

int main()
{
    Printer p;
    BraketsMSG m("Hi!");

    p.Print(&m);

    return 0;
}
