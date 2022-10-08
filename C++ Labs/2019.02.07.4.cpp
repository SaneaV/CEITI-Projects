#include <iostream>

using namespace std;

class Matrix
{
private:
    int n;
    int A[10][10];
public:
    void Show();

    Matrix(int, int);
};

Matrix::Matrix(int n=2, int x=0)
{
    this->n = n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            A[i][j]=x;
        }
    }
}

void Matrix::Show()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    setlocale(LC_ALL,"RUS");

    Matrix M;
    M.Show();

    cout<<endl;
    Matrix F(4,98);
    F.Show();
}
