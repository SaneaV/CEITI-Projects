#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    for(int i=0;i<256;i++)
    {
        cout<<"Code - "<<i<<"\t"<<(char)i<<endl;
    }
}
