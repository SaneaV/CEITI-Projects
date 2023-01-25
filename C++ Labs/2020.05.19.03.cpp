#include <iostream>
#include <fstream>

using namespace std;

int **A;

int FF(const int i)
{
    int Sum = 0;
    for(int j=0; j<12; j++)
        Sum+= A[i][j];
    return Sum;
}

int main()
{
    ifstream f("FS.in.txt");

    int n, minI = 0, localSum = 0, Sum = 0;

    f>>n;

    A = new int*[n];
    for(int i=0; i<n; i++)
    {
        A[i] = new int[12];
        for(int j=0; j<12; j++)
            f>>A[i][j];
    }

    f.close();

    for(int i=0; i<n; i++)
    {
        if(i==0)
            Sum = FF(i);
        else
        {
            localSum = FF(i);
            if(localSum<Sum)
            {
                Sum = localSum;
                minI = i;

            }
        }
    }

    ofstream g("FS.out.txt");
    g<<++minI;
    g.close();

}
