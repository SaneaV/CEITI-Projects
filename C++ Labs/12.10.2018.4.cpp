//Дано четырёхзначное число, разбить его на цифры.

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;
    int *A=new int [5];
    int i=0;

    cout<<"Введите число: ";
    do
    {
        cin>>n;
    }while(n>=10000 or n<1000);

    cout<<endl<<endl;

    while(n)
    {
        A[i]=n%10;
        n/=10;
        i++;
    }

    for(int i=3;i>=0;i--)
    {
        cout<<A[i]<<" ";
    }

    delete(A);
}
