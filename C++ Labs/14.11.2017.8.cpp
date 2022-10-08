//Найти сумму S+=n/(n+1.0);

#include <iostream>

using namespace std;

main()
{
    setlocale(0,"Rus");
    float n, S=0;
    cout<<"Введите n: ";
    cin>>n;
    for (int i=0;i<=n;i++);
    {
        S+=n/(n+1.0);
    }cout<<S;
}
