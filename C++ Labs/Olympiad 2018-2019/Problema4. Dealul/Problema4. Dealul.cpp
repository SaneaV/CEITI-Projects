#include <iostream>
#include <fstream>
#include <limits.h>
#include <windows.h>

using namespace std;



int main()
{
    ifstream f("deal.in.txt");

    int n;
    f>>n;
    int *H = new int [n];

    for(int i=0; i<n; i++)
    {
        f>>H[i];
    }
    f.close();

    bool POSSIBLE = true;

    int SMAX = 0;

    while(POSSIBLE)
    {
        int NUL = 0;
        int max = 0;
        int min = INT_MAX;
        int pozMAX = 0;
        int pozMIN = 0;

        for(int i=0; i<n; i++)
        {
            if(H[i]>max)
            {
                max = H[i];
                pozMAX=i;
            }
            if(H[i]<min and H[i]!=0)
            {
                min = H[i];
                pozMIN=i;
            }

            if(H[i]==0) NUL++;

        }

        if(NUL==n or NUL==n-1) POSSIBLE = false;
        else if(min!=0 and max!=0 and max!=min)
        {
            H[pozMAX]=0;
            H[pozMIN]=0;
            SMAX+=max;
        }

    }

    ofstream g("deal.out.txt");
    g<<SMAX;
    g.close();

}
