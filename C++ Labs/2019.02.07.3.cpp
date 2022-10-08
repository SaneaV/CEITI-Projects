#include <iostream>

using namespace std;

class Matrix
{
private:
    int n;
    int M[20][20];

public:

    Matrix(int n, int x)
    {
        this->n = n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            M[i][j]=x;
    }
    Matrix(const Matrix& mrtx, int a, int b)
    {
        n = mrtx.n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            M[i][j] = mrtx.M[i][j]*a+b;
    }

    void Show(int);
};


void Matrix::Show(int r)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<r; j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");

    int r;

    cout<<"¬ведите количество: ";
    cin>>r;

    Matrix M(r, 5);

    cout<<endl;
    M.Show(r);

    cout<<endl;
    Matrix B(M, 3, 4);
    B.Show(r);
}

