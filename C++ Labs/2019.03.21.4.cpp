#include <iostream>
#include <process.h>

using namespace std;

const int LIMIT = 10;

template <class TYPE> class safearray
{
private:
    TYPE arr[LIMIT];
public:
    TYPE &operator[](int n)
    {
        if(n<0 || n>=LIMIT)
        {
            cout<<"\nќшибочный индекс!"<<endl;
        }
        return arr[n];
    }
};

int main()
{
    setlocale(LC_ALL,"RUS");

    safearray<int> sa1;
    safearray<char> sa2;
    safearray<float> sa3;

    for(int j=0; j<LIMIT; j++)
        sa1[j]=j*10;

    char ch;
    cout<<"¬ведите символ: ";
    cin>>ch;

    for(int j=0; j<LIMIT; j++)
        sa2[j]=ch+j;

    for(int j=0; j<LIMIT; j++)
        sa3[j]=j*10.5;

    for(int j=0; j<LIMIT; j++)
    {
        int temp = sa1[j];
        cout<<"Ёлемент "<<j<<" равен "<<temp<<endl;
    }

    cout<<endl<<endl;

    for(int j=0; j<LIMIT; j++)
    {
        char temp = sa2[j];
        cout<<"Ёлемент "<<j<<" равен "<<temp<<endl;
    }
    cout<<endl<<endl;

    for(int j=0; j<LIMIT; j++)
    {
        float temp = sa3[j] *1.0;
        cout<<"Ёлемент "<<j<<" равен "<<temp<<endl;
    }

    return 0;
}
