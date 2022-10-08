//Вывести на экран:
//54321
//5432
//543
//54
//5

#include <iostream>
#include <iomanip>

using namespace std;

main()
{
    setlocale(0,"Rus");
    int n=5;

for (int i=1;i<=n;i++){
    for (int j=5;j>=i;j--)
        cout<<j;
        cout<<endl;}

}
