//Ввести n.
//От 1 до n
//S+=1*1.0/2.0*n

#include <iostream>

using namespace std;

main()
{
    setlocale (0,"Rus");
    cout<<"Введите n: ";
    float n,S=0;
    cin>>n;
    for (int i=1; i<=n;i++)
    {
        S+=1*1.0/2.0*n;
    }cout<<S;
}
