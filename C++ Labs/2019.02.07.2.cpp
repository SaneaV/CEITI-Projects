#include <iostream>

using namespace std;

class Matrix
{
private:
    int n;
    int M[20][20];

public:
    void Create(int);
    void Show(int);

    Matrix(){}
    ~Matrix(){}
};

void Matrix::Create(int r)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<r; j++)
        {
            cout<<"¬ведите число: ";
            cin>>M[i][j];
        }
    }
}

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

    Matrix M;
    M.Create(r);
    cout<<endl;
    M.Show(r);
}

