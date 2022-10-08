/*В копилке находится N монет различных достоинств общим весом G граммов. Вес каждой монеты определенной стоимости дан в таблице, приведенной ниже.

Стоимость монеты, лей	Вес монеты, грамм
1	1
5	2
10	3
25	4
50	5
Напишите программу, которая определит минимальную сумму S, которая может находиться в копилке. */

#include <iostream>
#include <windows.h>

using namespace std;

int nominal[5]= {1,5,10,25,50};
int weight[5]= {1,2,3,4,5};
int mn[5];
int cnt[5];
int N,G;
int Smin;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

bool PosibSol(int *c)
{
    int V=0, k=0;

    for(int i=0; i<5; i++)
    {
        V+=c[i]*weight[i];
        k+=c[i];
    }
    if(k==N and V==G)
        return true;
    else
        return false;
}

void ProcesSol(int *c)
{
    int s=0;
    for(int i=0; i<5; i++)
        s+=nominal[i]*c[i];
    if(s<Smin)
    {
        Smin=s;
        for(int i=0; i<5; i++)
            mn[i]=c[i];
    }
}

int main()
{
    cin>>N>>G;

    Smin=N*50;

    for(int i1=0; i1<=N; i1++)
        for(int i2=0; i2<=N; i2++)
            for(int i3=0; i3<=N; i3++)
                for(int i4=0; i4<=N; i4++)
                    for(int i5=0; i5<=N; i5++)
                    {
                        cnt[0]=i1;
                        cnt[1]=i2;
                        cnt[2]=i3;
                        cnt[3]=i4;
                        cnt[4]=i5;

                        SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGreen));
                        cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<" "<<cnt[4]<<endl;

                        if(PosibSol(cnt))
                            ProcesSol(cnt);
                    }
    for(int i=0; i<5; i++)
        cout<<nominal[i]<<"=>"<<mn[i]<<endl;
}

