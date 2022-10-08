#include <iostream>

using std::cout;
using std::endl;

namespace test1
{

int a = 10;

void Start()
{
    std::cout<<"Test 1"<<std::endl;
}

}

namespace test2
{
int b = 14;

void Start()
{
    std::cout<<"Test 2"<<std::endl;
}
}

namespace Secur
{
namespace test2
{
void Start()
{
    std::cout<<"Test 3"<<std::endl;
}
}
}

int main()
{
    setlocale(LC_ALL, "rus");

    test1::Start();
    std::cout<<std::endl;
    test2::Start();
    std::cout<<std::endl;
    Secur::test2::Start();
    std::cout<<std::endl;
    std::cout<<test1::a<<std::endl;
    std::cout<<test2::b<<std::endl;
    std::cout<<std::endl;
    std::cout<<test1::a<<" + "<<test2::b<<" = "<<test1::a+test2::b<<std::endl;

    return 0;
}
