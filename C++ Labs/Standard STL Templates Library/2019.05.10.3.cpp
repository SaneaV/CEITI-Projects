#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
    srand(time(NULL));
    vector<int> MyVector;

    for(int i=0; i<10; i++)
    {
        MyVector.push_back(-10 + rand()% 20);
    }

    for(auto i : MyVector)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}
