#include <iostream>
#include <fstream>

using namespace std;

int M[10][10];
int n, m;

void Read()
{
    ifstream f("Matrix2.txt");

    f>>n;
    f>>m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            f>>M[i][j];
        }
    }
    f.close();
}

void Show()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
}

void LockingFor()
{
    int max = 0;
    int Sum = 0;
    int poz1, poz2, poz3, poz4;
    int xpoz1, xpoz2, xpoz3, xpoz4;
    int Last1, Last2;

    for(int i=0; i<n; i++)
    {
        Sum=0;
        for(int j=0; j<m; j++)
        {
            for(int p=i; p<n; p++)
            {
                for(i nt q=j; q<m; q++)
                {
                    poz1=M[i][j];
                    poz2=M[n-1][j];
                    poz3=M[p][q];
                    poz4=M[n-1][q];
                    Sum+=poz1+poz2+poz3+poz4;
                    if(Sum>=max)
                    {
                        xpoz1=poz1;
                        xpoz2=poz2;
                        xpoz3=poz3;
                        xpoz4=poz4;
                    }
                }
            }
        }
    }

    cout<<"Самый лучший вариант: "<<endl;
    cout<<xpoz1<<endl;
    cout<<xpoz2<<endl;
    cout<<xpoz3<<endl;
    cout<<xpoz4<<endl;
}

int main()
{
    setlocale(LC_ALL,"RUS");

    Read();
    Show();
    LockingFor();


}

