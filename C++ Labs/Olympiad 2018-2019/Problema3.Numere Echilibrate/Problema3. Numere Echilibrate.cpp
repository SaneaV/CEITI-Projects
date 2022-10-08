#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    cout<<"Stop input \"x\""<<endl;

    int M[20];
    int i=0;
    bool Stop = false;
    int n=0;

    while(!Stop)
    {
        if(i>18)
        {
            Stop=true;
        }
        if(_kbhit)
        {
            switch(getch())
            {
            case '1':
            {
                M[i]=1;
                cout<<M[i];
                i++;
                break;
            }
            case '2':
            {
                M[i]=2;
                cout<<M[i];
                i++;
                break;
            }
            case '3':
            {
                M[i]=3;
                cout<<M[i];
                i++;
                break;
            }
            case '4':
            {
                M[i]=4;
                cout<<M[i];
                i++;
                break;
            }
            case '5':
            {
                M[i]=5;
                cout<<M[i];
                i++;
                break;
            }
            case '6':
            {
                M[i]=6;
                cout<<M[i];
                i++;
                break;
            }
            case '7':
            {
                M[i]=7;
                cout<<M[i];
                i++;
                break;
            }
            case '8':
            {
                M[i]=8;
                cout<<M[i];
                i++;
                break;
            }
            case '9':
            {
                M[i]=9;
                cout<<M[i];
                i++;
                break;
            }
            case '0':
            {
                M[i]=0;
                cout<<M[i];
                i++;
                break;
            }
            case 'x':
            {
                Stop=true;
                break;
            }

            }
        }
    }
    n=i;

    int S1=0;
    int S2=0;
    bool Posible = false;

    while(!Posible)
    {
        S1=0;
        S2=0;

        M[n-1]++;

        for(int j=0; j<n; j++)
        {
            if(M[j]==10)
            {
                M[j]=0;
                M[j-1]++;
                j--;
            }
            if(M[0]==10)
            {
                n+=1;
                M[n-1]=0;
                M[0]=1;
                for(int j=n-1;j>=n;j--)
                {
                    if(j!=0)
                    {
                        M[j]=M[j-1];
                    }
                }
            }

        }

        for(int j=0; j<n; j++)
        {
            if(j%2==0)
                S1+=M[j];
            else
                S2+=M[j];
        }

        if(S1==S2)
            Posible=true;
    }


    system("cls");
    cout<<"Your number: ";
    for(int j=0; j<n; j++)
    {
        cout<<M[j];
    }

}
