///Наибольший общий делитель методом перебора

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"RUS");

    int A[20];
    int n;

    cout<<"Введите количество чисел: ";
    cin>>n;
    cout<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<"Введите число: ";
        cin>>A[i];
    }

    int min=A[0];
    for(int i=0; i<n; i++)
        if(A[i]<min)
            min=A[i];

    int k=0;

    for(int i=0; k!=n ; i++)
    {
        if(A[i]%min==0)
            k++;

        if(k!=n and i+1==n)
        {
            k=0, i=-1;
            min--;
        }
    }
    cout<<"НОД - "<<min<<endl;
}
