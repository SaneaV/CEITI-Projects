//k=cos(x)*cos(cos(x))....n*cos(x);

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");
    float n,x,i=0,k=0;
    cin>>n>>x;
    while (i<n)
    {
        n*=cos(x);
        k+=n;
        i++;
    }cout<<k;
}
