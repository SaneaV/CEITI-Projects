#include <iostream>
#include <memory>

int main()
{
    std::auto_ptr<int> aP1(new int(5));
    std::auto_ptr<int> aP2(aP1);

    std::unique_ptr<int> uP1(new int(5));
    std::unique_ptr<int> uP2;
    uP2 = std::move(uP1);


    std::shared_ptr<int> sP1(new int (5));
    std::shared_ptr<int> sP2(sP1);


    return 0;
}
