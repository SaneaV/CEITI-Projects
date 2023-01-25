#include<iostream>
using namespace std;
float Max(float a, float b )
{
    return (a>b)? a: b;
}
int main()
{
    setlocale(0,"");
    int n,m;
    float C[50][50], A[50][50];
    cout<<"n=";
    cin>>n;
    cout<<"m=";
    cin>>m;
    cout<<"Введите элементы массива A"<<endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>A[i][j];

    C[0][0]=A[0][0];
    for(int i=1; i<n; i++)
        C[i][0]=A[i][0]+C[i-1][0];
    for(int j=1; j<m; j++)
        C[0][j]=A[0][j]+C[0][j-1];
    for (int k=1; k<n+m-1; k++)
        for(int i=1; i<n; i++)
            for(int j=1; j<m; j++)
                if (i+j-1==k)
                    C[i][j]=A[i][j]+Max(C[i][j-1], C[i-1][j]);

                        cout<<endl<<endl;
    cout<<"Cmax="<< C[n-1][m-1];

    cout<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }

}
