#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <algorithm>

typedef std::vector<int> int_vector;
typedef std::vector<float> float_vector;

using std::cout;
using std::endl;


struct randNumber
{
    int operator()()
    {
        return (rand()%10);
    }
};

template <typename T>
void printVector(const std::vector<T> &V)
{
    for(auto i: V)
            cout<<i<<" ";
    cout<<endl;
}

int main()
{
    setlocale(LC_ALL,"RUS");
    srand(time(0));

    /**----------------------------------------------------------------------*/
    int_vector mySecondVector(10);

    generate(mySecondVector.begin(), mySecondVector.end(), randNumber());

    printVector(mySecondVector);

    /**----------------------------------------------------------------------*/
    float_vector myFloatVector;

    for(int i=0;i<10;i++)
        myFloatVector.push_back(i/2.0);

    printVector(myFloatVector);
    /**----------------------------------------------------------------------*/


    return 0;
}
