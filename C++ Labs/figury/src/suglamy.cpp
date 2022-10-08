#include "suglamy.h"
#include <iostream>
using namespace std;
suglamy::suglamy(int tmp):figury("s uglami")
{

    k_ugl=tmp;
    //ctor
}
void suglamy::show()
{
    cout<<k_ugl;
}


