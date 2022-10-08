//Рекурсия. Матрица. Позиция минимального элемента по модулю

#include <iostream>
#include <cmath>

using namespace std;

void Array(float *z, int &m)
{
    float e=z[0];
    int p=0;
    for(int i=1;i<m;i++)
    {
        if (fabs(z[i])<e) {e=z[i];p=i;}
    }
    cout<<p;
}


int main()
{
    setlocale(0,"");

    int n;
    cout<<"n=";
    cin>>n;

    float x[50];

    for (int i=0;i<n;i++)
    {
        cin>>x[i];
    }

    cout<<"Позиция минимального элемента по модулю: ";
    Array(x,n);
}

