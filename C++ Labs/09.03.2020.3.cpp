#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int BankProfit[4][6];

bool isNice(int i)
{
        for(int j=0;j<6;j++)
        {
            if(BankProfit[i][0]<0) return false;

            if(BankProfit[i][j]<BankProfit[i][j-1] and j!=0) return false;
        }
    return true;
}

int main()
{
    int n;
    int k = 0;

    ifstream f("BN.in.txt");
    ofstream g("BN.out.txt");

    f>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<6;j++)
            {
                f>>BankProfit[i][j];
            }

        if(isNice(i)) k++;
    }



    g<<k;

    g.close();
    f.close();

}
