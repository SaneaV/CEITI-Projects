//Вывести на экран:
//11111
//2222
//333
//44
//5

#include <iostream>

using namespace std;

main()
{
    setlocale(0,"Rus");
    int n=1;

for (int i=n;i<=5;i++){
    for (int j=5;j>=i;j--)
        cout<<i;
        cout<<endl;}
}

