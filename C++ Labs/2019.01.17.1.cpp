#include <iostream>
#include <fstream>

using namespace std;

int M[10][10];
int n;

void Read()
{
    ifstream f("Matrix.txt");

    f>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
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
        for(int j=0; j<n; j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
}

bool Check(int x, int y, int d)
{
    for(int i=x; i<x+d; i++)
    {
        for(int j=y; j<y+d; j++)
        {
            if(M[i][j]==0)
                return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL,"RUS");

    Read();
    //Show();

    for(int dl=n; dl>0; dl--)
    {
        for(int a=0; a<=dl; a++)
        {
            for(int b=0; b<=dl; b++)
            {
                if(Check(a,b,dl))
                {
                    cout<<a<<" "<<b<<" "<<endl;
                    a+=dl;
                    b+=dl;
                    dl=0;
                }
            }
        }
    }

}

