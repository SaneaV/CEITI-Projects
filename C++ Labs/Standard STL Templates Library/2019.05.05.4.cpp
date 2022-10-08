#include <iostream>

using namespace std;

class MyClass
{
public:
    MyClass();
    ~MyClass();
    void printMesage();

private:
};

void MyClass::printMesage()
{
    cout<<"Hi, I'm a prototype of MyClass!"<<endl;
}

MyClass::MyClass() {}
MyClass::~MyClass() {}

int main()
{
    MyClass a;
    a.printMesage();

    return 0;
}
