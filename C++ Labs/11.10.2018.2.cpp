//Рассмотрим множество P = {P1, P2, …, Pn}, образованное n точками (3 <= n <=30) на евклидовой плоскости.
//Каждая точка Pj определена своими координатами xj, yj. Напишите программу, которая находит такие три точки из множества P,
//для которых площадь соответствующего треугольника максимальна. Оцените время выполнения написанной программы.

#include<iostream>
#include<cmath>
using namespace std;

struct point
{
    float x,y;
} p[30],PA,PB,PC;

float cmax;

float Distance(point A, point B)
{
    return sqrt(pow((A.x-B.x),2)+pow((A.y-B.y),2));
}

bool PossibleSolution (int j, int m, int k)
{
    if (j!=m and j!=k and k!=m) return true;
    else  return false;
}

float Aria(point A, point B, point C)
{
   float a=Distance(A,B);
   float b=Distance(B,C);
   float c=Distance(A,C);

   float pr=0.5*(a+b+c);

   float S=sqrt(pr*(pr-a)*(pr-b)*(pr-c));

   return S;
}

void ProcessingSolution(point A, point B, point C)
{
    if (Aria(A, B, C)>cmax)
    {
        PA=A;
        PB=B;
        PC=C;
        cmax=Aria(A, B, C);
    }
}



int main()
{
    int n;
    setlocale(0,"");
    cout<<"n=";
    cin>>n;
    cout<<"Введите координаты x, y точек";
    for(int j = 0; j<n; j++)
    {
        cout<<"P["<< j<< "]: ";
        cin>> p[j].x>>p[j].y;
    }
    for(int j= 0; j<n; j++)
        for(int m= 0; m<n; m++)
        for(int k= 0; k<n; k++)
            if (PossibleSolution(j, m, k))
                ProcessingSolution(p[j], p[m], p[k]);
     cout<<"Решение: PA=("<< PA.x<< ","<< PA.y<< ")";
     cout<<" PB=("<< PB.x<< ","<< PB.y<<")";
     cout<<" PC=("<< PC.x<< ","<< PC.y<<")";
}

