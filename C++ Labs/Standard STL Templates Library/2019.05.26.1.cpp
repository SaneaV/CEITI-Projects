#include <iostream>

template <typename T>
class SmartPointer
{
private:
    T *ptr;

public:

    SmartPointer(T *ptr)
    {
        this->ptr = ptr;
    }

    ~SmartPointer()
    {
        delete ptr;
    }

    T& operator *()
    {
        return *ptr;
    }

};

int main()
{
    SmartPointer<int> pointer = new int(5);
    *pointer = 1000;

    std::cout<<*pointer;


    return 0;
}
