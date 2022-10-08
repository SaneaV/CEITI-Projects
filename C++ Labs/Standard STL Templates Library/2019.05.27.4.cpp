#include <iostream>
#include <vector>
#include <stdlib.h>
#include <functional>
#include <windows.h>

void Foo(const int a)
{
    if(a>10 and a<50)
        std::cout<<a<<" ";
}

void Bar(const int a)
{
    if(a%2==0)
        std::cout<<a<<" ";
}

template<typename T>
void doWork(std::vector<T> &myVector, std::vector<std::function<void(const int)>> f)
{
    for(auto i:myVector)
        for(auto &j:f)
        {
            j(i);
        }
}

int main()
{
    std::vector<int> myVector = {4,5,2,67,89,12,4,56,7,8};
    std::vector<std::function<void(const int)>> functionVector; //= {Foo, Bar};

    functionVector.push_back([](int a)
    {
        std::cout<<"The anonymous function was called - "<<a<<std::endl;
    });

    doWork(myVector, functionVector);

    return 0;
}


