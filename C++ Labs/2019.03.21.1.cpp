#include <iostream>
#include <windows.h>

using namespace std;

template <typename TYPE> TYPE avg(TYPE *x, int n)
{
    int S=0;
    for(int i=0; i<n; i++)
    {
        S+=x[i];
    }

    return S/n;
}

int main()
{
    setlocale(LC_ALL,"RUS");
    int n;

    int intMassive[10];
    long longMassive[10];
    double doubleMassive[10];
    char charMassive[10];

    cout<<"Введите количество элементов: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Элемент int: ";
        cin>>intMassive[i];
    }
    for(int i=0; i<n; i++)
    {
        cout<<"Элемент long: ";
        cin>>longMassive[i];
    }
    for(int i=0; i<n; i++)
    {
        cout<<"Элемен double: ";
        cin>>doubleMassive[i];
    }
    for(int i=0; i<n; i++)
    {
        cout<<"Элемент char: ";
        cin>>charMassive[i];
    }

    system("cls");

    cout<<"AVG int: "<<avg(intMassive,n)<<endl;
    cout<<"AVG long: "<<avg(longMassive,n)<<endl;
    cout<<"AVG double: "<<avg(doubleMassive,n)<<endl;
    cout<<"AVG char: "<<avg(charMassive,n)<<endl;




    return 0;
}
