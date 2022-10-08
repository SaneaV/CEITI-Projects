#include <iostream>
#include <stdlib.h>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    srand(time(NULL));

    int a = rand()%10;
    cout<<"Random number is: "<<a<<endl;
    cout<<a<<">5 - ";

    a>5? cout<<"It is true!"<<endl:
        1<a? cout<<"It is false!"<<endl<<"1<"<<a<<" - It is true!"<<endl:
             cout<<"It is false!"<<endl<<"1<"<<a<<" - It is false!"<<endl;

    return 0;
}
