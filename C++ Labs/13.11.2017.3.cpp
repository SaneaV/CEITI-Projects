//Вывести на экран:
//    *
//   **
//  ***
// ****
//*****

#include <iostream>
#include <iomanip>

using namespace std;

main()
{
    setlocale(0,"Rus");
    int n=5;
    for (int i=1; i<=n; i++)
    {
         for (int j=n; j>i; j--)
            cout<<" ";
        for (int j=0; j<i; j++)
            cout<<"*";

        cout<<endl;

    }
}
