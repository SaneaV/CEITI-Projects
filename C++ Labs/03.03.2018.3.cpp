//Создать динамическую матрицу. Поменять местами строки.

#include <iostream>
#include <fstream>

using namespace std;

main()
{
    setlocale(LC_ALL,"RUS");

    ifstream f("file1.txt");
    int n;
    f>>n;

    int **A=new int *[n];
    for (int i=0; i<n; i++)
        A[i]=new int [n];

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            f>>A[i][j];

    int q=n/2;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }


    for (int j=0; j<n; j++)
    {
        for (int i=0; i<q; i++)
        {

            int c=A[i][j];
            A[i][j]=A[i+q][j];
            A[i+q][j]=c;

        }
    }




    cout<<endl<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }


}

