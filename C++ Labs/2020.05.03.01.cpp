#include <iostream>
#include <fstream>

using namespace std;

int n, k;
ifstream f("fe.in.txt");

int FV (int index)
{
    int t = 0;
    int x = 0;
    for(int i=0; i<k; i++)
    {
        f>>x;
        if(x==3)
            t++;
    }
    return t;
}

int main()
{
    f>>n>>k;

    int *Array = new int [n];
    int max = 0;
    int maxIndex =0;
    int noWin = 0;

    for(int i=0; i<n; i++)
    {
        Array[i] = FV(i);
        if(Array[i] > max)
        {
            max = Array[i];
            maxIndex = i+1;
        }
        if(Array[i] == 0)
            noWin++;
    }
    f.close();
    ofstream f("fe.out.txt");
    f<<maxIndex<<" "<<noWin;
    f.close();
}
