#include <iostream>
#include <cmath>

using namespace std;

void FillTemp(int **Matrix, int **&Temp, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            Temp[i][j] = Matrix[i][j];
        }
    }

}

void ShowMatrix(int **Temp, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<Temp[i][j]<<" ";
        cout<<endl;
    }
}

void SwapColumn(int **&Temp, int **B, int i, int n)
{
    while(n>=0)
    {
        Temp[n][i] = B[n][0];
        n--;
    }
}

double determ(int** Temp, int n)
{
    int i,j;
    double det=0;
    int** matr;
    if(n==1)
    {
        det=Temp[0][0];
    }
    else if(n==2)
    {
        det=Temp[0][0]*Temp[1][1]-Temp[0][1]*Temp[1][0];
    }
    else
    {
        matr=new int*[n-1];
        for(i=0; i<n; ++i)
        {
            for(j=0; j<n-1; ++j)
            {
                if(j<i)
                    matr[j]=Temp[j];
                else
                    matr[j]=Temp[j+1];
            }
            det+=pow((double)-1, (i+j))*determ(matr, n-1)*Temp[i][n-1];
        }
        delete[] matr;
    }
    return det;
}


int main()
{
    setlocale(LC_ALL,"RUS");

    int n;
    int m;

    cout<<"Введите количество уравнений: ";
    cin>>n;

    m = n+1;

    int **Matrix = new int*[n];
    for(int i=0; i<m; i++)
        Matrix[i] = new int[m];

    int **Temp = new int*[n];
    for(int i=0; i<n; i++)
        Temp[i] = new int[n];

    int **B = new int*[0];
    for(int i=0; i<n; i++)
        B[i] = new int[n];

    int *Det = new int[n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            if(n+1==j+1)
            {
                cout<<"Matrix["<<i<<"]["<<j<<"]: ";
                cin>>B[i][0];
            }
            else
            {
                cout<<"Matrix["<<i<<"]["<<j<<"]: ";
                cin>>Matrix[i][j];
            }
        }
    }

    cout<<"\n";
    FillTemp(Matrix, Temp, n);
    ShowMatrix(Temp, n);
    cout<<"\n\n";

    for(int i=0; i<n; i++)
    {
        SwapColumn(Temp, B, i, n-1);
        ShowMatrix(Temp, n);
        Det[i] = determ(Temp, n);
        FillTemp(Matrix, Temp, n);
        cout<<"Детерминант: "<<Det[i]<<"\n\n";
    }

    int mainDet = determ(Matrix, n);

    for(int i=0; i<n; i++)
    {
        cout<<"X"<<i+1<<" = "<<(float)Det[i]/mainDet<<endl;
    }

    delete Matrix;
    delete Temp;
    delete B;
    delete Det;
}
