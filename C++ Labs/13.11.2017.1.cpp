//¬водитс€ число N.
//S=sqrt(n)*sqrt(n)...n*sqrt(n);

#include <iostream>
#include <cmath>

using namespace std;

main ()
{
    setlocale (LC_ALL,"Rus");
    cout<<"¬ведите число";
    int n;
    int S=1,p=1;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        p*=sqrt(n);
        S+=p;
    }
    cout<<S;
}
