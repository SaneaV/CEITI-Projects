#include <iostream>

using namespace std;

int main()
{
    for(int i=1; i<=10; i++)
        if(i%2==0)
            continue;
        else if (i==7)
            break;
        else
            cout<<"Iteration number - "<<i<<endl;


    return 0;
}
