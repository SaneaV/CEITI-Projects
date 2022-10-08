#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Component
{
public:
    Component(string companyName)
    {
        cout<<"Constructor component"<<endl;
        this->companyName = companyName;
    }

    string companyName;
};

class GPU : public  Component
{
public:
    GPU(string companyName) : Component(companyName)
    {
        cout<<"Constructor GPU"<<endl;
    }
};

class Memory : public  Component
{
public:
    Memory(string companyName) : Component(companyName)
    {
        cout<<"Constructor Memory"<<endl;
    }
};

class GraphicCard : public GPU, public Memory
{
public:
    GraphicCard(string GPUcompanyName, string MemoryCompanyName):GPU(GPUcompanyName), Memory(MemoryCompanyName)
    {
        cout<<"Constructor GraphicCard"<<endl;
    }
};

int main()
{
    GraphicCard("Intel", "AMD");

    return 0;
}
