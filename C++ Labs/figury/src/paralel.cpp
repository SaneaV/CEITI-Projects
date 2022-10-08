#include "paralel.h"
#include <iostream>
using namespace std;
paralel::paralel(int a1,int b1,int u1):suglamy(4)
{
  //  figury("parall");

   a=a1;
    b=b1;
    u=u1;//ctor
}
void paralel::show()
{
    cout<<a;
    cout<<b;
    cout<<u;
}

