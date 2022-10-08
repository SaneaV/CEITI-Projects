#include <iostream>
#include "figury.h"
#include "circle.h"
#include "suglamy.h"
#include "treugolnik.h"
#include "paralel.h"
#include "preamoug.h"
#include "romb.h"

using namespace std;

int main()
{
    cout<<"Okrujnosti:";
    circle c(5);
    c.show();
    cout<<endl<<"Romb:";
    romb rm(4,90);
    rm.show();

    return 0;
}
