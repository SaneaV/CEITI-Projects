#include <iostream>
#include <stdlib.h>
#include <ctime>

using std::cout;
using std::endl;

int factorial(int n)
{
    if(n==1)
    {
        cout<<"1";
        return 1;
    }
    cout<<n<<"*";
    return n*(factorial(n-1));
}

int main()
{
    srand(time(NULL));
    int randNumber = 3+rand()%7;
    cout<<"Random number: "<<randNumber<<"\n\n";
    cout<<"\n\nThe factorial is: "<<factorial(randNumber)<<"\n\n";

    return 0;
}
