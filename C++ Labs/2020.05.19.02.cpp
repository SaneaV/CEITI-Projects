#include <iostream>
#include <fstream>

using namespace std;

int maxA(int **A,int &maxQuantity, const int n, const int m)
{
    int maxI = A[0][0];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(A[i][j]>maxI)
            {
                maxI = A[i][j];
                maxQuantity=0;
            }

            if(A[i][j]==maxI)
            {
                maxQuantity++;
            }
        }

    return maxI;
}

int main()
{
    ifstream f("Taxi.in.txt");

    int n, m, maxQuantity = 0;
    f>>n>>m;

    int **A = new int*[n];
    for(int i=0; i<n; i++)
    {
        A[i] = new int[m];
        for(int j=0; j<m; j++)
            f>>A[i][j];
    }

    f.close();

    ofstream g("Taxi.out.txt");

    g<<maxA(A, maxQuantity, n, m)<<" ";
    g<<maxQuantity;
    g.close();
}
