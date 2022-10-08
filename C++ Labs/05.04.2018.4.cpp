//»спользу€ рекурсивную функцию, получить треугольник ѕифагора
#include <iostream>

using namespace std;

int C(int k, int n)
{
    if (k==0)
        return 1;
    else
        return C(k-1, n)*(n-k+1)/k;
}

main()
{
    setlocale(LC_ALL,"RUS");
    int m;
    cin>>m;
    for(int j=0; j<=m; j++)
    {
        for(int i=0; i<=j; i++)
            cout<<C(i,j)<<" ";
        cout<<endl;
    }
}
