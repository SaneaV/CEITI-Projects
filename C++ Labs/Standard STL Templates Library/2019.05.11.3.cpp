#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int *pa = new int;
    *pa = 10;
    cout<<*pa<<endl;
    delete pa;
    pa = nullptr;
    cout<<pa<<endl;

    return 0;
}
