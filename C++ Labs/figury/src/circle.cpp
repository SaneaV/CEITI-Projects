#include "circle.h"
#include <iostream>
using namespace std;
circle::circle( unsigned int tmp=1):figury("okrujnosti")
{

   r=tmp; //ctor
}
void circle::show()
{
    cout<<r;
}

