#include <iostream>
#include <typeinfo>

template <typename T>
class typeSize
{
protected:
    T value;
public:

    typeSize(T value)
    {
        this->value = value;

    }

    int ValueSize()
    {
        return sizeof(value);
    }
};

template<typename T>
class typeInfo : public typeSize<T>
{
public:
    typeInfo(T value):typeSize<T>(value)
    {

    }

    std::string showTypeInfo()
    {
        return typeid(typeSize<T>::value).name();
    }

private:

};



int main()
{
    typeInfo<double> s(10);

    std::cout<<"The size of your value is: "<<s.ValueSize()<<std::endl;

    std::cout<<s.showTypeInfo()<<std::endl;

    return 0;
}
