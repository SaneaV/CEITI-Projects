//„исла ‘ибоначчи определ€ютс€ рекуррентной формулой:

//f0 = 0; f1 = 1; fn = fn-1 + fn-2;

#include <iostream>

using namespace std;

main()
{
    setlocale (0,"Rus");
    cout<<"¬ведите k: ";
    int a=0,b=1,k;
    cin>>k;
    for (;k!=0;)
    {
        a=a+b;
        b=a-b;
        k=k-1;
        cout<<a<<" ";;
    }

}
