//Дан текстовый файл натуральных чисел, за которыми следует целое отрицательное число.
//Используя рекурсивную подпрограмму, вычилите сумму чисел файла.


#include <iostream>
#include <fstream>

using namespace std;

int Sum(int A[],int x)
{
    if (x==0)
        return 0;
    else
        return Sum(A,x-1)+A[x-1];
}

int main()
{
    setlocale(LC_ALL,"RUS");

    ofstream f("File.txt");

    cout<<"Последнее, отрицательное число вводится пользователем."<<endl;
    cout<<"Введите количество чисел: ";
    int n;
    cin>>n;

    int y;

    for(int i=0; i<n; i++)
    {
            cout<<"Введите число: ";
            cin>>y;
            f<<y<<" ";
    }

    f.close();

    ifstream g("File.txt");

    int Array[250];

    int j=0;

    while(!g.eof())
    {
        g>>y;
        Array[j]=y;
        j++;

    }

    g.close();

    int t=0;
    for (int i=0; i<n; i++)
    {
        t=Array[0];
        if (i==n-1)
        {
            Array[0]=Array[n];
            Array[n]=t;
        }
    }

    cout<<endl<<Sum(Array,n)<<endl;
}
