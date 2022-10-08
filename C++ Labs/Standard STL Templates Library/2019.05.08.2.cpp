#include <iostream>
#define FOO(x,y)((x)*(y))

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    cout<<FOO(5,6);

    return 0;
}
