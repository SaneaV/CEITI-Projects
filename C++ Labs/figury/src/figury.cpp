#include "figury.h"
#include <iostream>
#include<string.h>
using namespace std;
figury::figury(char tmp[20])
{
    strcpy(nazvanie,tmp);
    //ctor
}
void figury::show()
{
    cout<<nazvanie;
}
