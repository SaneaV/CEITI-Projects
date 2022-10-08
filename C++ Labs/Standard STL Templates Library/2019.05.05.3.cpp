#include <iostream>

using namespace std;

void foo();
void foo2(int, int);

int main()
{
    foo();
    foo2(2, 3);
    return 0;
}

void foo()
{
    cout<<"Hi, I'm a function :)"<<endl;
}

void foo2(int a, int b)
{
    cout<<"Hi, I'm a function with parametrs :)"<<endl;
    cout<<"a + b = "<<a+b<<endl;
}
