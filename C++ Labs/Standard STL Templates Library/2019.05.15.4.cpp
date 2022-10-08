#include <iostream>

class MyClass
{
private:
    int* data;

public:
    MyClass(int size)
    {
        data = new int [size];

        for(int i = 0; i<size; i++)
        {
            data[i]=i;
        }

        std::cout<<"The number is - "<<data<<". Constructor has been started."<<std::endl;
    }

    ~MyClass()
    {
        delete [] data;
        std::cout<<"The number is - "<<data<<". Destructor has been started."<<std::endl;
    }
};

int main()
{
    MyClass myFirstClass(1);
    MyClass mySecondClass(2);

}
