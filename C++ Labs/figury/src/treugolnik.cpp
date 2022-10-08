#include "treugolnik.h"
#include <iostream>
using namespace std;
treugolnik::treugolnik(int a1,int b1,int c1):suglamy(3)
{

   a=a1;
   b=b1;
   c=c1; //ctor
}
void treugolnik::show()
{
    cout<<a;
    cout<<b;
    cout<<c;
}

