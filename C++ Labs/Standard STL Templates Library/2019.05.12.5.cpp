#include <iostream>

using namespace std;

int main()
{
    char *string = "Hello!";
    cout<<string<<endl<<endl;

    char *arrString[] = {"Hello", "How are you?", "My name is Alex"};

    for(int i=0;i<3;i++)
        cout<<arrString[i]<<endl;
}
