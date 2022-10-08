#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>

template <typename T>
void filling_Vector(std::vector<T> &V, int n)
{
    if(n==0) return;
    else filling_Vector(V, --n);
    V.push_back(rand()%10);
}

template <typename T>
void print_Vector(const std::vector<T> &V, int n)
{
    if(n==0) return;
    else print_Vector(V, --n);
    std::cout<<V[n]<<" ";
}

template <typename T>
void print_Vector(const std::vector<T> &V)
{
    for(auto i:V)
        std::cout<<i<<" ";
    std::cout<<std::endl;
}

int main()
{
    srand(time(NULL));

    std::vector<int> MyVector;

    filling_Vector(MyVector, 10);
    print_Vector(MyVector, MyVector.size());
    std::cout<<std::endl;
    print_Vector(MyVector);
    return 0;
}
