#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;
    int m;
    int max=0;
    int pmax=0;

    cout<<"Input number of members: ";
    cin>>n;
    cout<<"Input number of fix circles: ";
    cin>>m;

    int *M = new int [m];
    int *N = new int [n];

    for(int i=0;i<n;i++)
        M[i]=0;

    for(int i=0;i<n;i++)
        N[i]=0;

    for(int i=0; i<m; i++)
    {
        cout<<"Who was on position "<<i+1<<":";
        cin>>M[i];
    }

    for(int i=0; i<n; i++)
    {
        N[M[i]-1]++;

        /*for(int j=0;j<n;j++)
            cout<<N[j];
        cout<<endl;*/
    }

    for(int i=0; i<n; i++)
    {
        if(N[i]>max)
        {
            max=N[i];
            pmax=i;
            i=n;
            break;
        }
    }

    cout<<"Who drove first: "<<pmax+1<<endl;
}
