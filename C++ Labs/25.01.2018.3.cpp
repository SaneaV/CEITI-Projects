//Сортировка подсчёта №2
//Все элементы больше либо равно нулю

#include <iostream>

using namespace std;

main()
{
    cout<<"Vvedite chislo: ";
    int n;
    cin>>n;

    int b[100];
    int a[100];

    for (int i=0;i<n;i++)
    {
        cout<<"Vvvedite chislo: ";
        cin>>a[i];
    }


    for (int i=0;i<n;i++)
    {
        b[i]=-1;//Tak kak vse elimenti bolishe libo ravno nuliu
    }

    for (int i=0;i<n;i++)
    {
        int k=0,t=0;
        for (int j=0;j<n;j++)
        {
            if (a[i]>a[j]) k++;
            if (a[i]==a[j]) t++;
        }
        t--;
        if (b[k]==-1)
        {
            for (int j=k;j<=k+t;j++)
            {
                b[j]=a[i];
            }
        }
    }




    for (int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
}
