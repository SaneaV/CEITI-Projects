#include <iostream>

using namespace std;

template <typename TYPE> TYPE amax(TYPE *M, int n)
{
    TYPE a=0;

    for(int i=0;i<n;i++)
    {
        if(a<M[i]) a=M[i];
    }

    return a;
}

int main()
{
    setlocale(LC_ALL,"RUS");

    int n;

    int intMassive[10];
    float floatMassive[10];
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
        cout<<"Элемент float: ";
        cin>>floatMassive[i];
    }

    for(int i=0; i<n; i++)
    {
        cout<<"Элемент char: ";
        cin>>charMassive[i];
    }

    cout<<"Максимальный элемент в int: "<<amax(intMassive, n)<<endl;
    cout<<"Максимальный элемент в float: "<<amax(floatMassive, n)<<endl;
    cout<<"Максимальный элемент в char: "<<amax(charMassive, n)<<endl;



    return 0;
}
