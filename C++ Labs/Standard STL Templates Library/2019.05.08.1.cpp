#include <iostream>

#define Pi 3.14
#define tab "\t"
#define begin {
#define end }

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    cout<<Pi<<endl;

    cout<<tab"cout"tab<<endl;

    cout<<endl<<endl;

    for(int i=0; i<5; i++)
        begin
        if(i!=0 and i!=1)
            cout<<tab;
    cout<<i;
    if(i==0)
        cout<<tab;
    end

    return 0;
}
