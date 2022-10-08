#include <iostream>

using namespace std;

int main()
{
    int n;
    int Nm=0;
    bool Posible = true;
    int c;

    while(n>72 or n<3)
    {
        cout<<"Input n: ";
        cin>>n;
    }

    int *M = new int [n];

    for(int i=0; i<n; i++)
    {
        M[i]=1;
    }
    Nm++;

    while(Posible)
    {
        if(n==2)
            Posible = false;


        M[n-1]+=M[n-2];
        n--;

        for(int i=0; i<n; i++)
        {
            if(M[i]>3)
                Posible=false;
        }

        if(Posible)
        {
            Nm++;
            for(int i=n; i>0; i--)
            {
                c = M[i-1];
                M[i-1]=M[i];
                M[i]=c;
                Nm++;

            }
        }

    }

    cout<<endl<<Nm<<endl;

}
