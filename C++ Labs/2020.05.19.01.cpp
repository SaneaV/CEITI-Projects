#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int ppVerefication(int N)
{
    int Sum = 0;


    if(N>99 and N<1000)
        for(int i=0; i<3; i++)
        {
            Sum += (N%10);
            N /=10;
        }

    if(N>999 and N<10000)
        for(int i=0; i<3; i++)
        {
            Sum += (N%10);
            N /=10;
        }

}

int main()
{

    int PUK;
    int PIN;

    ifstream f("CODE.IN.txt");
    ofstream g("CODE.OUT.txt");

    f>>PUK>>PIN;

    if(ppVerefication(PUK)%ppVerefication(PIN)==0)
        g<<"Acceptat";
    else
        g<<"Respins";
}
