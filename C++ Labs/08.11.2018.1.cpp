//Задача о рюкзаке.
//Один из способов решения.

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;
    int V;

    cout<<"Введите количество предметов: ";
    cin>>n;
    cout<<"Введит объём рюкзака: ";
    cin>>V;



    int C[50];
    int G[50];
    int F[25][25];
    int x[25][25];

    for(int i=1; i<=n; i++)
    {
        cout<<"Введите вес предмета: ";
        cin>>G[i];
        cout<<"Введите стоимость предмета: ";
        cin>>C[i];


    }

    int t=0;
    int Smax=0;
    int Tmax=0;

    for(int j=0; j<=V; j++)
         F[0][j]=0;


    for(int i=1; i<=n; i++)
        for(int j=0; j<=V; j++)
        {
            t=0;
            Smax=0;
            Tmax=0;

            while(t<=j/G[i])
            {
                int S = F[i-1][j-G[i]*t] + C[i]*t;
                if(S>Smax)
                {
                    Smax=S;
                    Tmax=t;
                }
                t++;

            }
            F[i][j]=Smax;
            x[i][j]=Tmax;
            cout<<F[i][j]<<" "<<x[i][j]<<endl;

        }



    cout<<F[n][V]<<endl;
}

