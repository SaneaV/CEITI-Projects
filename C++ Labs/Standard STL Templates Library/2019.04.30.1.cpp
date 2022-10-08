#include <iostream>
#include <array>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    array<int, 4> arr = {2,3,0};
    array<int, 4> arr2 = {2,2,22};

    bool result = (arr>arr2);

    cout<<boolalpha<<result<<endl;
}
