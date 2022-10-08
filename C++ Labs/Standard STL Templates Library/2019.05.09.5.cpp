#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int *pa = new int;
    *pa=3;
    cout<<"pa = "<<pa<<endl;
    cout<<"*pa = "<<*pa<<endl<<endl;
    delete pa;
    cout<<"pa = "<<pa<<endl;
    cout<<"*pa = "<<*pa<<endl<<endl;

    return 0;
}
