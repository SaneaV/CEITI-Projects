#include "romb.h"
#include <iostream>
using namespace std;
romb::romb(int a1,int u1):paralel(a,a,u)
{


   a=a1;
   u=u1;//ctor
}
void romb::show()
{
    cout<<a;
    cout<<u;

}

