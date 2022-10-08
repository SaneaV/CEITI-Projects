#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Test
{
private:
    int arr[5]{5,4,9,8,3};

public:

    int &operator [](int index)
    {
        return arr[index];
    }

};

int main()
{
    Test A;

    cout<<A[0]<<endl;
    cout<<A[1]<<endl;
    cout<<A[2]<<endl;
    cout<<A[3]<<endl;
    cout<<A[4]<<endl;

    return 0;
}
