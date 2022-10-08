#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;

int main()
{
////////////////////////////////////////////////////////
    int n = 7;
    char Word[2][7];
    bool Stop = false;

////////////////////////////////////////////////////////
    Word[0][0] = 'L';
    Word[0][1] = 'o';
    Word[0][2] = 'a';
    Word[0][3] = 'd';
    Word[0][4] = 'i';
    Word[0][5] = 'n';
    Word[0][6] = 'g';

    for(int i=0; i<n; i++)
    {
        Word[1][i] = ' ';
    }
////////////////////////////////////////////////////////
    while(!Stop)
    {
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (i==0)
                {
                    Word[i+1][j] = Word[i][j];
                    Word[i][j] = ' ';
                }
                else if (i==1)
                {
                    Word[i-1][j] = Word[i][j];
                    Word[i][j] = ' ';
                }

                for(int p=0; p<2; p++)
                {
                    for(int q=0; q<n; q++)
                    {
                        if (q==0)
                            cout<<setw(25)<<Word[p][q];
                        else
                            cout<<Word[p][q];
                    }
                    cout<<endl;
                }
                Sleep(500);
                system("cls");
            }
        }
        Stop = true;
    }
}
